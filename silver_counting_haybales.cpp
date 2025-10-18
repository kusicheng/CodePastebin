#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int lf,rf,n,q;
int main(){
	freopen("haybales.in","r",stdin);
	freopen("haybales.out","w",stdout);
	scanf("%d%d",&n,&q);
	vector<int> a(n);
	for (int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	for (int i=0;i<q;i++){
		scanf("%d%d",&lf,&rf);
		int low=upper_bound(a.begin(),a.end(),lf)-a.begin();
		int ans=upper_bound(a.begin(),a.end(),rf)-a.begin()-low;
		if (a[low-1]==lf)ans++;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
}
