#include <iostream>
#include <queue>
#include <functional>
#define ll long long
using namespace std;
const ll N=300005;
ll n,itv;
ll cows[N];
bool good[N];
ll parent[N];
ll find(ll x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
int main(){
	freopen("14.in","r",stdin);
	cin>>n>>itv;
	for (int i=0;i<n;i++){
		cin>>cows[i];
		parent[i]=i;
	}
	fclose(stdin);
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;//start time, interviewer id
	ll ctime=0;
	for (int i=0;i<itv;i++){
		pq.push({cows[i],i});//beginning is like this
	}
	ll curitv=itv;//currently next in line
	while (curitv<n){
		ll top=pq.top().first;//finishing fastest right now
		vector<ll> available;//stores finished interviewer id
		while (pq.top().first==top){//while time is same store the interviewers available
			available.push_back(pq.top().second);
			pq.pop();
		}
		ctime=top;//update time
		for (ll x:available)parent[find(x)]=find(available[0]);//set parent as equal since they will all have same answer
		int i=0;
		for (i=0;i<available.size()&&curitv<n;i++,curitv++){
			pq.push({ctime+cows[curitv],available[i]});//push until none are left or full
		}
		if (curitv==n&&i!=available.size()){//all cows have been interviewed so theres two cases
			//first there are the interviewers in the list so mark them as possible
			good[find(0)]=1;//just mark 1, its the same result
		}
		else if (curitv==n){
			                                    //else the next free interviewers will be the only candidates
			ctime=pq.top().first;                          //remember to update time
			while (pq.top().first==ctime){
				cout<<"good: "<<pq.top().second<<endl;
				good[find(pq.top().second)]=1;
				pq.pop();
			}
		}
	}
	cout<<ctime<<endl;
	for (int i=0;i<itv;i++){
		if (good[find(i)])cout<<"1";
		else cout<<"0";
	}
	cout<<endl;
	return 0;
}
