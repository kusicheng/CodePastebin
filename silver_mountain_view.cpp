#include <stdio.h>
#include <algorithm>
using namespace std;
struct P{
	double x,y;
} a[100005];
int n,vis=0,ans=1;
bool cmp(P m,P n){
	return m.x-m.y<n.x-n.y;
}
bool yes(int peakn){
	if (a[peakn].x==a[vis].x&&a[vis].y<a[peakn].y) return true;
	else if (a[peakn].x==a[vis].x&&a[vis].y>=a[peakn].y)return false;
	double slopex=(a[vis].y-a[peakn].y)/(a[vis].x-a[peakn].x);
	if (1>slopex&&slopex>-1)return true;
	return false;
}
int main(){
	freopen("mountains.in","r",stdin);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	fclose(stdin);
	sort(a,a+n,cmp);
	for (int i=1;i<n;i++)if (yes(i)){
		vis=i;
		ans++;
	}
	freopen("mountains.out","w",stdout);
	printf("%d\n",ans);
	fclose(stdout);
}
