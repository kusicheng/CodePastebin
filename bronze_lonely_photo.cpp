#include <iostream>
#define ll long long
using namespace std;
char a[500000];
int main(){
    int n;
    char m;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    //for (auto x:a)cout<<x.first<<": "<<x.second<<endl;
    ll ans=0;
    for (int i=0;i<n;i++){
        int l=i-1,r=i+1;
        while (a[l]!=a[i]&&l>=0)l--;
        while (a[r]!=a[i]&&r<n)r++;
        r--;
        l++;
        //cout<<l<<" "<<r<<endl;
        if (r-l>=2)
            ans+=(r-i)*(i-l)+r+l-2*i;
    }
    cout<<ans<<endl;
}
