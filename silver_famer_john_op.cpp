#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
void solve(){
	int n,mod;
	long long a[400005];
	cin>>n>>mod;
	for (int i=0;i<n;i++){
		cin>>a[i];
		a[i]%=mod;
	}
	sort(a,a+n);
	for (int i=0;i<n;i++){
		a[i+n]=a[i]+mod;
	}
	for (int i=1;i<2*n;i++){
		a[i]+=a[i-1];
	}
	long long ans=LLONG_MAX;
	for (int i=0;i<n;i++){
		int mid = (i + i + n - 1) >> 1;
		long long tans = (i != 0) ? a[i + n - 1 ] - a[mid] - a[mid - 1] + a[i - 1] : a[i + n - 1] - a[mid] - a[mid - 1];
		ans=min(ans,tans);
	}
	
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while (T--){
		solve();
	}
}
