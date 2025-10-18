#include <iostream>
using namespace std;
long long n,swift[100005],sema[100005];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){cin>>swift[i];swift[i]+=swift[i-1];}
    for (int i=1;i<=n;i++){cin>>sema[i];sema[i]+=sema[i-1];}
    for (int i=n;i>=1;i--){
        if (swift[i]==sema[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
}
