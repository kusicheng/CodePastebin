#include <stdio.h>
#include <algorithm>
using namespace std;
int diffarrh[101];
int diffarrb[101];
int arrh[101],arrb[101];
int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    freopen("speeding.in","r",stdin);
    int n,m,l,smax,pst=0,ans=0;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d%d",&l,&smax);
        diffarrh[pst+1]+=smax;diffarrh[pst+l+1]-=smax;
        pst+=l;
    }
    pst=0;
    for (int i=0;i<m;i++){
        scanf("%d%d",&l,&smax);
        diffarrb[pst+1]+=smax;diffarrb[pst+l+1]-=smax;
        pst+=l;
    }
    for (int i=0;i<101;i++){
        if (i==0){
            arrh[i]=diffarrh[i];
            arrb[i]=diffarrb[i];
        }
        else {
            arrh[i]=arrh[i-1]+diffarrh[i];
            arrb[i]=arrb[i-1]+diffarrb[i];
            ans=max(ans,arrb[i]-arrh[i]);
        }
        //printf("%d %d\n",arrh[i],arrb[i]);
    }
    freopen("speeding.out","w",stdout);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
}
