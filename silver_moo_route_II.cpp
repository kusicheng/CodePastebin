#include <iostream>
#include <algorithm>
#include <vector>
#define N 200005
using namespace std;
int n,m,a[N],ans[N];
struct port{
	int tleave,tarrive,dest;
};
bool cmp(const port &a,const port &b){
	return a.tleave>b.tleave;
}
vector<port> edges[N];
int si,ei,st,et;
void dfs(const int &node,const int &time){
	ans[node]=time;
	for (port x:edges[node]){
		//cout<<x.tleave<<" "<<x.dest<<endl;
		if (time+a[node] > x.tleave){
			break;
		}
		if (ans[x.dest] > x.tarrive || ans[x.dest]==-1)
			dfs(x.dest,x.tarrive);
	}
}
int main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>si>>st>>ei>>et;
		si--;
		ei--;
		edges[si].push_back({st,et,ei});
	}
	for (int i=0;i<n;i++)
		cin>>a[i];
	for (int i=0;i<n;i++)
		sort(edges[i].begin(),edges[i].end(),cmp);
	for (int i=0;i<n;i++)
		ans[i]=-1;
	dfs(0,-2147483647);
	ans[0]=0;
	for (int i=0;i<n;i++)
		cout<<ans[i]<<endl;
} 
