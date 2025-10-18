#include <stdio.h>
#include <algorithm>
#undef f
#undef s
#define f first
#define s second
#define P pair<int,int>
using namespace std;
P a[100005];
int n,total,ans,start,end1,minalone=2147483647;
bool cmp(P x,P y){
	return x.f<y.f;
}
int main(){
	freopen("lifeguards.in","r",stdin);
	scanf("%d",&n);
	for (int i=0;i<n;i++)scanf("%d%d",&a[i].f,&a[i].s);
	fclose(stdin);
	sort(a,a+n,cmp);
	for (int i=0;i<n;i++)
		if (a[i].s>=end1){
			start=max(a[i].f,end1);
			total+=a[i].s-start;
			end1=a[i].s;
		}
	start=0;
	a[n].f=a[n-1].s;
	for (int i=0;i<n;i++){
		minalone=min(minalone,min(a[i].s,a[i+1].f)-max(a[i].f,start));
		start=max(start,a[i].s);
	}
	freopen("lifeguards.out","w",stdout);
	printf("%d\n",total-max(minalone,0));
	fclose(stdout);
} 
