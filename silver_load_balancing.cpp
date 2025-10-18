#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN (1<<17)
using namespace std;
int S[2*MAXN],S2[2*MAXN],n,pos,lastn;
void update(int *s,int x,int dx){
	x+=MAXN;
	s[x]+=dx;
	for (x=x>>1;x;x>>=1)
		s[x]=s[2*x]+s[2*x+1];
}
int q(int x,int l1,int r1,int l2,int r2){
	if (x>MAXN){
		(l1<r1?l1:r1)+=S[x];
		(l2<r2?l2:r2)+=S2[x];
		return max(l1,max(r1,max(l2,r2)));
	}
	int c1=x*2;
  	int c2=x*2+1;
  	if (max(l1+S[c1],l2+S2[c1])<max(r1+S[c2],r2+S2[c2]))
    	return q(c2,l1+S[c1],r1,l2+S2[c1],r2);
	else
    	return q(c1,l1,r1+S[c2],l2,r2+S2[c2]);
}
bool cmp(pair<int,int> a,pair<int,int> b){
	return make_pair(a.second,a.first)<make_pair(b.second,b.first);
}
int main(){
	freopen("balancing.in","r",stdin);
	cin>>n;
	vector<pair<int,int> >a(n);
	for (pair<int,int> &l:a)cin>>l.first>>l.second;
	fclose(stdin);
	sort(a.begin(),a.end());
	lastn=a[0].first;
	for (int i=0;i<n;i++){
		if (a[i].first!=lastn){
			lastn=a[i].first;
			pos++;
		}
		a[i].first=pos;
	}
	sort(a.begin(),a.end(),cmp);
	for (pair<int,int> l:a)update(S,l.first,1);
	int ans=n;
	for (int i=0;i<n;){
		int span=0;
		while (i+span<n&&a[i].second==a[i+span].second){
			update(S,a[i+span].first,-1);
			update(S2,a[i+span].first,1);
			span++;
		}
		ans=min(ans,q(1,0,0,0,0));
		i+=span;
	}
	freopen("balancing.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
}
