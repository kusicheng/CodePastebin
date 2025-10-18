#include <cmath>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
ll a[100001];
int main(){
    int n,tuit;
    ll ans=0,tans;
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for (ll i=0;i<n;i++){
        tans=a[i]*(n-i);
        if (tans>ans){
            ans=tans;
            tuit=a[i];
        }
    }
    cout<<ans<<" "<<tuit<<endl;
}
