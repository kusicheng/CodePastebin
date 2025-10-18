#include <iostream>
#include <string>
using namespace std;
struct s {
    string type;
    int lb,ub;
} lst[101];
int main(){
    int n,ub,lb;
    string type;
    freopen("traffic.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++)cin>>lst[i].type>>lst[i].lb>>lst[i].ub;
    fclose(stdin);
    int a=-999999,b=999999;
    for (int i=n-1;i>=0;i--){
        if (!lst[i].type.compare("none")){
            a=max(a,lst[i].lb);b=min(b,lst[i].ub);a=max(0,a);
        }
        else if (!lst[i].type.compare("on")){
            a-=lst[i].ub;b-=lst[i].lb;a=max(0,a);b=max(0,b);
        }
        else {
            a+=lst[i].lb;b+=lst[i].ub;
        }
    }
    freopen("traffic.out","w",stdout);
    cout<<a<<" "<<b<<endl;
    a=-999999,b=999999;
    for (int i=0;i<n;i++){
        if (!lst[i].type.compare("none")){
            a=max(a,lst[i].lb);b=min(b,lst[i].ub);a=max(0,a);
        }
        else if (!lst[i].type.compare("on")){
                a+=lst[i].lb;b+=lst[i].ub;
        }
        else {
            a-=lst[i].ub;b-=lst[i].lb;a=max(0,a);b=max(0,b);
        }
    }
    cout<<a<<" "<<b<<endl;
    fclose(stdout);
}
