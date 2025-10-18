#include <iostream>
#define ll long long
using namespace std;
ll a[100001][2];
int main(){
    ll devnum,days,n,b;
    cin>>devnum>>days;
    for (int i=0;i<devnum;i++){
        cin>>a[i][0]>>a[i][1];
    }
    if (devnum==1){
        cout<<min(days-a[0][0],a[0][1]);
        return 0;
    }
    ll stored=0,ans=0;
    for (int i=0;i<devnum;i++){
        if (i==0)
            stored+=a[i][1];
        else {
            ll eat=min(a[i][0]-a[i-1][0],stored);
            ans+=eat;
            stored-=eat;
            stored+=a[i][1];
        }
    }
    ans+=min(days-a[devnum-1][0]+1,stored);
    cout<<ans<<endl;
}
