#include <iostream>
#include <queue>
using namespace std;
pair<int,int> cows[1005];
int n;
bool visited[1005];
void bfs(int maxed){
	queue<pair<int,int> > q;
	q.push(cows[0]);
	visited[0]=1;
	while (q.size()){
		int x=q.front().first;
		int y=q.front().second;
		for (int i=0;i<n;i++)
			if (!visited[i]&&(cows[i].first-x)*(cows[i].first-x)+(cows[i].second-y)*(cows[i].second-y)<=maxed){
				visited[i]=1;
				q.push(cows[i]);
			}
		q.pop();
	}
}
bool check(int x){
	for (int i=0;i<n;i++)visited[i]=0;
	bfs(x);
	for (int i=0;i<n;i++)if (!visited[i])return false;
	return true;
}
int main(){
	freopen("moocast.in","r",stdin);
	cin>>n;
	for (int i=0;i<n;i++)cin>>cows[i].first>>cows[i].second;
	fclose(stdin);
	int l=1,r=2147483647,mid;
	while (l<r){
		mid=(l+r)>>1;
		check(mid)?r=mid:l=mid+1;
	}
	freopen("moocast.out","w",stdout);
	cout<<r<<endl;
	fclose(stdout);
}
