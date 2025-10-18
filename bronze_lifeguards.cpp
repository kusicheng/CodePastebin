#include <stdio.h>
using namespace std;
int a[1001];
int sel[101][2];
int max(int a,int b){return (a>b)?a:b;}
int main()
{
    freopen("lifeguards.in","r",stdin);
    int n,s,e,ans=0,tempans,ans1;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d",&sel[i][0],&sel[i][1]);
        a[sel[i][0]]++;a[sel[i][1]]--;
    }
    fclose(stdin);
    for (int i=0;i<n;i++){
        a[sel[i][0]]--;a[sel[i][1]]++;
        for (int it=0;it<1000;it++){
            if (it==0)tempans=a[0];
            else tempans=tempans+a[it];
            if (tempans>0)ans1++;
            //printf("%d ",tempans);
        }
        //printf("\n");
        ans=max(ans,ans1);
        ans1=0;
        a[sel[i][0]]++;a[sel[i][1]]--;
    }
    freopen("lifeguards.out","w",stdout);
    printf("%d",ans);
    fclose(stdout);
}
