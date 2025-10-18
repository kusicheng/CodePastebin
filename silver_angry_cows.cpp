#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll n,shots,cowpos[50005];
bool check(ll p){
	int fired=0,lpos=0,rpos;
	while (fired<shots&&lpos<n){
		rpos=lpos;
		while (rpos<n&&cowpos[rpos]-cowpos[lpos]<=2*p){
			rpos++;
		}
		lpos=rpos;
		fired++;
	}
	return lpos>=n;
}
int main(){
	freopen("angry.in","r",stdin);
	cin>>n>>shots;
	for (int i=0;i<n;i++)cin>>cowpos[i];
	fclose(stdin);
	sort(cowpos,cowpos+n);
	ll l=0,r=1000000000,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (check(mid))
			r=mid;
		else l=mid+1;
	}
	freopen("angry.out","w",stdout);
	cout<<l<<endl;
	fclose(stdout);
}
