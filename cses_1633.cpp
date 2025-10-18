#include <iostream>
using namespace std;
int n;
int a[1000005];
int main(){
    cin>>n;
    a[0]=1;
    for (int i=1;i<=n;i++){
        for (int q=i-6;q<i;q++){
            (q>=0)?a[i]+=a[q]:a[i]+=0;
            a[i]%=1000000007;
        }
    }
    cout<<a[n]<<endl;    return 0;
}