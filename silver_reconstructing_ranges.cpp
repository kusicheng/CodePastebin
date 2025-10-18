#include <iostream>
using namespace std;
int n,a[301],rij[301][301];
bool isok(int idx){
	int minx=2147483647,maxx=-2147483648;
	for (int i=idx;i<n;i++){
		minx=min(minx,a[i]);
		maxx=max(maxx,a[i]);
		if (maxx-minx!=rij[idx][i-idx])
			return false;
	}
	return true;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n-i;j++)
			cin>>rij[i][j];
	for (int i=n-1;i>=0;i--){
		a[i]=a[i+1]+rij[i][1];
		if (!isok(i))
			a[i]=a[i+1]-rij[i][1];
	}
	for (int i=0;i<n-1;i++)cout<<a[i]<<" ";
	cout<<a[n-1]<<endl;
}
