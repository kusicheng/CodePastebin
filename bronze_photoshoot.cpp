#include <iostream>
#include <string>
using namespace std;
int n,ans;
string t,s;
int main(){
    cin>>n>>t;
    for (int i=0;i<n;i+=2){
        if (t[i]=='G'&&t[i+1]=='H')s+='a';
        else if (t[i]=='H'&&t[i+1]=='G')s+='b';
    }//max b
    int l=s.length()-1;
    int idx=0;
    while (l>=0){
        if (s[l]=='b'){
            l--;
            continue;
        }
        for (int i=0;i<=l;i++){
            if (s[i]=='a')s[i]='b';
            else s[i]='a';
        }
        //cout<<s<<endl;
        l--;
        ans++;
    }
    cout<<ans<<endl;
}
