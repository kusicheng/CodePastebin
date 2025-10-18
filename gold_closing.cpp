#include <vector>
#include <iostream>
using namespace std;

class DSU {
private:
	vector<int> parent;
	vector<int> sizes;

public:
	DSU(int size) : parent(size), sizes(size) {
		for (int i = 0; i < size; ++i) {
			parent[i] = i;
			sizes[i] = 1;
		}
	}
	int getroot(int x) {
		if (x == parent[x]) {
			return x;
		}
		int root = getroot(parent[x]);
		parent[x] = root;
		return root;
	}
	bool unite(int x, int y) {
		int rootx = getroot(x);
		int rooty = getroot(y);
		if (rootx == rooty) {
			return false;
		}
		if (sizes[rootx] < sizes[rooty]) {
			parent[rootx] = rooty;
			sizes[rooty] += sizes[rootx];
		}
		else {
			parent[rooty] = rootx;
			sizes[rootx] += sizes[rooty];
		}
		return true;
	}
	bool query(int x, int y) {
		return getroot(x) == getroot(y);
	}
};
vector<bool> ans;
bool opened[200005];
int comps=0;
int main() {
	int n,m,u,v;
	freopen("closing.in","r",stdin);
	cin>>n>>m;
	DSU dsu(n);
	vector<vector<int> > cnc(n);
	for (int i=0;i<m;i++){
		cin>>u>>v;u--;v--;
		cnc[u].push_back(v);
		cnc[v].push_back(u);
	}
	vector<int> closings(n);
	for (int i=0;i<n;i++){
		cin>>closings[i];
		closings[i]--;
	}
	fclose(stdin);
	for (int i=n-1;i>=0;i--){
		int cur=closings[i];
		opened[cur]=1;
		comps++;
		for (int x:cnc[cur]){
			if (opened[x]&&!dsu.query(x,cur)){
				dsu.unite(x,cur);
				comps--;
			}
		}
		ans.push_back(comps==1);
	}
	freopen("closing.out","w",stdout);
	for (int i=ans.size()-1;i>=0;i--)
		(ans[i])?cout<<"YES\n":cout<<"NO\n";
	fclose(stdout);
}
