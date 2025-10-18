#include <iostream>
#include <algorithm>
using namespace std;
int a[50005],n,k;
int vals[50005],max1,max2,idx;
int main(){
	freopen("diamond.in","r",stdin);
	cin>>n>>k;
	for (int i=0;i<n;i++)cin>>a[i];
	fclose(stdin);
	sort(a,a+n);
	for (int i=0;i<n;i++){
		vals[i]=upper_bound(a,a+n,a[i]+2*k)-a-i-1;
		if (vals[i]>max1){
			idx=i;
			max1=vals[i];
		}
	}
	for (int i=0;i<n;i++){
		if (idx<=i&&i<=idx+vals[idx]){
			continue;
		}
		if (i+vals[i]<idx)
			max2=max(max2,vals[i]);
		else if (i+vals[i]>=idx)
			max2=max(max2,idx-i);
	}
	freopen("diamond.out","w",stdout);
	cout<<max1+max2<<endl;
	fclose(stdout);
}
