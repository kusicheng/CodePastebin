#include <iostream>
#include <string>
using namespace std;
string s;
int n;
int main(){
    cin>>n>>s;
    //elimination of first F chain
    int FstartN=0;
    while (s[FstartN]=='F'&&FstartN<n)
        FstartN++;
    int FendN=0;
    while (s[n-FendN-1]=='F'&&FendN<n)
        FendN++;
    if (FstartN==n){
        cout<<n<<endl;
        for (int i=0;i<n;i++)cout<<i<<endl;
        return 0;
    }
    int minx=0,maxx=0;
    int idx=FstartN;
    while (idx<n){
        int next=idx+1;
        while (s[next]=='F'&&next<n)
            next++;
        if (next==n)break;
        if (s[idx]==s[next]){
            if ((next-idx+1)%2==0)
                minx++;
            maxx+=next-idx;
        }
        else {
            if ((next-idx+1)%2!=0)
                minx++;
            maxx+=next-idx-1;
        }
        idx=next;
    }
    if (FstartN==0&&FendN==0){
        cout<<(maxx-minx)/2+1<<endl;
        for (int i=minx;i<=maxx;i+=2)
            cout<<i<<endl;
    }
    else{
        maxx+=FstartN+FendN;
        cout<<maxx-minx+1<<endl;
        for (int i=minx;i<=maxx;i++)
            cout<<i<<endl;
    }
}
