#include <iostream>
#include <string>
using namespace std;
int input[101][101],output[101];
int t,n,m;
char s;
bool check(){
    for (int i=0;i<m;i++)
        if (output[i]!=-1)
            return false;
    return true;
}
int main(){
    cin>>t;
    for (int l=0;l<t;l++){
        cin>>n>>m;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                cin>>s;
                input[i][j]=s-'0';
            }
            cin>>output[i];
        }
        int select=0;
        while (true){
            int find1=-1;
            bool good=true;
            for (int i=0;i<m;i++){
                if (output[i]!=-1){
                    if (input[i][select]==1){
                        if (find1==-1)
                            find1=output[i];
                        else {
                            if (find1!=output[i]){
                                good=false;
                                break;
                            }
                        }
                    }
                }
            }
            if (good&&find1!=-1){
                //cout<<"good for 1 at "<<select<<endl;
                for (int i=0;i<m;i++)
                    if (input[i][select]==1)
                        output[i]=-1;
                select=0;
                continue;
            }
            find1=-1;
            good=true;
            for (int i=0;i<m;i++){
                if (output[i]!=-1){
                    if (input[i][select]==0){
                        if (find1==-1)
                            find1=output[i];
                        else {
                            if (find1!=output[i]){
                                good=false;
                                break;
                            }
                        }
                    }
                }
            }
            if (good&&find1!=-1){
                //cout<<"good for 0 at "<<select<<endl;
                for (int i=0;i<m;i++)
                    if (input[i][select]==0)
                        output[i]=-1;
                select=0;
                continue;
            }
            //for (int i=0;i<m;i++)cout<<output[i]<<" ";
            //cout<<select<<endl;
            if (select==n-1&&!check()){
                cout<<"LIE\n";
                break;
            }
            else if (select==n-1&&check()){
                cout<<"OK\n";
                break;
            }
            select++;
        }
    }
}
