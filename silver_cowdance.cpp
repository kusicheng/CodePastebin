#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int times[10005],n,TMAX;
bool check(int dim){
	priority_queue<int,vector<int>,greater<int> > q;
	int timepassed=0;
	for (int i=0;i<n;i++){
		if (q.size()==dim){
			timepassed=q.top();
			q.pop();
		}
		if (timepassed+times[i]>TMAX)
			return 0;
		q.push(timepassed+times[i]);
	}
	return 1;
}
int main(){
	freopen("cowdance.in","r",stdin);
	cin>>n>>TMAX;
	for (int i=0;i<n;i++)
		cin>>times[i];
	fclose(stdin);
	int l=1,r=10000,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (check(mid)){
			r=mid;
		}
		else l=mid+1;
		//cout<<l<<" "<<r<<endl;
	}
	freopen("cowdance.out","w",stdout);
	cout<<l<<endl;
	fclose(stdout);
} 
