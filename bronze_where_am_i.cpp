#include <iostream>
#include <string>
using namespace std;
string a;int n;
bool check(int l){
    for (int i=0;i<n-l;i++){
        string t=a.substr(i,l);
        for (int idx=i+1;idx<n-l+1;idx++)
            if (!t.compare(a.substr(idx,l)))
                return false;
    }
    return true;
}
int main(){
    freopen("whereami.in","r",stdin);
    cin>>n;
    cin>>a;
    fclose(stdin);
    freopen("whereami.out","w",stdout);
    for (int i=2;i<n;i++){
        if (check(i)){
            cout<<i<<endl;
            fclose(stdout);
            return 0;
        }
    }
    cout<<n<<endl;
    fclose(stdout);
}
