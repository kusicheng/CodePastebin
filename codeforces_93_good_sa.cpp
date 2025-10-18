#include <map>
#include <iostream>
#include <string>
using namespace std;
long long solve(){
	int n,sum=0;
	string s;
	long long total=0;
	map<int,int> m;
	m[0]=1;
	cin>>n>>s;
	for (int i=0;i<n;i++){
		int x=s[i]-'0'-1;
		sum+=x;
		total+=m[sum];
		m[sum]++;
	}
	return total;
}
int main(){
	int t;
	cin>>t;
	while (t--)cout<<solve()<<endl;
}
