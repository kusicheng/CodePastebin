#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
multiset<int> lengths;
set<int> lights;
int x,n,pos;
int main(){
	cin>>x>>n;
	while (n--){
		cin>>pos;
		auto r=lights.upper_bound(pos);
		auto l=r;
		l--;
		lights.insert(pos);
		lengths.erase(lengths.find(*r-*l));
		lengths.insert(*r-pos);
		lengths.insert(pos-*l);
		cout<<*(--lengths.end())<<" ";
	}
}
