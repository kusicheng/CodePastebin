#include <iostream>
#define ll long long
using namespace std;
ll owes,minpay,limday;
bool check(ll n,ll k,ll m,ll x){
    ll g = 0;
    while(k > 0 && g < n) {
        ll y=(n-g)/x;
        if(y < m) {
            ll leftover=(n-g+m-1)/m;//leftover days
            return leftover<=k;
        }
        ll maxmatch=n-x*y;
        ll numdays=(maxmatch-g)/y+1;
        if(numdays > k) numdays = k;
        g += y * numdays;
        k -= numdays;
    }
    return g >= n;
}
int main(){
    freopen("loan.in","r",stdin);
    cin>>owes>>minpay>>limday;
    fclose(stdin);
    ll l=1,r=1000000000005,mid,ans;
    while (l<=r){
        mid=((r-l)>>1)+l;
        if (check(owes,minpay,limday,mid)){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    freopen("loan.out","w",stdout);
    cout<<ans<<endl;
    fclose(stdout);
}
