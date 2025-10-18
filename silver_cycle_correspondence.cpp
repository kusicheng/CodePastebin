#include <unordered_map>
#include <map>
#include <stdio.h>
int n,k,u,maxn,ans1[500005],ans2[500005];
int main(){
	scanf("%d%d",&n,&k);
	std::unordered_map<int,int> f,s,s2;
	for (int i=1;i<=k;i++){
		scanf("%d",&u);
		f[u]=i;
	}
	for (int i=1;i<=k;i++){
		scanf("%d",&u);
		s[u]=i;
		s2[u]=k-i+1;
	}
	u=0;
	for (int i=1;i<=n;i++){
		if (f[i]!=0&&s[i]!=0)
			ans1[(f[i]-s[i]>0)?f[i]-s[i]:f[i]-s[i]+k]++;
		else if (f[i]==0&&s[i]==0)u++;
		
		if (f[i]!=0&&s2[i]!=0)
			ans2[(f[i]-s2[i]>0)?f[i]-s2[i]:f[i]-s2[i]+k]++;
	}
	for (int i=1;i<=n;i++)if (maxn<ans1[i]||maxn<ans2[i])maxn=std::max(ans1[i],ans2[i]);
	printf("%d\n",maxn+u);
} 
