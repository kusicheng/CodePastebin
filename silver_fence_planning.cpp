#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int> > coords;
vector<vector<int> > graph;
bool visited[100001];
int perimeter(int node){
	int minx=2147483647,maxx=-2147483647,miny=2147483647,maxy=-2147483647;
	queue<int> q;
	q.push(node);
	while (q.size()){
		minx=min(minx,coords[q.front()].first);
		maxx=max(maxx,coords[q.front()].first);
		miny=min(miny,coords[q.front()].second);
		maxy=max(maxy,coords[q.front()].second);
		for (int x:graph[q.front()])if (!visited[x])q.push(x);
		visited[q.front()]=1;
		q.pop();
	}
	return 2*(maxx-minx+maxy-miny);
}
int main(){
	freopen("fenceplan.in","r",stdin);
	int n,m,u,v,ans=2147483647;cin>>n>>m;
	coords.resize(n);
	graph.resize(n);
	for (auto &l:coords)cin>>l.first>>l.second;
	for (int i=0;i<m;i++){
		cin>>u>>v;u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	fclose(stdin);
	for (int i=0;i<n;i++)
		if (!visited[i])
			ans=min(ans,perimeter(i));
	freopen("fenceplan.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
} 
