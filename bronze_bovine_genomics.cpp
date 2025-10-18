#include <iostream>
using namespace std;
char spotty[101][101],plain[101][101];
int n,l;
int check(int col){
    int spottycol[4]={0,0,0,0},plaincol[4]={0,0,0,0};
    for (int i=0;i<n;i++){
        char m=spotty[i][col];
        switch (m){
            case 'A':spottycol[0]=1;break;
            case 'C':spottycol[1]=1;break;
            case 'G':spottycol[2]=1;break;
            case 'T':spottycol[3]=1;break;
        }
    }
    for (int i=0;i<n;i++){
        char m=plain[i][col];
        switch (m){
            case 'A':plaincol[0]=1;break;
            case 'C':plaincol[1]=1;break;
            case 'G':plaincol[2]=1;break;
            case 'T':plaincol[3]=1;break;
        }
    }
    for (int i=0;i<4;i++)if (spottycol[i]&&plaincol[i])return false;
    return true;
}
int main(){
    int ans=0;
    freopen("cownomics.in","r",stdin);
    cin>>n>>l;
    for (int i=0;i<n;i++)for (int j=0;j<l;j++)cin>>spotty[i][j];
    for (int i=0;i<n;i++)for (int j=0;j<l;j++)cin>>plain[i][j];
    fclose(stdin);
    for (int col=0;col<l;col++){
        if (check(col))ans++;
    }
    freopen("cownomics.out","w",stdout);
    cout<<ans<<endl;
    fclose(stdout);
}
