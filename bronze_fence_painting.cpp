#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,c,d;
    freopen("paint.in","r",stdin);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    fclose(stdin);
    freopen("paint.out","w",stdout);
    if (c<b&&d>a)
        printf("%d",abs(min(a,c)-max(b,d)));
    else
        printf("%d",b-a+d-c);
    fclose(stdout);
}
