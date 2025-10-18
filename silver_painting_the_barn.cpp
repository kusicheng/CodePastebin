#include <iostream>
using namespace std;
int n,want,grid[1005][1005],x1,y1,x2,y2,ans;
int main(){
	freopen("paintbarn.in","r",stdin);
	cin>>n>>want;
	for (int i=0;i<n;i++){
		cin>>x1>>y1>>x2>>y2;
		grid[x1+1][y1+1]++;
		grid[x1+1][y2+1]--;
		grid[x2+1][y1+1]--;
		grid[x2+1][y2+1]++;
	}
	fclose(stdin);
	for (int i=1;i<1005;i++){
		for (int j=1;j<1005;j++){
			grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
			if (grid[i][j]==want)ans++;
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	freopen("paintbarn.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
}
