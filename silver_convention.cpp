#include <stdio.h>//CORRECT SOLUTION
#include <algorithm>
#define ll long long
using namespace std;
ll a[100005];
int n,m,lim;
bool check(ll time){//lim is 2
    int firstcow=0;
    int cnt=1;
    for (int i=0;i<n;i++){
        if(i-firstcow+1>lim||a[i]-a[firstcow]>time){
            printf("time limit: %d. %d caused new bus\n",time,i);
            firstcow=i;
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return cnt<=m;
}
int main(){
    freopen("convention.in","r",stdin);
    scanf("%d %d %d",&n,&m,&lim);
    for (int i=0;i<n;i++)scanf("%lld",&a[i]);
    fclose(stdin);
    sort(a,a+n);
    ll l=0,r=1000000001,mid,ans;//1 1 3 4 10 11
    while (l<=r){
        mid=((r-l)>>1)+l;
        //printf("%lld %lld\n",l,r);
        if (check(mid)){
            r=mid-1;
            ans=mid;
        }
        else {
            l=mid+1;
        }
    }
    freopen("convention.out","w",stdout);
    printf("%lld\n",ans);
    fclose(stdout);
}
