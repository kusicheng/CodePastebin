#include <iostream>
#include <string>
#include <vector>
using namespace std;
int a[100005][52],mark[52],l,r=1,ans=100005;
vector<int> check;
int main(){
	int n;
	string s;
	cin>>n>>s;
	for (int i=1;i<=n;i++){
		for (int x=0;x<52;x++)a[i][x]=a[i-1][x];
		if ('A'<=s[i-1]&&s[i-1]<='Z'){
			mark[s[i-1]-'A']=1;
			a[i][s[i-1]-'A']++;
		}
		else{
			mark[s[i-1]-'a'+26]=1;
			a[i][s[i-1]-'a'+26]++;
		}
	}
	for (int i=0;i<52;i++)if (mark[i])check.push_back(i);
	while (r<=n&&l<=r){
		int flag=1;
		for (int idx:check){
			if (a[r][idx]-a[l][idx]<=0){
				flag=0;
				r++;break;
			}
		}
		if (flag){
			ans=min(ans,r-l);
			l++;
		}
	}
	cout<<ans<<endl;
} 
