#include <iostream>
#include <string>
using namespace std;
int n;
string s;
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>s;
        int lim=s.length();
        int dir=s[0];
        int l=0,r=0;
        for (int i=1;i<lim;i++){
            if (s[i]=='N'&&dir=='W'||s[i]=='E'&&dir=='N'||s[i]=='S'&&dir=='E'||s[i]=='W'&&dir=='S')
                r++;
            else if (s[i]!=dir)
                l++;
            dir=s[i];
        }
        if (r>l)cout<<"CW"<<endl;
        else cout<<"CCW"<<endl;
    }
}
