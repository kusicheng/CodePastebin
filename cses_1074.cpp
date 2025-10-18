#include <iostream>
#include <algorithm>
using namespace std;
int n,a[200005];
int main(){
	cin>>n;
	for (int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int mid=a[n/2];
	long long ans=0;
	for (int i=0;i<n/2;i++)
		ans+=mid-a[i];
	for (int i=n/2;i<n;i++)
		ans+=a[i]-mid;
	cout<<ans<<endl;
}
