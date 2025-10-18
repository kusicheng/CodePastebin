#include <iostream>
using namespace std;
long double perunit,unit;
int main(){
	int n,t;
	cin>>n>>t;
	for (int i=0;i<n;i++){
		cin>>unit;
		perunit+=1/unit;
	}
	cout<<perunit<<endl;;
	cout<<(int)(t/perunit)<<endl;
}
