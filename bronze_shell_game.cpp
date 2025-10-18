#include <iostream>
using namespace std;
int swaps[101][2],guess[101],n,a,b,g;
int max(int a,int b){
    return (a>b)?a:b;
}
int calc(int s){
    int ans=0;
    for (int i=1;i<=n;i++){
        if (swaps[i][0]==s)s=swaps[i][1];
        else if (swaps[i][1]==s)s=swaps[i][0];
        if (s==guess[i])ans++;
    }
    return ans;
}
int main(){
    freopen("shell.in","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>swaps[i][0]>>swaps[i][1]>>guess[i];
    }
    fclose(stdin);
    freopen("shell.out","w",stdout);
    cout<<max(calc(1),max(calc(2),calc(3)));
    fclose(stdout);
}
