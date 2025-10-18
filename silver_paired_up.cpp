#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> a[100005];
int n,maxn;
int main(){
	freopen("pairup.in","r",stdin);
	cin>>n;
	for (int i=0;i<n;i++)cin>>a[i].second>>a[i].first;
	fclose(stdin);
	sort(a,a+n);
	int l=0,r=n-1,mini;
	while (l<r){
		if (a[l].second==0)l++;
		if (a[r].second==0)r--;
		maxn=max(maxn,a[l].first+a[r].first);
		mini=min(a[l].second,a[r].second);
		a[l].second-=mini;
		a[r].second-=mini;
	}
	if (a[l].second)maxn=max(maxn,a[l].first+a[l].first);
	freopen("pairup.out","w",stdout);
	cout<<maxn<<endl;
	fclose(stdout);
}
