#include <iostream>
using namespace std;
int a[5005],b[5005],n,k,start1,end1,maxn;
long long ans[10010];
int main(){
	cin>>n>>maxn;
	for (int i=0;i<n;i++){
		cin>>start1>>end1;
		a[start1]++;b[end1]++;
	}
	for (int i=0;i<=maxn;i++)
		for (int j=0;j<=maxn;j++){
			if (a[i]!=0&&a[j]!=0)ans[i+j]+=a[i]*a[j];
			if (b[i]!=0&&b[j]!=0)ans[i+j+1]-=b[i]*b[j];
		}
	for (int x=1;x<=2*maxn;x++)ans[x]+=ans[x-1];
	for (int x=0;x<=2*maxn;x++)cout<<ans[x]<<endl;
}
