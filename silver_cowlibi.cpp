#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct graze{
	long long x,y,t;
};
int g,alib,cx,cy,ct,ans;
bool cmp(graze a,graze b){
	return a.t<b.t;
}
int ubound(vector<graze> arr, int N, int X)//x is time, n is length
{
    int mid;
    int low = 0;
    int high = N;
    while (low < high) {
        mid = low + (high - low)>>1;
        if (X >= arr[mid].t) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low;
}
int main(){
	cin>>g>>alib;
	vector<graze> grazed(g);
	for (int i=0;i<g;i++)cin>>grazed[i].x>>grazed[i].y>>grazed[i].t;
	sort(grazed.begin(),grazed.end(),cmp);
	for (int i=0;i<alib;i++){
		cin>>cx>>cy>>ct;
		int idx=ubound(grazed,g-1,ct);
		//cout<<idx<<endl; 
		if (idx==0){
			if ((grazed[idx].x-cx)*(grazed[idx].x-cx)+(grazed[idx].y-cy)*(grazed[idx].y-cy)<=(grazed[idx].t-ct)*(grazed[idx].t-ct))ans++;
			continue;
		}
		if ((grazed[idx-1].x-cx)*(grazed[idx-1].x-cx)+(grazed[idx-1].y-cy)*(grazed[idx-1].y-cy)<=(grazed[idx-1].t-ct)*(grazed[idx-1].t-ct)&&
		(grazed[idx].x-cx)*(grazed[idx].x-cx)+(grazed[idx].y-cy)*(grazed[idx].y-cy)<=(grazed[idx].t-ct)*(grazed[idx].t-ct))
			ans++;
	}
	cout<<ans<<endl;
}
