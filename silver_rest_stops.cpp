#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l,n,fs,bs;
pair<int,int> stops[100005];
vector<pair<int,int> > greedystops;
int main(){
	freopen("reststops.in","r",stdin);
	cin>>l>>n>>fs>>bs;
	int dif=fs-bs;
	for (int i=0;i<n;i++)
		cin>>stops[i].first>>stops[i].second;
	fclose(stdin);
	sort(stops,stops+n);
	greedystops.push_back(stops[n-1]);
	for (int i=n-2;i>=0;i--)
		if (stops[i].second>(*greedystops.rbegin()).second)
			greedystops.push_back(stops[i]);
	long long ans=0;
	int lastpos=0;
	pair<int,int> l;
	for (int i=greedystops.size()-1;i>=0;i--){
		l=greedystops[i];
		ans+=((long long)l.first-lastpos)*l.second*dif;
		lastpos=l.first;
	}
	freopen("reststops.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
} 
