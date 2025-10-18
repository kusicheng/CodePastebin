#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
void dfs(vector<vector<int> > &graph, vector<int> &component, int node, int root){
	for (int x:graph[node]){
		if (component[x]!=root){
			component[x]=root;
			dfs(graph,component,x,root);
		}
	}
}
int main(){
	int t;cin>>t;
	while (t--){
		int n,m;
		cin>>n>>m;
		vector<vector<int> > graph(n);
		for (int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			u--;
			v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		vector<int> component(n);
		for (int i=0;i<n;i++)
			component[i]=i;
		for (int i=0;i<n;i++)
			if (component[i]==i)
				dfs(graph,component,i,i);
		if (!component[n-1]){
			cout<<0<<endl;
			continue;
		}
		vector<vector<int> >rootidx(n);
		for (int i=0;i<n;i++)
			rootidx[component[i]].push_back(i);
		vector<ll> cost1(n,1e9),cost2(n,1e9);
		int toidx=0,fromidx=0;
		for (int i=0;i<n;i++){
			while (toidx<rootidx[component[0]].size()){
				//cout<<i<<" "<<rootidx[0][toidx]<<endl;
				cost1[component[i]]=min(cost1[component[i]],(ll)abs(i-rootidx[component[0]][toidx]));
				if (rootidx[component[0]][toidx]<i)toidx++;
				else break;
			}
			if (toidx)toidx--;
			while (fromidx<rootidx[component[n-1]].size()){
				//cout<<i<<" "<<rootidx[n-1][fromidx]<<endl;
				cost2[component[i]]=min(cost2[component[i]],(ll)abs(i-rootidx[component[n-1]][fromidx]));
				if (rootidx[component[n-1]][fromidx]<i)fromidx++;
				else break;
			}
			if (fromidx)fromidx--;
		}
		ll ans=1e18;
		for (int i=0;i<n;i++){
			//cout<<cost1[i]<<" "<<cost2[i]<<endl;
			ans=min(ans,cost1[i]*cost1[i]+cost2[i]*cost2[i]);
		}
		cout<<ans<<endl;
	}
}
