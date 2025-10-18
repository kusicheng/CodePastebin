#include <iostream>
#include <vector>
using namespace std;
const int N=2505;
int n,u,v,ans;
vector<int> tree[N];
int changes[N];
int plist[N];
void cc(int node,int parent){
	for (int x:tree[node])
		if (x!=parent){
			cc(x,node);
			plist[node]+=12-plist[x];
			plist[node]%=12;
		}
}
int main(){
	freopen("clocktree.in","r",stdin); 
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>changes[i];
	for (int i=0;i<n-1;i++){
		cin>>u>>v;
		u--;
		v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	fclose(stdin);
	for (int i=0;i<n;i++){
		for(int i=0;i<n;i++)
			plist[i]=changes[i];
		cc(i,N-1);
		if (plist[i]==1||plist[i]==0)ans++;
	}
	freopen("clocktree.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
} 
