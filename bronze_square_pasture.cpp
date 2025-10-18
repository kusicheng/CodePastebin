#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int x1,y1,x2,y2,x3,y3,x4,y4;
    freopen("square.in","r",stdin);
    scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    fclose(stdin);
    int minx=min(x1,x3),maxx=max(x2,x4),miny=min(y1,y3),maxy=max(y2,y4);
    freopen("square.out","w",stdout);
    printf("%d\n",max((maxx-minx)*(maxx-minx),(maxy-miny)*(maxy-miny)));
    fclose(stdout);
}
