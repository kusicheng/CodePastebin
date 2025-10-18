#include <iostream>
#include <algorithm>
#include <vector>
#define sf second.first
#define ss second.second
using namespace std;
int tosort[100005],n,m;
pair<int,pair<int,int> > e[100005];
bool visited[100005];
vector<int> graph[100005];
void dfs(int node){
	if (!visited[node]){
		visited[node]=1;
		for (int x:graph[node])
			dfs(x);
	}
}
bool check(int minw){
	for (int i=0;i<n;i++){
		visited[i]=0;
		graph[i].clear();
	}
	for (int i=m-1;i>=0;i--){
		if (e[i].first>=minw){
			graph[e[i].sf-1].push_back(e[i].ss-1);
			graph[e[i].ss-1].push_back(e[i].sf-1);
		}
		else break;
	}
	dfs(0);
	for (int i=0;i<n;i++)if (!visited[i]&&tosort[i]!=i+1)return false;
	return true;
}
int main(){
	freopen("wormsort.in","r",stdin);
	cin>>n>>m;
	for (int i=0;i<n;i++)cin>>tosort[i];
	for (int i=0;i<m;i++)cin>>e[i].sf>>e[i].ss>>e[i].first;
	fclose(stdin);
	sort(e,e+m);
	int l=-1,r=1e9+1,mid;
	while (l<r){
		mid=(l+r+1)>>1;
		check(mid)?l=mid:r=mid-1;
	}
	freopen("wormsort.out","w",stdout);
	if (l!=1e9+1)
		cout<<l<<endl;
	else cout<<-1<<endl;
	fclose(stdout);
}
