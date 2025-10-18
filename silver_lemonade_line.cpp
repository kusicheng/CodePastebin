#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
	int n, a[100005], ans = 0;
	freopen("lemonade.in","r",stdin);
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", &a[i]);
	fclose(stdin);
	sort(a,a+n,greater<int>());
	for (int i=0;i<n;i++){
		if (a[i]<i)
			break;
		ans++;
	}
	freopen("lemonade.out","w",stdout);
	printf("%d\n",ans);
	fclose(stdout);
} 
