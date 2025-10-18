//cses.fi/problemset/task/1629
#include <iostream>
#include <algorithm>
#define f first
#define s second
#define ll long long
using namespace std;
ll n,si,ei;
pair<ll,ll> a[200005];
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    return x.s<y.s;
}
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i].f>>a[i].s;
    }
    sort(a,a+n,cmp);
    ll watched=0,lastend=0;
    for (int i=0;i<n;i++){
        if (a[i].first>=lastend){
            lastend=a[i].second;
            watched++;
        }
    }
    cout<<watched<<endl;
}
