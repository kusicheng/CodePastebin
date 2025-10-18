#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int xy[2][101];
int check(int a,int b,int c){
    int t;
    if (xy[1][a]==xy[1][b]&&xy[0][a]==xy[0][c])return abs(xy[0][a]-xy[0][b])*abs(xy[1][a]-xy[1][c]);
    t=a;a=b;b=c;c=t;
    if (xy[1][a]==xy[1][b]&&xy[0][a]==xy[0][c])return abs(xy[0][a]-xy[0][b])*abs(xy[1][a]-xy[1][c]);
    t=b;b=c;c=t;
    if (xy[1][a]==xy[1][b]&&xy[0][a]==xy[0][c])return abs(xy[0][a]-xy[0][b])*abs(xy[1][a]-xy[1][c]);
    t=a;a=b;b=c;c=t;
    if (xy[1][a]==xy[1][b]&&xy[0][a]==xy[0][c])return abs(xy[0][a]-xy[0][b])*abs(xy[1][a]-xy[1][c]);
    t=b;b=c;c=t;
    if (xy[1][a]==xy[1][b]&&xy[0][a]==xy[0][c])return abs(xy[0][a]-xy[0][b])*abs(xy[1][a]-xy[1][c]);
    t=a;a=b;b=c;c=t;
    if (xy[1][a]==xy[1][b]&&xy[0][a]==xy[0][c])return abs(xy[0][a]-xy[0][b])*abs(xy[1][a]-xy[1][c]);
    t=b;b=c;c=t;
    return -1;
}
int main(){
    int n,ans=0;
    freopen("triangles.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++)cin>>xy[0][i]>>xy[1][i];
    fclose(stdin);
    for (int p1=0;p1<n;p1++){
        for (int p2=0;p2<n;p2++){
            for (int p3=0;p3<n;p3++){
                ans=max(ans,check(p1,p2,p3));
            }
        }
    }
    freopen("triangles.out","w",stdout);
    cout<<ans<<endl;
    fclose(stdout);
}
