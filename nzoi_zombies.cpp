#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#define ll long long
using namespace std;
const string GOOD="SOLUTION IS TRIVIAL\n";
const string BAD="SOLUTION IS NON-TRIVIAL\n";
const int MAXN=50005;
bool cmp(pair<int,int> a,int b){
	return a.second<b;
}
int main(){
	int house_num,dist,programmer_num,all_full=0,temp,ans[MAXN];
	pair<int,ll> programmers[MAXN];
	set<pair<int,int> >max_cap;
	cin>>house_num>>dist>>programmer_num;
	for (int i=0;i<house_num;i++){
		cin>>temp;
		if (temp)
			max_cap.insert(make_pair(temp,i+1));
	}
	for (int i=0;i<programmer_num;i++){
		cin>>programmers[i].first>>programmers[i].second;
		programmers[i].second/=dist;
	}
	sort(programmers,programmers+programmer_num);
	for (int i=0;i<programmer_num;i++){
		set<pair<int,int> >::iterator l=lower_bound(max_cap.begin(),max_cap.end(),programmers[i].first-programmers[i].second,cmp);
		if (l==max_cap.end()||(*l).second-programmers[i].first-programmers[i].second>0){
			cout<<BAD;
			return 0;
		}
		ans[i]=(*l).second;
		if ((*l).first>1)
			max_cap.insert(make_pair((*l).first-1,(*l).second));
		max_cap.erase(l);
	}
	cout<<GOOD;
	for (int i=0;i<n;i++)
		cout<<ans[i]<<endl;
} 
