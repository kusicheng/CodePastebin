#include <iostream>
using namespace std;
int n,k,b,t,c[100005],ans=2147483647;
int main(){
	freopen("maxcross.in","r",stdin);
	cin>>n>>k>>b;
	for (int i=0;i<b;i++){
		cin>>t;
		c[t]++;
	}
	fclose(stdin);
	for (int i=1;i<=n;i++)c[i]+=c[i-1];
	for (int i=1;i<=n-k;i++)
		ans=min(ans,c[i+k]-c[i]);
	freopen("maxcross.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
}
