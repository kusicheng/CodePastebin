#include <iostream>
#include <vector>
using namespace std;
vector<int> graphsame[100001];
vector<int> graphdif[100001];
int visited[100001];
int n,m,n1,n2;
char ch;
int dfs(int node,int color){
	visited[node]=color;
	for (int x:graphsame[node]){
		if (visited[x]!=color&&visited[x])return 0;
		if (!visited[x])dfs(x,color); 
	}
	for (int x:graphdif[node]){
		if (visited[x]==color)return 0;
		if (!visited[x])dfs(x,(color==1?2:1));
	}
	return 1;
}
int main(){
	freopen("revegetate.in","r",stdin);
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>ch>>n1>>n2;
		if (ch=='S'){
			graphsame[n1].push_back(n2);
			graphsame[n2].push_back(n1);
		}
		else {
			graphdif[n1].push_back(n2);
			graphdif[n2].push_back(n1);
		}
	}
	fclose(stdin);
	int ans=0;
	for (int i=0;i<n;i++)
		if (!visited[i])
			ans+=dfs(i,1);
	freopen("revegetate.out","w",stdout);
	if (ans){
		cout<<1;
		for (int i=0;i<ans-1;i++)cout<<0;
		fclose(stdout);
		return 0;
	}
	cout<<0;
	fclose(stdout);
}
