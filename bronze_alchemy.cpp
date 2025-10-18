#include <iostream>
#include <vector>
using namespace std;
int m[102];
vector<int> recipes[101];
int mats[102];
int main(){
    int n,k;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>m[i];
    cin>>k;
    for (int i=0;i<k;i++){
        int res,inum,ing;
        cin>>res>>inum;
        for (int j=0;j<inum;j++){
            cin>>ing;
            recipes[res].push_back(ing);
        }
    }
    int ans=0;
    while(true) {
        vector<int> mats(n+1);
        mats[n]++;
        bool flag=true;
        for(int i=n;i>=1;i--) {
            if(mats[i]<=m[i]) {
                m[i]-=mats[i];
                continue;
            }
            if(!recipes[i].size()) {
                flag=false;
                break;
            }
            int dx=min(mats[i],m[i]);
            mats[i]-=dx;
            m[i]-=dx;
            for(int x:recipes[i])mats[x]+=mats[i];
        }
        if(flag)ans++;
        else break;
  }
  cout<<ans<<endl;
}
