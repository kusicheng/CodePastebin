#include <iostream>
#include <algorithm>
using namespace std;
int n,sumto,got;
pair<int,int> a[5005],tofind;
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.first<y.first;
}
int main(){
	cin>>n>>sumto;
	for (int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i+1;
	}
	sort(a,a+n,cmp);
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			tofind={sumto-a[i].first-a[j].first,0};
			got=upper_bound(a,a+n,tofind,cmp)-a-1;
			if (a[got].first==tofind.first&&got!=i&&got!=j&&got>=0){
				cout<<a[i].second<<" "<<a[j].second<<" "<<a[got].second;
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE";
} 
