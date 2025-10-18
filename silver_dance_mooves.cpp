#include <vector>
#include <iostream>
#undef size
using namespace std;
int parent[200005];
int sizes[200005];
int getparent(int node){
	if (parent[node]!=node)
		node=getparent(parent[node]);
	return node;
}
int main(){
	for (int i=0;i<200005;i++){
		sizes[i]=1;
		parent[i]=i;
	}
	int n,k,pos1,pos2;
	cin>>n>>k;
	for (int i=0;i<k;i++){
		cin>>pos1>>pos2;
		pos1=getparent(pos1);
		pos2=getparent(pos2);
		if (getparent(pos1)!=getparent(pos2)){
			if (sizes[pos1]<sizes[pos2]){
				parent[pos1]=pos2;
				sizes[pos2]+=sizes[pos1];
			}
			else {
				parent[pos2]=parent[pos1];
				sizes[pos1]+=sizes[pos2];
			}
		}
	}
	for (int i=1;i<=n;i++)
		cout<<sizes[getparent(i)]-1<<endl;
}
