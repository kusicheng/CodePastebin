#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#define sf second.first
#define ss second.second
const int N=100005;
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
	int getsize(int x){
		return sizes[x];
	}
};
struct p {
	int id;
	int vid;
	int rel;
};
bool cmp(p a,p b){
	return a.rel>b.rel;
}
p qlist[N];//first = relevance, second = video id
pair<int,pair<int,int> > edges[N];
int ans[N];
int n,q,w,u,v;
int main() {
	freopen("mootube.in","r",stdin);
	cin>>n>>q;
	for (int i=0;i<n-1;i++){
		cin>>edges[i].sf>>edges[i].ss>>edges[i].first;
		edges[i].ss--;
		edges[i].sf--;
	}
	for (int i=0;i<q;i++){
		cin>>qlist[i].rel>>qlist[i].vid;
		qlist[i].vid--;
		qlist[i].id=i;
	}
	fclose(stdin);
	sort(qlist,qlist+q,cmp);
	sort(edges,edges+n-1);
	int cidx=n-2;
	DSU dsu(n);
	for (int i=0;i<q;i++){
		while (edges[cidx].first>=qlist[i].rel){
			dsu.unite(edges[cidx].sf,edges[cidx].ss);
			cidx--;
		}
		ans[qlist[i].id]=dsu.getsize(dsu.getroot(qlist[i].vid))-1;
	}
	freopen("mootube.out","w",stdout);
	for (int i=0;i<q;i++)
		cout<<ans[i]<<endl;
	fclose(stdout);
}
