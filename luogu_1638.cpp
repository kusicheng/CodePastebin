#include <stdio.h>
using namespace std;
int p[1000001];
int bucket[2005];
int pnum,anum;
bool check(){
    for (int i=1;i<=anum;i++)
        if (!bucket[i])return true;
    return false;
}
int main(){
    scanf("%d%d",&pnum,&anum);
    for (int i=1;i<=pnum;i++)scanf("%d",&p[i]);
    int minl=0,minr=pnum;
    for (int i=1;i<=pnum-anum;i++){
        int r=i+1;
        while (r<=pnum&&check()){
            bucket[p[r]]=1;
            r++;
        }
        if (minr-minl>r-i-1&&check()){
            minr=r-1;
            minl=i;
        }
        for (int j=1;j<=anum;j++)bucket[j]=0;
    }
    printf("%d %d",minl,minr);
}
