#include <iostream>
#include <algorithm>
using namespace std;
int n,t,a[100001];
int main(){
    cin>>t;
    for (int l=0;l<t;l++){
        cin>>n;
        int ans=0,calctomin=2147483647;
        for (int i=0;i<n;i++)cin>>a[i];
        for (int i=1;i<n;i++){
            if (i+1<n){
                int dx=max(a[i]-a[i-1],0);
                a[i+1]-=dx;
                a[i]-=dx;
                ans+=2*dx;
            }
        }
        reverse(a,a+n);
        for (int i=1;i<n;i++){
            if (i+1<n){
                int dx=max(a[i]-a[i-1],0);
                a[i+1]-=dx;
                a[i]-=dx;
                ans+=2*dx;
            }
            calctomin=min(calctomin,a[i]);
        }
        if (calctomin<0||a[n-1]>a[n-2])
            cout<<"-1"<<endl;
        else{
            for (int i=0;i<n;i++)
                ans+=a[i]-calctomin;
            cout<<ans<<endl;
        }
    }
}
