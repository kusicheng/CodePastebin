#include <stdio.h>
#include <set>
int n,g,ans,u;
std::set<int> s;
int main()
{
	scanf("%d%d",&n,&g);
	for (int i=1;i<=n;i++)
		s.insert(i);
	do 
	{
		scanf("%d",&u);
		auto x=s.upper_bound(u);
		if (x!=s.end()){
			x--;
			s.erase(x);
			ans++;
		}
		else break;
	}
	while (g--);
	printf("%d\n",ans);
}
