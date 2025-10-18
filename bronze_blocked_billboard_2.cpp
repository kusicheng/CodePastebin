#include <stdio.h>
#include <algorithm>
using namespace std;
int check(int a,int b,int c,int d){
    printf("%d %d %d\n",b-a,c-a,b-d);
    if (a<=c&&c<=b&&a<d&&d<b)return b-a;
    if (a<=c&&c<=b&&b<=d)return c-a;
    if (a<=c&&c<=b&&a>=d)return b-d;
}
int main(){
    int x1,y1,x2,y2,x3,y3,x4,y4;
    //freopen("billboard.in","r",stdin);
    scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    //fclose(stdin);
    int xb1=max(min(x2,x4)-max(x1,x3),0);
    int yb1=max(min(y2,y4)-max(y1,y3),0);
    //freopen("billboard.out","w",stdout);
    printf("%d %d\n",check(x1,x2,x3,x4),(y2-y1));
    if (xb1<x2-x1&&yb1<y2-y1)printf("%d\n",(x2-x1)*(y2-y1));
    else if (xb1>=x2-x1&&yb1<y2-y1)printf("%d\n",(x2-x1)*check(y1,y2,y3,y4));
    else if (xb1<x2-x1&&yb1>=y2-y1)printf("%d\n",check(x1,x2,x3,x4)*(y2-y1));
    else printf("%d\n",0);
    //fclose(stdout);
}
