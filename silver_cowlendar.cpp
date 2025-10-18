#include <iostream>
#include <set>
#include <cmath>
#define ll long long
using namespace std;
ll n,temp,minx=99999999999,dif;
set<ll> s,cases;
int test(ll L){
	if (L>minx)
		return false;
	set<ll> t;
	for (ll x:s){
		t.insert(x%L);
		if (t.size()>3)
			return 0;
	}
	return 1;
}
void solve(){
	auto x=s.begin();
	auto y=s.begin();
	for (int i=0;i<4;i++){
		y=x;
		for (int j=i+1;j<4;j++){
			y++;
			dif=*y-*x;
			for (ll k=1;k<pow(dif,0.5)+1;k++)
				if (!(dif%k)){
					cases.insert(k);
					cases.insert(dif/k);
				}
		}
		x++;
	}
	ll ans=0;
	for (ll x:cases)
		if (test(x))
			ans+=x;
	cout<<ans<<endl;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>temp;
		s.insert(temp);
		minx=min(minx,temp);
	}
	minx/=4;
	if (s.size()<4){
		cout<<(minx+1)*minx/2<<endl;
		return 0;
	}
	solve();
} 
