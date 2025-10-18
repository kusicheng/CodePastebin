#include <algorithm>
#include <queue>
#include <vector>
#include <stdio.h>
struct cmp {
    bool operator()(const std::pair<int, int>&a,const std::pair<int, int>&b)const {
        return a.first > b.first;
    }
};
int n,s,e,ans=1;
struct al{
	int first,second,idx,day;
} a[200005];
bool cmpfirst(al x, al y){
	return x.first<y.first;
}
bool cmpidx(al x,al y){
	return x.idx<y.idx;
}
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> r;
void solve(){
	r.push({a[0].second,1});
	a[0].day=1;
	for (int i=1;i<n;i++){
		if (r.top().first<a[i].first){
			r.push({a[i].second,r.top().second});
			a[i].day=r.top().second;
			r.pop();
		}
		else {
			r.push({a[i].second,r.size()+1});
			a[i].day=r.size();
			ans++;
		}
	}
	std::sort(a,a+n,cmpidx);
	printf("%d\n",ans);
	for (int i=0;i<n-1;i++)printf("%d ",a[i].day);
	printf("%d\n",a[n-1].day);
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d%d",&a[i].first,&a[i].second);
		a[i].idx=i;
	}
	std::sort(a,a+n,cmpfirst);
	solve();
} 
