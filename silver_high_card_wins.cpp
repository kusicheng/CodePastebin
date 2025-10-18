#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define LL_MAX 9223372036854775807
#define F first
#define S second
#define UNS using namespace std;
#define P pair<int,int>
#define v(l) vector<l>
UNS
v(ll) a(50005),b(50005);
int main(){
    for (int i=0;i<50005;i++){
        a[i]=LL_MAX;b[i]=LL_MAX;
    }
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>b[i];
    sort(b.begin(),b.end());
    int bd=0,ad=0;
    for (int i=1;i<=2*n;i++){
        if (b[bd]==i)bd++;
        else {
            a[ad]=i;
            ad++;
        }
    }
    int win=0;
    for (int i=0;i<n;i++){
        auto ub=upper_bound(a.begin(),a.end(),b[i]);
        if (ub!=a.end()){
            a[ub-a.begin()]=-1;
            win++;
        }
    }
    cout<<win<<endl;
}
