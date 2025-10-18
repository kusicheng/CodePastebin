#include <iostream>
#include <vector>
#define maxn 100005
#define maxk 200005
using namespace std;
int n,m,pos1[maxk],pos2[maxk],opos[maxn],ans[maxn];
vector<int> graph[maxn];
int main(){
	cin>>n>>k;
	for (int i=0;i<m;i++){
		cin>>pos1[i]>>pos2[i];
		pos1[i]--;
		pos2[i]--;
	}
	for (int i=0;i<n;i++){
		graph[i].push_back(i);
		opos[i]=i;
	}
	for (int i=0;i<m;i++){
		//swapping pos1[i] and pos2[i]
		graph[opos[pos1[i]]].push_back(pos2[i]);
		graph[opos[pos2[i]]].push_back(pos1[i]);
		swap(opos[pos1[i]],opos[pos2[i]]);
	}
	for (int i=0;i<n;i++){
		if (!ans[i]){
			
		}
	}
} 
