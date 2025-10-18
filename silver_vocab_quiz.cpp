#include <iostream>
#include <vector>
#define N 1000005
using namespace std;
int pos;
int n;
vector<int> graph[N];
int tdist[N];
int activechildn[N];
int a[N];
void truedist(int node,int parent,int dist){
	tdist[node]=dist;
	for (int x:graph[node]){
		if (x!=parent){
			truedist(x,node,dist+1);
		}
	}
}
int calcdist(int node){
	int parent=a[node];
	if (node==0)return 1;
	if (activechildn[parent]==2){
		return calcdist(parent);
	}
	else {
		activechildn[parent]--;
		return tdist[parent]+1;
	}
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>pos;
		a[i]=pos;
		graph[pos].push_back(i);
		graph[i].push_back(pos);
	}
	for (int i=0;i<=n;i++){
		activechildn[i]=graph[i].size();
	}
	truedist(0,0,0);
	int q=-1;
	for (int i=0;i<N;i++){
		if (graph[i].size()==1){
			q++;
		} 
	}
	if (graph[0].size()==1)q--;
	for (int i=0;i<q;i++){
		cin>>pos;
		cout<<calcdist(pos)<<endl;
	}
	cout<<0<<endl;
}
