#include <stdio.h>
#include <vector>
const int N = 102;
using namespace std;
int n,m,ans,x,y,a,b;
vector<pair<int,int> > sw[N][N];
bool visited[N][N],lights[N][N];
void cc(int x,int y){
	visited[x][y]=1;
	lights[x][y]=1;
	for (pair<int,int> u:sw[x][y])
		if (!visited[u.first][u.second]&&(visited[u.first-1][u.second]||visited[u.first+1][u.second]||visited[u.first][u.second+1]||visited[u.first][u.second-1]))
			cc(u.first,u.second);
		else 
			lights[u.first][u.second]=1;
	if (!visited[x+1][y]&&lights[x+1][y])
		cc(x+1,y);
	if (!visited[x][y+1]&&lights[x][y+1])
		cc(x,y+1);
	if (!visited[x-1][y]&&lights[x-1][y])
		cc(x-1,y);
	if (!visited[x][y-1]&&lights[x][y-1])
		cc(x,y-1);
}
int main(){
	freopen("lightson.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		scanf("%d%d%d%d",&x,&y,&a,&b);
		sw[x][y].push_back({a,b});
	}
	fclose(stdin);
	cc(1,1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		    if (lights[i][j])
		    	ans++;
	freopen("lightson.out","w",stdout);
	printf("%d\n",ans);
	fclose(stdout);
}
