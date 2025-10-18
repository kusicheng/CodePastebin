#include <iostream>
#include <string>
using namespace std;
char stamp[21][21],pic[21][21],stamped[21][21],stamp2[21][21];
int n,dimp,dims;
int stampxy(int row,int col){
    for (int i=0;i<dims;i++)
        for (int j=0;j<dims;j++)
            if (pic[i+row][j+col]=='.'&&stamp[i][j]=='*')return 0;
    return 1;
}
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        for (int z=0;z<21;z++)
            for (int x=0;x<21;x++)
                stamped[z][x]='.';
        cin>>dimp;
        for (int j=0;j<dimp;j++)
            for (int jy=0;jy<dimp;jy++)
                cin>>pic[j][jy];
        cin>>dims;
        for (int j=0;j<dims;j++)
            for (int jy=0;jy<dims;jy++)
                cin>>stamp[j][jy];
        for (int l=0;l<4;l++){
            for (int m=0;m<=dimp-dims;m++){
                for (int j=0;j<=dimp-dims;j++){
                    if (stampxy(m,j)){
                        //printf("stamped at %d,%d\n",m,j);
                        for (int row=0;row<dims;row++){
                            for (int col=0;col<dims;col++){
                                if (stamp[row][col]=='*')
                                    stamped[row+m][col+j]=stamp[row][col];
                            }
                        }
                    }
                }
            }

            for (int l=0;l<dims;l++){
                for (int j=0;j<dims;j++){
                    stamp2[j][dims-l-1]=stamp[l][j];
                }
            }

            for (int l=0;l<dims;l++){
                for (int j=0;j<dims;j++){
                    stamp[l][j]=stamp2[l][j];
                }
            }
        }
        int f=1;
        for (int l=0;l<dimp;l++){
            for (int j=0;j<dimp;j++){
                //cout<<stamped[l][j];
                if (pic[l][j]!=stamped[l][j]&&f){
                    f=0;
                    cout<<"NO"<<endl;
                }
            }
            //cout<<endl;
        }
        if (f)cout<<"YES"<<endl;
    }
}
