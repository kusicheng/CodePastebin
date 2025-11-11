#include <iostream>
#include <vector>
using namespace std;
void solve(int a,int b){
    int a_msb=31-__builtin_clz(a),b_msb=31-__builtin_clz(b);
    if (a_msb<b_msb){
        cout<<-1<<endl;
        return;
    }
    if (a==b){
        cout<<0<<endl;
        return;
    }
    if (a_msb==b_msb){
        cout<<1<<endl<<((a-(1<<a_msb))^(b-(1<<b_msb)))<<endl;
        return;
    }
    cout<<2<<endl<<((a-(1<<a_msb))^b)<<" "<<(1<<a_msb)<<endl;
    return;
}
int main(){
    int T;cin>>T;
    while (T--){
        int a,b;cin>>a>>b;
        solve(a,b);
    }
}