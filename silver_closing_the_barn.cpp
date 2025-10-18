#include <iostream>
#include <vector>
using namespace std;
int n,m,visited[3005],u,v,closed;
vector<int> a[3005];
void dfs(int last){
	if (visited[last]==0){
		//cout<<"visitied "<<last<<endl;
		visited[last]=1;
		for (int x:a[last])
			dfs(x);
	}
}
string solve(){
	for (int i=1;i<=n;i++)if (visited[i]==1)visited[i]=0;
	for (int i=1;i<=n;i++)if (visited[i]==0){
		dfs(i);
		break;
	}
	for (int i=1;i<=n;i++){
		if (visited[i]==0)
			return "NO";
	}
	return "YES";
}
int main(){
	freopen("closing.in","r",stdin);
	freopen("closing.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i=0;i<n;i++){
		cout<<solve()<<endl;
		int closed;cin>>closed;
		visited[closed]=-1;
	}
	fclose(stdin);
	fclose(stdout);
} 
