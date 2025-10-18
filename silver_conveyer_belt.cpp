#include <iostream>
using namespace std;
struct query{
	int x,y;
	char m;
};
char grid[1001][1001];
bool good[1001][1001];
query qlist[200001];
int ans[200001];
int n,q,curgood;
int dirx[]={0,0,-1,1};
int diry[]={-1,1,0,0};
char dirs[]={'L','R','U','D'};
bool inside(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=n;
}
bool isgood(int x,int y){
	if (!inside(x,y))return false;
	for (int i=0;i<4;i++)
		if (dirs[i]==grid[x][y]||grid[x][y]=='?')
			if (!inside(x+dirx[i],y+diry[i])||good[x+dirx[i]][y+diry[i]])
				return true;
	return false;
}
void dfs(int x,int y){
	if (!isgood(x,y)||good[x][y])
		return;
	good[x][y]=1;
	curgood++;
	for (int i=0;i<4;i++)
		dfs(x+dirx[i],y+diry[i]);
}
int main(){
	for (int i=0;i<=1000;i++)for (int j=0;j<=1000;j++)grid[i][j]='?';
	cin>>n>>q;
	for (int i=0;i<q;i++){
		cin>>qlist[i].x>>qlist[i].y>>qlist[i].m;
		grid[qlist[i].x][qlist[i].y]=qlist[i].m;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dfs(i,j);
	for (int i=q-1;i>=0;i--){
		ans[i]=n*n-curgood;
		grid[qlist[i].x][qlist[i].y]='?';
		dfs(qlist[i].x,qlist[i].y);
	}
	for (int i=0;i<q;i++)
		cout<<ans[i]<<endl;
}
