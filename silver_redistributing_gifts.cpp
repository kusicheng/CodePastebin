#include <iostream>
#include <stack>
#include <set>
using namespace std;
set<int> graph[505];
int gifts[505][505];
bool reachable(int beg,int dest){
	bool visited[505];
	for (int i=0;i<505;i++)visited[i]=0;
	stack<int> s;
	s.push(beg);
	while (s.size()){
		int a=s.top();
		s.pop();
		visited[a]=1;
		for (int x:graph[a])if (!visited[x])s.push(x);
	}
	return visited[dest];
}
int main(){
	int n,u;cin>>n;
	for (int i=1;i<=n;i++){
		bool flag=1;
		for (int j=1;j<=n;j++){
			cin>>gifts[i][j];
			if (gifts[i][j]==i)flag=0;
			if (flag)
				for (int x=1;x<j;x++)graph[gifts[i][j]].insert(gifts[i][x]);
		}
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (gifts[i][j]==i||reachable(gifts[i][j],i)){
				cout<<gifts[i][j]<<endl;break;
			}
		}
	}
}
