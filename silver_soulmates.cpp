#include <iostream>
#define ll long long
#define INT_MAX 2147483647
using namespace std;
int n,ans=INT_MAX;
ll a,b;
int bitcount(ll i){
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i + (i >> 4)) & 0x0f0f0f0f;
    i = i + (i >> 8);
    i = i + (i >> 16);
    return i & 0x3f;
}
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        for (int shifts=0;b>>shifts>0;shifts++){
            ll bnow=b>>shifts;
            int tempans=0;
            ll anow=a;
            while (anow>bnow){
                if (anow%2){
                    anow++;
                    tempans++;
                }
                anow/=2;
                tempans++;
            }
            tempans+=bnow-anow;
            tempans+=shifts;
            tempans+=bitcount(b&((1<<shifts)-1));
            if (tempans>=0)
                ans=min(ans,tempans);
        }
        cout<<ans<<endl;
        ans=INT_MAX;
    }
}
