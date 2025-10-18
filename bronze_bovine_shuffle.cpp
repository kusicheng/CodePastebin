#include <stdio.h>
#include <algorithm>
using namespace std;
struct cow {
    int idx,id;
} cows[100];
int idxl[101];
bool cmp(cow a,cow b){
    return (a.idx<b.idx)?true:false;
}
int main()
{
    int n;
    freopen("shuffle.in","r",stdin);
    scanf("%d",&n);
    for (int i=0;i<n;i++)scanf("%d",&idxl[i]);
    for (int i=0;i<n;i++)scanf("%d",&cows[i].id);
    for (int i=0;i<3;i++){
        for (int j=0;j<n;j++){
            for (int i=0;i<n;i++){
                if (idxl[i]==j+1){
                    cows[j].idx=i;break;
                }
            }
        }
        sort(cows,cows+n,cmp);
    }
    freopen("shuffle.out","w",stdout);
    for (int i=0;i<n;i++)printf("%d\n",cows[i].id);
    fclose(stdin);
    fclose(stdout);
}
