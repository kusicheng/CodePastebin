#include <stdio.h>
using namespace std;
int diffarr[1001];
int arr[1001];
int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    freopen("blist.in","r",stdin);
    int n,st,et,dt,max1=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d%d",&st,&et,&dt);
        diffarr[st]+=dt;diffarr[et+1]-=dt;
    }
    //findmax in diffarr;
    for (int i=0;i<1001;i++){
        if (i==0)arr[i]=diffarr[i];
        else arr[i]=arr[i-1]+diffarr[i];
        //printf("%d ",arr[i]);
        max1=max(arr[i],max1);
    }
    freopen("blist.out","w",stdout);
    printf("%d",max1);
    fclose(stdin);
    fclose(stdout);
}
