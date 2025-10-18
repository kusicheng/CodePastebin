#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n,maxt,k,w;
long long ans;
priority_queue<pair<int,int>> towers;
pair<int,int> cows[200005];
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first>b.first;
}
int main(){
	cin>>n>>maxt>>k;
	for (int i=0;i<n;i++)
		cin>>cows[i].first>>cows[i].second;
	towers.push({2147483647,maxt});
	sort(cows,cows+n,cmp);
	for (int i=0;i<n;i++){
		int r=cows[i].second;
		while (r&&cows[i].first+k<=towers.top().first&&towers.size()){
			pair<int,int> nd=towers.top();
			if (r<nd.second){
				nd.second-=r;
				r=0;
				towers.pop();
				towers.push(nd);
			}
			else {
				r-=nd.second;
				towers.pop();
			}
		}
		ans+=cows[i].second-r;
		towers.push({cows[i].first,cows[i].second-r});
	}
	cout<<ans<<endl;
} 
