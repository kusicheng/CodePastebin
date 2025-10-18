#include <iostream>
#include <vector>
#define N 200005
#define ll long long
#define ff first.first
#define fs first.second
using namespace std;
vector<int> tree[N];
ll treesums[N],bales[N];
int n,u,v;
ll av;
vector<pair<pair<int,int>,ll> > ans;
ll dfs(const int &node,const int &parent){
	ll subtreesums=0;
	for (int x:tree[node])
		if (x!=parent)
			treesums[node]+=dfs(x,node);
	treesums[node]+=bales[node];
	return treesums[node];
}
void computeans(const int &node,const int &parent){
	for (int x:tree[node]){
		if (treesums[x]>=0&&x!=parent)
			computeans(x,node);
		if (treesums[x]>0&&x!=parent)
			ans.push_back({{x+1,node+1},treesums[x]});
	}
	for (int x:tree[node]){
		if (treesums[x]<0&&x!=parent){
			ans.push_back({{node+1,x+1},-treesums[x]});
			computeans(x,node);
		}
	}
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>bales[i];
		av+=bales[i];
	}
	av/=n;
	for (int i=0;i<n;i++)
		bales[i]-=av;
	for (int i=0;i<n-1;i++){
		cin>>u>>v;
		u--;
		v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	//let root = 0, edge = first edge. Divide the tree according that edge
	dfs(0,N-1);
	
	//compute moves from root
	computeans(0,N-1);
	
	cout<<ans.size()<<endl;
	for (auto x:ans)
		cout<<x.ff<<" "<<x.fs<<" "<<x.second<<endl;
} 
