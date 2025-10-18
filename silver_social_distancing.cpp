#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int n,m;
pair<ll,ll> intervals[200005];
bool check(ll d){
	ll possible=0,tplaced=-999999999999999999;
	for (int i=0;i<m;i++){
		if (tplaced+d<intervals[i].first){
			tplaced=intervals[i].first;
			possible++;
		}
		while (tplaced+d<=intervals[i].second){
			possible++;
			tplaced+=d;
			if (possible>=n)return 1;
		}
	}
	if (possible>=n)return 1;
	return 0;
}
int main(){
	freopen("socdist.in","r",stdin);
	cin>>n>>m;
	for (int i=0;i<m;i++)cin>>intervals[i].first>>intervals[i].second;
	fclose(stdin);
	sort(intervals,intervals+m);
	ll l=1,r=1e18+5,mid;
	while (l<r){
		mid=r-((r-l)>>1);
		if (check(mid))
			l=mid;
		else r=mid-1;
		//cout<<l<<" "<<r<<endl;
	}
	freopen("socdist.out","w",stdout);
	cout<<l<<endl;
	fclose(stdout);
} 
