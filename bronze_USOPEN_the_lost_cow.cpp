#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int s,e,pos;
    long long ans=0,dy=1;
    freopen("lostcow.in","r",stdin);
    scanf("%d%d",&s,&e);
    fclose(stdin);
    int dir=1;
    while (true){
        if (dir==1&&s+dy>=e&&s<e||dir==-1&&s-dy<=e&&s>e){
            ans+=abs(s-e);
            break;
        }
        else {
            ans+=dy*2;
            dy*=2;
            dir=-dir;
        }
    }
    freopen("lostcow.out","w",stdout);
    printf("%lld",ans);
    fclose(stdout);
}
