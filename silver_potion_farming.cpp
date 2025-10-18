#include <iostream>
#include <vector>
const int N = 100005;
using namespace std;
vector<int> tree[N];
int rooms[N],paths[N],check[N];
int u,v,ans,times,n;
void cc(int node,int parent){
	for (int x:tree[node])
		if (x!=parent){
			cc(x,node);
			paths[node]+=paths[x];
		}
	int used=min(paths[node],check[node]);
	paths[node]-=used;
	ans+=used;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>rooms[i];
		rooms[i]--;
	}
	for (int i=0;i<n-1;i++){
		cin>>u>>v;
		u--;
		v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for (int i=1;i<n;i++){
		if (tree[i].size()==1){
			paths[i]++;
			times++;
		}
	}
	for (int i=0;i<times;i++)
		check[rooms[i]]++;
	cc(0,0);
	cout<<ans<<endl;
}
