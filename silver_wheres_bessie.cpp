#include <iostream>
#include <vector>
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
using namespace std;
char grid[22][22];
int n,ansn;
bool visited[22][22];
void mark(int x,int y,int xmin,int xmax,int ymin,int ymax){
	visited[x][y]=1;
	if (x>xmin&&!visited[x-1][y]&&grid[x-1][y]==grid[x][y])
		mark(x-1,y,xmin,xmax,ymin,ymax);
	if (x<xmax&&!visited[x+1][y]&&grid[x+1][y]==grid[x][y])
		mark(x+1,y,xmin,xmax,ymin,ymax);
	if (y>ymin&&!visited[x][y-1]&&grid[x][y-1]==grid[x][y])
		mark(x,y-1,xmin,xmax,ymin,ymax);
	if (y<ymax&&!visited[x][y+1]&&grid[x][y+1]==grid[x][y])
		mark(x,y+1,xmin,xmax,ymin,ymax);
}
bool check(int x1,int y1,int x2,int y2){
	for (int i=0;i<22;i++)
		for (int j=0;j<22;j++)
			visited[i][j]=0;
	char a=grid[x1][y1],b='1';
	int c1=0,c2=0;
	for (int i=x1;i<=x2;i++){
		for (int j=y1;j<=y2;j++){
			if (grid[i][j]!=a){
				if (grid[i][j]!=b&&b=='1'||grid[i][j]==b)
					b=grid[i][j];
				else 
					return false;
			}
			if (!visited[i][j]){
				mark(i,j,x1,x2,y1,y2);
				grid[i][j]==a?c1++:c2++;
			}
		}
	}
	if (c1==1&&c2>=2||c1>=2&&c2==1)
		return true;
	return false;
}
vector<pair<pair<int,int>,pair<int,int>>> ans;
int main(){
	freopen("where.in","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>grid[i][j];
	fclose(stdin);
	for (int x1=1;x1<=n;x1++)
		for (int y1=1;y1<=n;y1++)
			for (int x2=x1;x2<=n;x2++)
				for (int y2=y1;y2<=n;y2++)
					if (check(x1,y1,x2,y2)){
						ans.push_back({{x1,y1},{x2,y2}});
					}
	cout<<endl<<check(1,1,4,3)<<endl;
	for (int i=0;i<ans.size();i++){
		cout<<ans[i].ff<<" "<<ans[i].fs<<" "<<ans[i].sf<<" "<<ans[i].ss<<endl;
		bool flag=true;
		for (int j=0;j<ans.size();j++)
			if (i!=j&&ans[i].ff>=ans[j].ff&&ans[i].fs>=ans[j].fs&&ans[i].sf<=ans[j].sf&&ans[i].ss<=ans[j].ss){
				flag=false;
				break;
			}
		if (flag) ansn++;
	}
	freopen("where.out","w",stdout);
	cout<<ansn<<endl;
	fclose(stdout);
}
