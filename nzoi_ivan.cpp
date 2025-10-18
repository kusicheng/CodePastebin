#include <cmath>
#include <iostream>
#define ll long long
#define MSTOP 100005 
using namespace std;
int n,m,visits[MSTOP],ans[MSTOP];
pair<ll,ll> cities[MSTOP];
ll costs[MSTOP];
int dist(pair<ll,ll> a,pair<ll,ll> b){
	return ceil(sqrt(pow(b.first-a.first,2)+pow(b.second-a.second,2)));
}
int findlast(int cidx){
	int l=-1,r=m,mid;
	while (l<r){
		mid=(l+r+1)>>1;
		//cout<<"To visit "<<cidx<<" from "<<mid<<" costs "<<costs[mid]+dist(cities[visits[mid]],cities[cidx])<<endl;
		if (costs[mid]+dist(cities[visits[mid]],cities[cidx])<=costs[m-1])
			l=mid;
		else r=mid-1;
		//cout<<l<<" "<<r<<endl;
	}
	return l;
}
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++)cin>>cities[i].first>>cities[i].second;
	for (int i=0;i<m;i++){
		cin>>visits[i];
		if (i)
			costs[i]=costs[i-1]+dist(cities[visits[i]],cities[visits[i-1]]);
	}
	for (int i=m;i<MSTOP;i++)costs[i]=costs[m-1];
	for (int i=0;i<n;i++){
		int u=findlast(i);//city id
		//cout<<u<<endl;
		if (u!=-1)
			ans[u]++;
	}
	for (int i=m-1;i>=0;i--)ans[i]+=ans[i+1];
	for (int i=0;i<m;i++)cout<<ans[i]-1<<" ";
}
