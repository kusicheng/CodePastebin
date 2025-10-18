#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
#define MAXN 50005
using namespace std;
int a[MAXN],n,ans,b[MAXN],mark[MAXN];
int main(){
	freopen("14.in","r",stdin);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		mark[a[i]]=1;
	}
	fclose(stdin);
	sort(a,a+n/2);
	sort(a+n/2,a+n,greater<int>());
	int idx=0;
	for (int i=1;i<=2*n;i++)
		if (!mark[i])
			b[idx++]=i;
	idx=n/2;
	for (int i=0;i<n/2;i++,ans++){
		while (a[i]>b[idx]&&idx<n)idx++;
		idx++;
		cout<<idx<<endl;
		if (idx==n)break;
	}
	idx=n/2-1;
	for (int i=n/2;i<n;i++,ans++){
		while (a[i]<b[idx]&&idx>=0)idx--;
		idx--;
		cout<<idx<<endl;
		if (idx<0)break;
	}
	//freopen("cardgame.out","w",stdout);
	cout<<ans<<endl;
	//fclose(stdout);
} 
