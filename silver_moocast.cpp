#include <stdio.h>
#include <vector>
#include <cmath>
#define ff first.first
#define fs first.second
using namespace std;
int store[205],n,ans=0;
vector<pair<pair<int,int>,int> > a;
int calculate(int node){
	int count=1;
	store[node]=1;
	for (int i=0;i<n;i++)
		if (!store[i]&&pow(a[node].ff-a[i].ff,2)+pow(a[node].fs-a[i].fs,2)<=pow(a[node].second,2))
			count+=calculate(i);
	return count;
}
int main(){
	freopen("moocast.in","r",stdin);
	scanf("%d",&n);a.resize(n);
	for (auto &l:a)scanf("%d%d%d",&l.ff,&l.fs,&l.second);
	fclose(stdin);
	for (int i=0;i<n;i++){
		ans=max(ans,calculate(i));
		for (int i=0;i<n;i++)store[i]=0;
	}
	freopen("moocast.out","w",stdout);
	printf("%d\n",ans);
	fclose(stdout);
}
