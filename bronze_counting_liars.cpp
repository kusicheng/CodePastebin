#include <iostream>
#include <algorithm>
using namespace std;
int n,idx,ans=2147483647;
char op;
pair<char,int> a[1001];
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    for (int i=0;i<n;i++){
        int assume=a[i].second;
        int t=0;
        for (int j=0;j<n;j++){
            if (a[j].first=='L'&&a[j].second<assume||a[j].first=='G'&&a[j].second>assume)t++;
        }
        ans=min(ans,t);
    }
    cout<<ans<<endl;
}
