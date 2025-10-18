#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll n,q,a[150005],pos,dx;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    cin>>q;
    while (q--){
        cin>>pos>>dx;
        int og=a[pos];
        a[pos]=dx;

        for (int i=1;i<=n;i++)a[i]=a[i]+a[i-1];
    }
}
