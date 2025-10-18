#include <iostream>
#include <algorithm>
using namespace std;
int b1,b2,target;
int findb(int total){
    if (total+b1<=target&&total+b2<=target){
        return max(findb(total+b1),findb(total+b2));
    }
    else if (total+b1<=target)return findb(total+b1);
    else if (total+b2<=target)return findb(total+b2);
    return total;
}
int main(){
    freopen("pails.in","r",stdin);
    cin>>b1>>b2>>target;
    fclose(stdin);
    freopen("pails.out","w",stdout);
    cout<<findb(0)<<endl;
    fclose(stdout);
}
