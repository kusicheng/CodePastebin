#include <string>
#include <iostream>
using namespace std;
string s;
int n;
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>s;
        if (s.find("MOO")!=string::npos){
            cout<<s.length()-3<<endl;
        }
        else if (s.find("MOM")!=string::npos||s.find("OOO")!=string::npos){
            cout<<s.length()-2<<endl;
        }
        else if (s.find("OOM")!=string::npos){
            cout<<s.length()-1<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
}
