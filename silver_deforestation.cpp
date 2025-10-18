#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
struct rg{
	int l,r,t;
};
void solve (){
	int n,k;
	map<int,int> m;
	cin>>n>>k;
	vector<int> points(n);
	for (int &x:points)
		cin>>x;
	vector<rg> ranges(k);
	vector<int> endpoints;
	for (auto &x:ranges){
		cin>>x.l>>x.r>>x.t;
		endpoints.push_back(x.l);
		endpoints.push_back(x.r);
		m[l]++;
		m[r]--;
	}
	sort(endpoints.begin(),endpoints.end());
	endpoints.erase(unique(endpoints.begin(), endpoints.end()), endpoints.end());
	
}
int main() {
	int T;cin>>T;
	while (T--){
		solve();
	}
}
