#include <iostream>
#include <algorithm>
#include <vector>
#define p pair<int,int>
#define N 100005
using namespace std;
int seg1[N],seg2[N],n;
vector<p> a;
bool cmp(p x,p y){
	return make_pair(x.second,x.first)<make_pair(y.second,y.first);
}
void update(int *seg,int pos,int dx){
	pos+=N;
	seg[pos]+=dx;
	for (int i=pos>>1;i;i>>=1)
		seg[i]=seg[2*i]+seg[2*i+1];
}
int main(){
	cin>>n;
	a.resize(n);
	for (int i=0;i<n;i++)
		cin>>a[i].first>>a[i].second;
	sort(a.begin(),a.end());
	int compress=0,cpos=a[0].first;
	for (int i=0;i<n;i++){
		if (a[i].first!=cpos){
			cpos=a[i].first;
			compress++;
		}
		a[i].first=compress;
	}
	sort(a.begin(),a.end(),cmp);
	for (int i=0;i<n;i++)
		update(seg1,a[i].first,1);
	for (int i=0;i<N;i++)
		if (seg1[i])
			cout<<"pos "<<i<<" "<<seg1[i]<<endl;
}
