#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
string dir;
ll x,y,dx,dy,l;
pair<ll,ll> changes[100005];
bool check(int days){
	ll movex=days/l*changes[l].first+changes[days%l].first;
	ll movey=days/l*changes[l].second+changes[days%l].second;
	return days>=abs(dx-movex)+abs(dy-movey);
}
int main(){
	cin>>x>>y>>dx>>dy>>l>>dir;dx-=x;dy-=y;
	for (int i=1;i<=l;i++){
		const char m=dir[i];
		switch (m){
			case 'U':changes[i]=make_pair(changes[i-1].first,changes[i-1].second+1);break;
			case 'D':changes[i]=make_pair(changes[i-1].first,changes[i-1].second-1);break;
			case 'L':changes[i]=make_pair(changes[i-1].first-1,changes[i-1].second);break;
			default: changes[i]=make_pair(changes[i-1].first+1,changes[i-1].second);
		}
	}
	ll l=0,r=1e10+1,mid;
	while (l<r){
		mid=(l+r)>>1;
		cout<<check(mid)<<" "<<mid<<endl;
		check(mid)?r=mid:l=mid+1;
	}
	if (r==(ll) 1e10+1)cout<<-1<<endl;
	else cout<<r<<endl;
} 
