#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int n,wmove,a[1234][1234],ans;
const int dx=405;
int calc(int x,int y){
	long long s=0;
	for (int i=x-wmove;i<=x+wmove;i++)
		s+=a[x+(wmove-abs(x-i))][y-(x-i)]-a[x-(wmove-abs(x-i))-1][y-(x-i)];
	return s;
}
int main(){
	//freopen("lazy.in","r",stdin);
	scanf("%d %d",&n,&wmove);
	for (int i=1+dx;i<=n+dx;i++)
		for (int j=1+dx;j<=n+dx;j++){
			scanf("%d",&a[i][j]);
			a[i][j]+=a[i-1][j];
		}
	for (int i=n+1+dx;i<900+dx;i++){
		for (int j=1+dx;j<=n+dx;j++){
			a[i][j]=a[i-1][j];
		}
	}
	//fclose(stdin);
	for (int x=1+dx;x<=n+dx;x++)
		for (int y=1+dx;y<=n+dx;y++)
			ans=max(ans,calc(x,y));
	//freopen("lazy.out","w",stdout);
	printf("%lld\n",ans);
	//fclose(stdout);
} 
