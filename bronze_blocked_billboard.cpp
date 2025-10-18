#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int x1,x2,y1,y2,x3,x4,y3,y4,x5,x6,y5,y6;
    freopen("billboard.in","r",stdin);
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&x5,&y5,&x6,&y6);
    fclose(stdin);
    int b1=max(min(x2,x6)-max(x1,x5),0)*max(min(y2,y6)-max(y1,y5),0);
    int b2=max(min(x4,x6)-max(x3,x5),0)*max(min(y4,y6)-max(y3,y5),0);
    freopen("billboard.out","w",stdout);
    printf("%d\n",(x2-x1)*(y2-y1)+(x4-x3)*(y4-y3)-b1-b2);
    fclose(stdout);
}
