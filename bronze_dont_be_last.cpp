#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string,int> a;
string arr[7]={"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
int main(){
    int n,l=2147483647,l2=2147483647,p=0;
    int id;
    string name;
    for (int i=0;i<7;i++)a[arr[i]]=0;
    freopen("notlast.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>name>>id;
        a[name]+=id;
    }
    fclose(stdin);
    for (auto x:a){
        l=min(l,x.second);
    }
    for (auto x:a){
        if (x.second!=l)
            l2=min(l2,x.second);
    }
    for (auto x:a){
        if (x.second==l2)p++;
    }
    freopen("notlast.out","w",stdout);
    if (p>1||l2==2147483647){
        cout<<"Tie\n";
        fclose(stdout);
        return 0;
    }
    for (auto x:a){
        if (x.second==l2){
            cout<<x.first<<endl;
            fclose(stdout);
            return 0;
        }
    }
    fclose(stdout);
}
