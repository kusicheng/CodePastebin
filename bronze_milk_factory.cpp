#include <iostream>
#include <vector>
using namespace std;
vector<int> a[101];
int main(){
    int n,c,b;
    freopen("factory.in","r",stdin);
    cin>>n;
    for (int i=0;i<n-1;i++){
        cin>>b>>c;
        a[b].push_back(c);
    }
    fclose(stdin);
    int ct=0,ans;
    freopen("factory.out","w",stdout);
    for (int i=1;i<=n;i++){
        if (!a[i].size()){ct++;ans=i;}
    }
    if (ct==1)cout<<ans<<endl;
    else cout<<-1<<endl;
    fclose(stdout);
}
