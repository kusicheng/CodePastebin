#include <iostream>
#include <algorithm>
#define ll long long
#define p pair<ll,ll>
#define N 2505
using namespace std;
ll n,ans,g[N][N];
p cow[N];
int util(int x1,int y1,int x2,int y2){
	return g[x2+1][y2+1]-g[x1][y2+1]-g[x2+1][y1]+g[x1][y1];
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++)cin>>cow[i].first>>cow[i].second;
	sort(cow,cow+n);
	for (int i=0;i<n;i++)cow[i].first=i+1;
	sort(cow,cow+n,[](const p &a,const p &b) -> bool {return make_pair(a.second,a.first)<make_pair(b.second,b.first);});
	for (int i=0;i<n;i++)cow[i].second=i+1;
	for (int i=0;i<n;i++)g[cow[i].first][cow[i].second]=1;
	for (int i=1;i<N;i++)
		for (int j=1;j<N;j++)
			g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++)
			ans+=util(0,i,min(cow[i].first,cow[j].first)-1,j)*util(max(cow[i].first,cow[j].first)-1,i,n-1,j);
			//(left side rectangle number)*(right side rectangle number)
	cout<<ans+1<<endl;
}
