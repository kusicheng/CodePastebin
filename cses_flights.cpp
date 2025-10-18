#include <iostream>
#include <vector>
using namespace std;
int visiteda[100005],visitedb[100005],u,v,n,m;
vector<int> a[200005];
vector<int> b[200005];
void dfs_a(int i){
	visiteda[i]=1;
	for (int x:a[i])
		if (!visiteda[x])
			dfs_a(x);
}
void dfs_b(int i){
	visitedb[i]=1;
	for (int x:b[i])
		if (!visitedb[x])
			dfs_b(x);
}
int main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>u>>v;
		a[u].push_back(v);
		b[v].push_back(u);
	}
	dfs_a(1);
	dfs_b(1);
	for (int i=1;i<=n;i++){
		if (!visiteda[i]){
			cout<<"NO\n1 "<<i<<endl;
			return 0;
		}
		if (!visitedb[i]){
			cout<<"NO\n"<<i<<" 1\n";
			return 0;
		}
	}
	cout<<"YES\n";
}
