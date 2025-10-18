#include <iostream>
#include <vector>
using namespace std;
int a[100005],n,mins[100005];
long double maxscore=-1;
vector<int> ans;
int main(){
	freopen("homework.in","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	mins[n+1]=2147483647;
	for (int i=n;i>=1;i--)
		mins[i]=min(a[i]-a[i-1],mins[i+1]);
	fclose(stdin);
	for (int k=1;k<=n-2;k++){
		long double av=float(a[n]-a[k]-mins[k])/float(n-k-1);
		if (av>maxscore){
			ans.clear();
			ans.push_back(k);
			maxscore=av;
		}
		else if (av==maxscore)
			ans.push_back(k);
	}
	freopen("homework.out","w",stdout);
	for (auto x:ans)cout<<x<<endl;
	fclose(stdout);
}
