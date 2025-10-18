#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
int n,a[1005][1005],freq[2002];//frequency of element i
vector<int> elemfreq[2002];//list of elements at frequency i
void arrswap(int x,int y){
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			if (a[i][j]==x)
				a[i][j]=y;
			else if (a[i][j]==y)
				a[i][j]=x;
		}
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>a[i][j];
			freq[a[i][j]]++;
		}
	}
	for (int i=0;i<=2*n;i++){
		elemfreq[freq[i]].push_back(i);
	}
	for (int i=0;i<=2*n;i++){
		while (elemfreq[freq[i]].size()<2)
			elemfreq[freq[i]].push_back(-100);
	}
	//op on smaller half
	for (int i=1;i<=n;i++){
		int freqielem=elemfreq[i][0];
		int toswap=i+1;
		int toswapfreq=freq[toswap];
		swap(elemfreq[i][0],elemfreq[toswapfreq][0]);
		swap(freq[toswap],freq[freqielem]);
		arrswap(freqielem,toswap);
	}
	//for (int i=0;i<=n;i++){
	//	cout<<"elements at freq "<<i<<": ";
	//	for (int x:elemfreq[i])cout<<x<<" ";
	//	cout<<endl;
	//}
	//op on larger half
	for (int i=1;i<n;i++){
		if (elemfreq[i][0]>elemfreq[i][1])swap(elemfreq[i][0],elemfreq[i][1]);
		int freqielem=elemfreq[i][1];
		int toswap=2*n-i+1;
		int toswapfreq=freq[toswap];
		swap(elemfreq[i][1],elemfreq[toswapfreq][1]);
		swap(freq[toswap],freq[freqielem]);
		//cout<<freqielem<<" "<<toswap<<endl;
		arrswap(freqielem,toswap);
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n-1;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<a[i][n-1]<<endl;
	}
	
	//for (int i=0;i<=n;i++){
	//	cout<<"elements at freq "<<i<<": ";
	//	for (int x:elemfreq[i])cout<<x<<" ";
	//	cout<<endl;
	//}
}
