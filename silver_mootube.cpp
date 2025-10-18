#include <iostream>
#include <vector>
const int N = 5002;
using namespace std;
vector<pair<int,int> > tree[N];
int u,v,r,n,q,ans,node;
void cc(const int &node,const int &parent,const int &rmin){
	for (pair<int,int> x:tree[node]){
		if (x.first!=parent&&x.second>=r){
			cc(x.first,node,min(rmin,r));
			ans++;
		}
	}
}
int main(){
	freopen("mootube.in","r",stdin);
	freopen("mootube.out","w",stdout);
	cin>>n>>q;
	for (int i=0;i<n-1;i++){
		cin>>u>>v>>r;
		tree[u].push_back({v,r});
		tree[v].push_back({u,r});
	}
	for (int i=0;i<q;i++){
		cin>>r>>node;
		cc(node,node,2147483647);
		cout<<ans<<endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
}
