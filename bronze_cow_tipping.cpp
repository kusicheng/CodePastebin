#include <iostream>
using namespace std;
char a[101][101];
int main(){
    int n,ans=0;
    freopen("cowtip.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>a[i][j];
    fclose(stdin);
    for (int i=n-1;i>=0;i--){
        for (int j=n-1;j>=0;j--){
            if (a[i][j]=='1'){
                for (int row=0;row<=i;row++){
                    for (int col=0;col<=j;col++){
                        if (a[row][col]=='1')a[row][col]='0';
                        else a[row][col]='1';
                    }
                }
                ans++;
            }
        }
    }
    freopen("cowtip.out","w",stdout);
    cout<<ans<<endl;
    fclose(stdout);
}
