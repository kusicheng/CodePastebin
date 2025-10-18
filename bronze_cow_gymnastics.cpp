#include <iostream>
using namespace std;
int a[11][21];
int row,col;
bool check(int c,int b){
    for (int i=0;i<row;i++){
        int f1=0,f2=0;
        for (int j=0;j<col;j++){
            if (a[i][j]==c)f1=j;
            else if (a[i][j]==b)f2=j;
        }
        if (f1>f2)return false;
    }
    return true;
}
int main(){
    int ans=0;
    freopen("gymnastics.in","r",stdin);
    cin>>row>>col;
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
    fclose(stdin);
    for (int c=0;c<col;c++){
        for (int b=0;b<col;b++){
            if (check(a[0][c],a[0][b])&&c!=b){
                ans++;
            }
        }
    }
    freopen("gymnastics.out","w",stdout);
    cout<<ans<<endl;
    fclose(stdout);
}
