#include <iostream>
#include <vector>
#define INT_MAX 2147483647
using namespace std;
struct node{
    int reward;
    int edge;
    //vector<int> edge;
};
int n,e;
long long ans;
node farms[100005];
vector<vector<int>> child(100005);
bool done[100005];
void mark_as_done(int x) {
	if (done[x]) return;
	done[x] = true;
	for (int c : child[x]) mark_as_done(c);
}
int solve(int start) {
	int x = start, y = start;
	do {
		x = farms[x].edge, y = farms[farms[y].edge].edge;
	} while (x != y);
	int min_along_cycle = INT_MAX;
	do {
		min_along_cycle = min(min_along_cycle, farms[x].reward);
		x = farms[x].edge;
	} while (x != y);
	mark_as_done(x);
	return min_along_cycle;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>farms[i].edge>>farms[i].reward;
        ans+=farms[i].reward;
        child[farms[i].edge].push_back(i);
        //farms[e].edge.push_back(i);
    }
    for (int i=0;i<n;i++){
        if (!done[i])ans-=solve(i);
    }
    cout<<ans<<endl;
}
