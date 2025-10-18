#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
int n,leave,ans,cowi=1;
set<pll> q;
vector<pair<int,pll>> cows;//.first=arrive,.second.first=seniority,.second.second=ttl
void solve(){
	sort(cows.begin(),cows.end());
	leave=cows[0].first+cows[0].second.second;
	while (cowi<n||q.size()){
		while (cowi<n&&cows[cowi].first<leave){
			q.insert({cows[cowi].second.first,cowi});
			cowi++;
		}
		if (!q.size()&&cowi<n)
			leave=cows[cowi].first+cows[cowi++].second.second;
		else if (q.size()){
			ans=max(ans,leave-cows[q.begin()->second].first);
			leave+=cows[q.begin()->second].second.second;
			q.erase(q.begin());
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("convention2.in","r",stdin);
	cin>>n;
	cows.resize(n);
	for (int i=0;i<n;i++){
		cin>>cows[i].first>>cows[i].second.second;
		cows[i].second.first=i;
	}
	fclose(stdin);
	freopen("convention2.out","w",stdout);
	solve();
	fclose(stdout);
}
