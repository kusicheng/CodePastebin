#include <bits/stdc++.h>
using namespace std;
int n,all[100];
vector<int> low,high;
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>all[i];
    sort(all+1,all+n+1);
    if (n&1){
        int div=(n+1)/2;
        cout<<all[div]<<" ";
        for (int i=1;i<div-1;i++){
            cout<<all[div+i]<<" "<<all[div-1]<<" ";
        }
        cout<<all[1]<<" "<<all[n];
    }
    else {
        int div=n/2;
        cout<<all[div]<<" ";
        for (int i=1;i<div;i++){
            cout<<all[div+i]<<" "<<all[div-i]<<" ";
        }
        cout<<all[n];
    }
}
