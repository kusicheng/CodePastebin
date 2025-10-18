#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
bool check(ll r,ll p){
	ll nr=1;
	ll tr=(ll)sqrt(r);
	for (ll i=0;4*i<r;i++)
		nr+=4*(r/(4*i+1)-r/(4*i+3));
	nr=(nr-1-4*tr)/4+2*tr+1;
	//cout<<"r= "<<r<<" nr= "<<nr<<endl; 
	return nr>=p;
}
int main(){
	int p;
	cin>>p;
	ll l=0,r=1e7+5,mid;
	while (l<r){
		mid=(l+r)/2;
		if (check(mid,p))
			r=mid;
		else l=mid+1;
	}
	cout<<r;
} 
