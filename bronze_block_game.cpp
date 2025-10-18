#include <iostream>
#include <algorithm>
using namespace std;
string a[101][2];
int n;
int countwords(char n, int lim){
    int ans=0;
    for (int i=0;i<lim;i++){
        ans+=max(count(a[i][0].begin(),a[i][0].end(),n),count(a[i][1].begin(),a[i][1].end(),n));
    }
    return ans;
}
int main(){
    freopen("blocks.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i][0]>>a[i][1];
    freopen("blocks.out","w",stdout);
    for (int i=0;i<26;i++){
        cout<<countwords('a'+i,n)<<endl;;
    }
    fclose(stdin);
    fclose(stdout);
}
