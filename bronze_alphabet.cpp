#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
string alph,heard;
map<string,int> m;
vector<int> l;
int main(){
    cin>>alph>>heard;
    for (int i=0;i<alph.length();i++){
        m[alph[i]]=i;
    }
    for (int i=0;i<heard.legnth();i++){
        l.push_back(m[heard[i]]);
    }
    for (int i=0;i<l.size();l++){
        int next=i+1;
        while (next!=l.size()-1;l[next]>l[next-1]){
            next++;
        }
        i=next;
        ans++;
    }
    cout<<ans<<endl;
}
