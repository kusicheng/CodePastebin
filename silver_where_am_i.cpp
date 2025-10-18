#include <iostream>
#include <map>
#include <string>
using namespace std;
int n;
string s;
bool check(int xl){
	map<string,bool> m;
	for (int i=0;i<s.length()-xl;i++){
		string u=s.substr(i,xl); 
		m[u]++;
		if (m[u]==2)
			return false;
	}
	return true;
}
int main(){
	cin>>n>>s;
	int l=1,r=n,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (check(mid))
			r=mid;
		else l=mid+1;
	}
	cout>>r>>endl;
} 
