#include <iostream>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
int g[1500][1500],n,r;
ll findx[1500],findy[1500],cx,cy,ans,x[1500],y[1500];
pair<ll,ll> a[705];
int main(){
	cin>>n>>r;
	for (int i = 1;i <= n;i++){
		cin>>cx>>cy;
		x[2*i]=max(cx-r,(ll)0);
		x[2*i-1]=cx+r;
		y[2*i]=max(cy-r,(ll)0);
		y[2*i-1]=cy+r;
		a[i]={cx,cy};
	}
	n*=2;
	sort(x+1,x+n+1);
	for (int i=1;i<=n;i++)
		findx[i]=x[i];
	sort(y+1,y+n+1);
	for (int i=1;i<=n;i++)
		findy[i]=y[i];
	for (int i=1;i<=n/2;i++){
		int x1=lower_bound(x+1,x+n+1,max(a[i].first-r,(ll)0))-x,y1=lower_bound(y+1,y+n+1,max(a[i].second-r,(ll)0))-x,x2=lower_bound(x+1,x+n+1,a[i].first+r)-x,y2=lower_bound(y+1,y+n+1,a[i].second+r)-x;
		g[x1][y1]++;
		g[x1][y2+1]--;
		g[x2+1][y1]--;
		g[x2+1][y2+1]++;
	}
	for (int i=1;i<1500;i++)
		for (int j=1;j<1500;j++)
			g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
	for (int i=1;i<1500;i++)
		for (int j=1;j<1500;j++)
			if (g[i][j]>0)
				ans+=(findx[i+1]-findx[i])*(findy[j+1]-findy[j]);
	cout<<ans<<endl;
	//for (int i=0;i<n;i++)cout<<findx[i]<<" ";cout<<endl;
	//for (int i=0;i<n;i++)cout<<findy[i]<<" ";cout<<endl;
	for (int i=0;i<=n+1;i++){
		for (int j=0;j<=n+1;j++)cout<<g[i][j]<<" ";
		cout<<endl;
	}
	for (int i=0;i<n/2;i++)cout<<a[i].first<<" "<<a[i].second<<endl;
	//for (auto u:o2nx)cout<<u.first<<" "<<u.second<<endl;
	//for (auto u:o2ny)cout<<u.first<<" "<<u.second<<endl;
}
