#include <iostream>
#define ll long long
using namespace std;
ll n,a[50005];
ll max(ll a,ll b){
    return (a>b)?a:b;
}
int main(){
    freopen("div7.in","r",stdin);
    cin>>n>>a[0];
    for (int i=1;i<n;i++){
        cin>>a[i];
        a[i]=(a[i]+a[i-1])%7;
    }
    fclose(stdin);
    int ans=-1000000;
    for (int i=0;i<n-1;i++){
        for (int j=i;j<n;j++){
            if ((a[j]-a[i])%7==0)ans=max(ans,(ll)j-i);
        }
    }
    freopen("div7.out","w",stdout);
    cout<<ans<<endl;
    fclose(stdout);
}
