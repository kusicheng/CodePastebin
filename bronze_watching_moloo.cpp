#include <iostream>
#define ll long long
using namespace std;
ll days[100001],n,k,ans;
ll min(ll a,ll b){
    return (a<b)?a:b;
}
int main(){
    cin>>n>>k;
    for (ll i=0;i<n;i++)cin>>days[i];
    for (ll i=0;i<n-1;i++){
        if (i==0){
            ans+=k+1;
        }
        ll cost1=days[i+1]-days[i];
        ll cost2=k+1;
        ans+=min(cost1,cost2);
    }
    cout<<ans<<endl;
}
