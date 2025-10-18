#include <iostream>
#include <vector>
const int INTMAX=2147483647;
using namespace std;
int dis1[40001],dis2[40001],disn[40001];
int n,m,b,e,p,u,v;
vector<int> graph[40001];
void markdistance1(int node,int dist){
	dis1[node]=dist;
	dist++;
	for (int x:graph[node])if (dis1[x]>dist)
		markdistance1(x,dist);
}
void markdistance2(int node,int dist){
	dis2[node]=dist;
	dist++;
	for (int x:graph[node])if (dis2[x]>dist)
		markdistance2(x,dist);
}
void markdistancen(int node,int dist){
	disn[node]=dist;
	dist++;
	for (int x:graph[node])if (disn[x]>dist)
		markdistancen(x,dist);
}
int main(){
	for (int i=0;i<40001;i++){
		dis1[i]=INTMAX;
		dis2[i]=INTMAX;
		disn[i]=INTMAX;
	}
	freopen("piggyback.in","r",stdin);
	cin>>b>>e>>p>>n>>m;
	for (int i=0;i<m;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	fclose(stdin);
	markdistance1(1,0);
	markdistance2(2,0);
	markdistancen(n,0);
	int ans=INTMAX;
	for (int i=1;i<=n;i++)
		ans=min(ans,dis1[i]*b+dis2[i]*e+disn[i]*p);
	freopen("piggyback.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
}
