#include <iostream>
using namespace std;
int l=0,r=1000005,n,graph[500][500],mid,visited[500][500],nodes;
void dfs(int nx,int ny){
	nodes++;
	int v=graph[nx][ny];
	visited[nx][ny]=1;
	if (nx>0&&!visited[nx-1][ny]&&abs(graph[nx-1][ny]-v)<=mid)
		dfs(nx-1,ny);
	if (ny>0&&!visited[nx][ny-1]&&abs(graph[nx][ny-1]-v)<=mid)
		dfs(nx,ny-1);
	if (ny<n-1&&!visited[nx][ny+1]&&abs(graph[nx][ny+1]-v)<=mid)
		dfs(nx,ny+1);
	if (nx<n-1&&!visited[nx+1][ny]&&abs(graph[nx+1][ny]-v)<=mid)
		dfs(nx+1,ny);
}
bool check(){
	int ans=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			visited[i][j]=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (!visited[i][j]){
				nodes=0;
				dfs(i,j);
				ans=max(ans,nodes);
			}
		}
	}
	return ans>=(n*n+1)>>1;
}
int main(){
	freopen("tractor.in","r",stdin);
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>graph[i][j];
	fclose(stdin);
	while (l<r){
		mid=(l+r)>>1;
		check()?r=mid:l=mid+1;
	}
	freopen("tractor.out","w",stdout);
	cout<<r<<endl;
	fclose(stdout);
} 
