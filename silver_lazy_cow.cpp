#include <iostream>
#include <cstring>
#define maxn 805
using namespace std;
long long a[maxn][maxn],prefix[maxn][maxn],n,k,ans,sizen;
int main(){
	memset(a,-1,sizeof(a[maxn][maxn])/sizeof(a[0]));
	freopen("lazy.in","r",stdin);
	cin>>n>>k;
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
	cin>>a[i+j][n-i+j-1];
	fclose(stdin);
	sizen=2*n-1;
	for (int i=0;i<sizen;i++)
	for (int j=0;j<sizen;j++)
	prefix[i+1][j+1]=prefix[i][j+1]+prefix[i+1][j]-prefix[i][j]+max(a[i][j],(long long)0);
	for (int i=k;i<sizen-k;i++)
	for (int j=k;j<sizen-k;j++)
	if (a[i][j]!=-1)
	ans=max(ans,prefix[i+k+1][j+k+1]-prefix[i-k][j+k+1]-prefix[i+k+1][j-k]+prefix[i-k][j-k]);
	if (k>=n)ans=prefix[sizen][sizen];
	freopen("lazy.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
} 
