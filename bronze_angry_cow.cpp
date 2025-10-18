#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll a[101];
int n;
int expplus(int idx, int sizeo, int ans){
    if (idx>=n)return ans;
    if (a[idx+1]-a[idx]<=sizeo)
        return expplus(idx+1,sizeo+1,ans+1);
    return ans;
}
int expminus(int idx, int sizeo,int ans){
    if (idx<=0)return ans;
    if (a[idx]-a[idx-1]<=sizeo)
        return expminus(idx-1,sizeo+1,ans+1);
    return ans;
}
int main(){
    int ans=0;
    //freopen("angry.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    //fclose(stdin);
    sort(a,a+n);
    for (int i=0;i<n;i++){
        int tempans=1;
        if (i==0)if(a[1]-a[0]==1)tempans+=expplus(i+1,1,0);
        else if (i==n-1)if(a[n-1]-a[n-2]==1)tempans+=expminus(i-1,1,0);
        else{
            if (a[i+1]-a[i]==1)tempans+=expplus(i+1,1,0);
            if (a[i]-a[i-1]==1)tempans+=expminus(i-1,1,0);
        }
        ans=max(ans,tempans);
    }
    //freopen("angry.out","w",stdout);
    cout<<ans;
    //fclose(stdout);
}
