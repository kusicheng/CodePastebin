#include <iostream>
#define ll long long
#define M (ll)1000000007
using namespace std;
int k;
ll expk(ll a,ll p){
	ll res=1;
	while (p){
		if (p&1){
			k+=res*a/M;
			res=res*a%M;
		}
		a=a*a%M;
		p>>=1;
	}
	return res;
}
ll exp(ll a,ll p){
	ll res=1;
	while (p){
		if (p&1){
			res=res*a%M;
		}
		a=a*a%M;
		p>>=1;
	}
	return res;
}
int main(){
	long long n,a,b,c;
	cin>>n;
	while (n--){
		cin>>a>>b>>c;
		ll u=expk(b,c);
		ll ans=exp(a,u)*exp(exp(a,k),M);
		cout<<k<<endl;
		cout<<ans%M<<endl;
	}
	//a^(b^c mod M + kM)
}
