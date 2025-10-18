#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,tc,tm,T,spentc,spentm;
struct customer{
	int ordc,ordm,wait;
};
bool cmp(customer a,customer b){
	return a.wait>b.wait;
}
void solve(){
	cin>>n>>tc>>tm;
	vector<customer> orders(n);
	for (auto &l:orders){
		cin>>l.ordc>>l.ordm>>l.wait;
		l.wait=ordc*tc+ordm*tm-l.wait;
	}
	sort(orders.begin(),orders.end(),cmp);//sort by overwaited time
	for (int i=0;i<n;i++){
		while (orders[i].wait>0){
			
		}
	}
}
int main(){
	cin>>T;
	while (T--)
		solve();
}
