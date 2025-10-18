#include <stdio.h>
using namespace std;
int a[1001],n;
int slice(int idx){
    int fac=0,ans=0;
    for (int i=idx;i<n;i++){
        ans+=a[i]*fac;
        fac++;
    }
    for (int i=0;i<idx;i++){
        ans+=a[i]*fac;
        fac++;
    }
    return ans;
}
int min(int a, int b){
    return (a<b)?a:b;
}
int main()
{
    int ans=2147483647;
    freopen("cbarn.in","r",stdin);
    scanf("%d",&n);
    for (int i=0;i<n;i++)scanf("%d",&a[i]);
    fclose(stdin);
    for (int i=0;i<n;i++){
        ans=min(ans,slice(i));
    }
    freopen("cbarn.out","w",stdout);
    printf("%d\n",ans);
    fclose(stdout);
}
