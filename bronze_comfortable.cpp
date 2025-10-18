#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int a[1002][1002];
int cnt(int x,int y){
    int r=0;
    if (x>0&&a[x-1][y])
        r++;
    if (a[x+1][y])
        r++;
    if (y>0&&a[x][y-1])
        r++;
    if (a[x][y+1])
        r++;
    return r;
}
int main(){
    int t,x,y,val,out=0;
    cin>>t;
    memset(a,0,sizeof(a));
    vector<int>m;
    while (t--){
        cin>>x>>y;
        if (x>0&&a[x-1][y]){
            val=cnt(x-1,y);
            if (val==3)
                out--;
            else if (val==2)
                out++;
        }
        if (y>0&&a[x][y-1]){
            val=cnt(x,y-1);
            if (val==3)
                out--;
            else if (val==2)
                out++;
        }
        if (a[x+1][y]){
            val=cnt(x+1,y);
            if (val==3)
                out--;
            else if (val==2)
                out++;
        }
        if (a[x][y+1]){
            val=cnt(x,y+1);
            if (val==3)
                out--;
            else if (val==2)
                out++;
        }
        a[x][y]=1;
        m.push_back(out);
    }
    for (int x:m)cout<<x<<endl;
}
