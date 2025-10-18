#include <iostream>
using namespace std;
int n,u,v,cowsplaced;
bool grid[3001][3001];
int comfy(int x,int y){
	return grid[x-1][y]+grid[x+1][y]+grid[x][y-1]+grid[x][y+1];
}
int getZero(int x,int y){
	
}
int main(){
	cin>>n;
	queue<pair<int,int>> q;
	for (int i=0;i<n;i++){
		cin>>u>>v;
		u+=1000;v+=1000;
		q.push({u,v});
		while (!q.empty()){
			u=q.front().first,v=q.front().second;
			q.pop();
			if (!grid[u][v]){
				cowsplaced++;
				grid[u][v]=1;
				if (grid[u+1][v]==1 && comfy(u+1,v)==3)
					q.push(getZero(u+1,v));
				if (grid[u-1][v]==1 && confy(u-1,y)==3)
					q.push(getZero(u-1,v));
				if (grid[u][v+1]==1 && comfy(u,v+1)==3)
					q.push(getZero(u,v+1));
				if (grid[u][v-1]==1 && confy(u,y-1)==3)
					q.push(getZero(u,v-1));
				if (comfy(u,v)==3)
					q.push(getZero(u,v));
			}
		}
	}
}
