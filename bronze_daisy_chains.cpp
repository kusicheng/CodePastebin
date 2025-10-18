#include <iostream>
using namespace std;
int a[100],n;
int check(int l){
    int av;
    int ans=0;
    for (int idx=0;idx<n-l;idx++){
        av=0;
        for (int i=idx;i<idx+l+1;i++)
            av+=a[i];
        if (av%(l+1)!=0)continue;
        av/=(l+1);
        for (int i=idx;i<idx+l+1;i++){
            if (a[i]==av){
                ans++;break;
            }
        }
    }
    return ans;
}
int main(){
    int ans;
    cin>>n;
    ans=n;
    for (int i=0;i<n;i++)cin>>a[i];
    for (int i=1;i<n;i++){
        ans+=check(i);
    }
    cout<<ans<<endl;
}
