#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
ll coords[100005];
int n,c;
bool check(const ll dx){
    ll last=coords[0];
    int cnt=1;
    for (int i=1;i<n;i++){
        if (coords[i]-last>=dx){
            last=coords[i];
            cnt++;
        }
    }
    if (cnt<c)return false;
    return true;
}
int main(){
    scanf("%d %d",&n,&c);
    for (int i=0;i<n;i++){
        scanf("%lld",&coords[i]);
    }
    sort(coords,coords+n);
    ll l=0,r=coords[n-1],mid,ans;
    while (l<=r){
        mid=((r-l)>>1)+l;
        cout<<mid<<" ";
        if (check(mid)){
            l=mid+1;
            ans=mid;
            //printf("%d good\n");
        }
        else {
            r=mid-1;
        }
    }
    printf("%lld\n",ans);
}
