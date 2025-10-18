#include <iostream>
using namespace std;
int n,a[1001][1001];
int calcrow(int row,int start){
	int sum1=0;
	for (int i=start;i<n;i+=2)
		sum1+=a[row][i];
	return sum1;
}
int calccol(int col,int start){
	int sum1=0;
	for (int i=start;i<n;i+=2)
		sum1+=a[i][col];
	return sum1;
}
int main(){
	cin>>n;
	for (int i=0;i<n;i++)for (int j=0;j<n;j++)cin>>a[i][j];
	long long colans=0,rowans=0;
	for (int i=0;i<n;i++){
		rowans+=max(calcrow(i,0),calcrow(i,1));
		colans+=max(calccol(i,0),calccol(i,1));
	}
	cout<<max(colans,rowans)<<endl;
} 
