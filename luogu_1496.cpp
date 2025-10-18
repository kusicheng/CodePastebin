#include <iostream>
#include <algorithm>
using namespace std;
int n,si,ei,ans=0;
pair<int,int> a[20005];
int main(){
	cin>>n;
	for (int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
	sort(a,a+n);
	si=a[0].first;
	ei=a[0].second;
	ans+=ei-si;
	for (int i=1;i<n;i++){
		if (a[i].second>ei){
			ans+=a[i].second-a[i].first-max(ei-a[i].first,0);
			ei=a[i].second;
		}
	}
	cout<<ans<<endl;
} 
