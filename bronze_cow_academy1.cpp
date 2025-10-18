#include <iostream>
#include <algorithm>
using namespace std;
int a[100001],n,addn;
int check(){
    for (int i=0;i<n;i++){
        if (a[i]>=n-i)return i;
    }
    return n-1;
}
int main(){
    //freopen("13.in","r",stdin);
    cin>>n>>addn;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    //fclose(stdin);
    sort(a,a+n);
    //for (int x:a)cout<<x<<" ";
    int findidx=check();
    for (int i=findidx+1;i>=findidx-addn+2&&i>=0;i--)a[i]++;
    cout<<n-check()<<endl;
}
