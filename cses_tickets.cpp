#include <iostream>
#include <set>
using namespace std;
int main(){
	int n,m,u;
	multiset<int,int> t;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>u;
		t.insert(u);
	}
	for (int i=0;i<m;++i){
		cin>>u;
		auto it=t.upper_bound(u);
		if (it==t.begin()) {
			cout<<-1<<endl;
		}else{
			it--;
			cout<<*it<<endl;
			t.erase(it);
		}
	}
}
