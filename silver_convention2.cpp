#include <stdio.h>
#include <queue>
#include <algorithm>
struct c{
	int idx,first,second;
} a[100005];
struct cmp {
    bool operator()(const c&a,c&b)const {
        return a.idx>b.idx;
    }
};
bool cmp2(c x,c y){
	return x.first<y.first;
}
std::priority_queue<c, std::vector<c>, cmp> nq;
void solve(int n){
	int ans=0,tlast=a[0].second+a[0].first;
	for (int i=1;i<n;i++){
		while (a[i].first<=tlast&&i<n)
			nq.push(a[i++]);
		if (!nq.size()){
			tlast=a[i].second+a[i].first;
			continue;
		}
		ans=std::max(ans,tlast-nq.top().first);
		tlast+=nq.top().second;
		nq.pop();
	}
	while (nq.size()){
		ans=std::max(ans,tlast-nq.top().first);
		tlast+=nq.top().second;
		nq.pop();
	}
	//freopen("convention2.out","w",stdout);
	printf("%d\n",ans);
	//fclose(stdout);
}
int main(){
	int n;
	freopen("2.in","r",stdin);
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",&a[i].first,&a[i].second);
		a[i].idx=i;
	}
	fclose(stdin);
	std::sort(a,a+n,cmp2);
	solve(n);
}
