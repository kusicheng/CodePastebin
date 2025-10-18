#include <iostream>
#include <string>
using namespace std;
string s;
char ans[100001];
int n,dn;
void memset(){
    for (int i=0;i<100000;i++)ans[i]='.';
}
int main(){
    int t;
    cin>>t;
    for (int l=0;l<t;l++){
        memset();
        cin>>n>>dn>>s;
        int h=-dn-1,g=-dn-1,cnt=0;
        for (int i=0;i<n;i++){
            if (s[i]=='G'){
                if (i-g>dn){
                    int idx=i+dn;
                    if (i+dn>=n){
                        idx=n-1;
                        while (ans[idx]!='.'&&ans[idx]!='G')idx--;
                        ans[idx]='G';
                    }
                    else {
                        while (ans[idx]!='.'&&ans[idx]!='G')idx--;
                        ans[idx]='G';
                    }
                    g=idx;
                    cnt++;
                }
            }
            else {
                if (i-h>dn){
                    int idx=i+dn;
                    if (i+dn>=n){
                        idx=n-1;
                        while (ans[idx]!='.'&&ans[idx]!='H')idx--;
                        ans[idx]='H';
                    }
                    else {
                        while (ans[idx]!='.'&&ans[idx]!='H')idx--;
                        ans[idx]='H';
                    }
                    h=idx;
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        for (int i=0;i<n;i++)cout<<ans[i];
        cout<<endl;
    }
}
