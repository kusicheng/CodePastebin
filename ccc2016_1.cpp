#include <string>
#include <iostream>
using namespace std;
string a,b;
int ba[26],bb[26],cards;
int main(){
    cin>>a>>b;
    for (int i=0;i<a.length();i++)ba[a[i]-'a']++;
    for (int i=0;i<b.length();i++){
        if ('a'<=b[i]&&b[i]<='z')
            bb[b[i]-'a']++;
        else cards++;
    }
    if (a.length()!=b.length()){
        cout<<"N"<<endl;
        return 0;
    }
    for (int i=0;i<26;i++){
        if (bb[i]>ba[i]){
            cout<<"N"<<endl;
            return false;
        }
        cards-=ba[i]-bb[i];
    }
    if (left>=0){
        cout<<"A"<<endl;
    }
    else{
        cout<<"N"<<endl;
    }
}
