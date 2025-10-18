#include <iostream>
using namespace std;
char m[51][51];
int n,k,ans;
int check(int type,int l,int r,int num){
    if (type){
        for (int i=l;i<=r;i++){
            if (m[num][i]=='H')
                return 0;
        }
        return 1;
    }
    for (int i=l;i<=r;i++){
        if (m[i][num]=='H')
            return 0;
    }
    return 1;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>n>>k;
        ans=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin>>m[i][j];
        if (k>=1){
            int f1=1,f2=1;
            for (int i=0;i<n;i++){
                if (m[0][i]=='H'&&f1||m[i][n-1]=='H'&&f1){
                    ans--;
                    f1=0;
                }
                if (m[i][0]=='H'&&f2||m[n-1][i]=='H'&&f2){
                    ans--;
                    f2=0;
                }
            }
            ans+=2;
        }//0=column 1=row
        if (k>=2){
            for (int select=0;select<n;select++){
                if (check(1,0,n-1,select)&&check(0,0,select,0)&&check(0,select,n-1,n-1)){
                    ans++;
                }
                if (check(0,0,n-1,select)&&check(1,0,select,0)&&check(1,select,n-1,n-1)){
                    ans++;
                }
            }
        }
        if (k>=3){
            for (int row=0;row<n;row++){
                for (int col=0;col<n;col++){
                    if (check(0,0,row,0)&&check(1,0,col,row)&&check(0,row,n-1,col)&&check(1,col,n-1,n-1)){
                        ans++;
                    }
                    if (check(1,0,row,0)&&check(0,0,col,row)&&check(1,row,n-1,col)&&check(0,col,n-1,n-1)){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
