#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
map<int,set<int>> br;
map<int,int> cows;
vector<pair<int,pair<int,int> > > ops;
int main(){
	int n,g;
	freopen("measurement.in","r",stdin);
	cin>>n>>g;
	ops.resize(n);
	for (pair<int,pair<int,int> > &l:ops){
		cin>>l.first>>l.second.first>>l.second.second;
		cows[l.second.first]=g;
		br[g].insert(l.second.first);
	}
	fclose(stdin);
	sort(ops.begin(),ops.end());
	int ans=0;
	for (pair<int,pair<int,int> > l:ops){
		auto compr=*br.rbegin();
		//cout<<(*br.rbegin()).first<<endl;
		int id=l.second.first,dx=l.second.second;
		int milkbeforeupdate=cows[id];
		br[milkbeforeupdate].erase(id);
		br[milkbeforeupdate+dx].insert(id);
		cows[id]+=dx;
		
		if (compr.second!=(*br.rbegin()).second)
			ans++;
	}
	freopen("measurement.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
}
