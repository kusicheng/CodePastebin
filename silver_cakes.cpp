#include <iostream>
using namespace std;
void solve(){
	int n;
	long long cakes[500002];
	cakes[0]=0;
	cin>>n;
	for (int i=1;i<=n;i++){	
		cin>>cakes[i];
		cakes[i]+=cakes[i-1];
	}
	long long b=0,e=0;
	int winstart=n/2;
	int winend=n;
	while (winstart>0){
		long long front=cakes[winstart-1];
		long long back=cakes[n]-cakes[winend];
		e=max(e,front+back);
		winstart--;
		winend--;
	}
	cout<<cakes[n]-e<<" "<<e<<endl;
}
int main(){
	int T;cin>>T;
	while (T--){
		solve();
	}
} 
