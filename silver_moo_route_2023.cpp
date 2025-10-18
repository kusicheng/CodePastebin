#include <iostream>
#include <cstring>
using namespace std;
int n,a[100005];
string ans="";
void print(){
	for (int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
		ans+="R";
	}
	int idx=n-1;
	while (idx>=0){
		while (idx>=0&&a[idx]>1||a[idx+1]==0&&idx>=0){
			a[idx--]--;
			ans+="L";
		}
		while (a[idx+1]>0){
			a[++idx]--;
			ans+="R";
		}
	}
	cout<<ans<<endl;
}
