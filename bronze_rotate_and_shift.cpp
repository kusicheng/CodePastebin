#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
int pos[200002];
int ans[200002];
int main(){
    ll n,k,t,m;
    cin>>n>>k>>t;
    for (int i=0;i<k;i++){
        cin>>pos[i];
    }
    pos[k]=pos[0]+n;
    for (int i=0;i<k;i++){
        //cout<<pos[i]<<" "<<pos[i+1]<<endl;
        for (int val=pos[i];val<pos[i+1];val++){
            ll moved=pos[i+1]-pos[i];
            ll diff=val-pos[i];
            ll didmove=ceil((double) (t-diff)/(double)moved)*moved;
            ll finalpos=(val+didmove)%n;
            ans[finalpos]=val;
        }
    }
    for (int i=0;i<n-1;i++)cout<<ans[i]<<" ";
    cout<<ans[n-1];
    cout<<endl;
}
