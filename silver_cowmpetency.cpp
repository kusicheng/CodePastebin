#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T,n,SCORE_MAX,q;
void solve(){
	cin>>n>>q>>SCORE_MAX;
	vector<int> scoreslist(n);
	vector<int> scoresmax(n);
	vector<pair<int,int>> comps(q);
	for (int i=0;i<n;i++){
		cin>>scoreslist[i];
		scoresmax[i]=max(scoresmax[i],scoreslist[i]);
	}
	for (int i=0;i<q;i++){
		cin>>comps[i].first>>comps[i].second;
		comps[i].first--;
		comps[i].second--;
	}
	sort(comps.begin(),comps.end());
	for (int i=0;i<q;i++){
		int l=comps[i].first,r=comps[i].second;
		if (scoreslist[l]==0){
			scoreslist[l]=scoresmax[r-1];
		}
		if (scoreslist[r]==0){
			scoreslist[r]=scoresmax[r]+1;
		}
		if (scoreslist[r]<scoreslist[l] || )
	}
}
int main(){
	cin>>T;
	while (T--)
		solve();
} 
