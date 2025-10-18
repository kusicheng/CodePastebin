#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct cow {
    int d,dt;
    string name;
} a[101];
bool cmp(cow a,cow b){
    return a.d<b.d;
}
int max(int a,int b){
    return (a>b)?a:b;
}
string prevpic="111";
string nowpic;

int main(){
    int c1=7,c2=7,c3=7;
    int n,ans=0,f;
    freopen("measurement.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i].d>>a[i].name>>a[i].dt;
    fclose(stdin);
    sort (a,a+n,cmp);
    for (int i=0;i<n;i++){
        char m=a[i].name[0];
        switch (m){
            case 'B':c1+=a[i].dt;break;
            case 'E':c2+=a[i].dt;break;
            default:c3+=a[i].dt;
        }
        int cmax=max(c1,max(c2,c3));
        if (c1==cmax)nowpic+="1";else nowpic+="0";
        if (c2==cmax)nowpic+="1";else nowpic+="0";
        if (c3==cmax)nowpic+="1";else nowpic+="0";
        if (nowpic.compare(prevpic))ans++;
        prevpic=nowpic;
        nowpic="";
    }
    freopen("measurement.out","w",stdout);
    cout<<ans<<endl;
    fclose(stdout);
}
