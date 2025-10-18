#include <iostream>
#include <string>
using namespace std;
char pos(char m){
	if ('a'<=m&&m<='z')return m-'a'+1;
	return m-'A'+27;
}
void solve(int T){
	string a,b;
	int ans=0;
	cin>>a>>b;
	int n=a.length();
	int graph[53];
	for (int i=0;i<53;i++)graph[i]=0;
	int visited[100005];
	for (int i=0;i<100005;i++)visited[i]=0;
	for (int i=0;i<n;i++){
		if (graph[pos(a[i])]!=0&&graph[pos(a[i])]!=pos(b[i])){
			cout<<-1<<endl;
			return;
		}
		if (a[i]!=b[i])
			graph[pos(a[i])]=pos(b[i]);
	}
	bool freeletter=false;
	for (int i=1;i<=52;i++)
		if (!graph[i])
			freeletter=true;
		else ans++;
	
	for (int i=1;i<=52;i++)
		if (!visited[i]&&graph[i]&&graph[i]!=i){
			int node=i;
			while (!visited[node]&&graph[node]!=node){
				visited[node]=1;
				node=graph[node];
			}
			if (node==i&&freeletter){
				ans++;
			}
			else if (node==i&&!freeletter){
				cout<<-1<<endl;
				return ; 
			}
		}
	cout<<ans<<endl;
}
int main(){
	int T;cin>>T;
	while (T--)
		solve(T);
}
