#include <iostream>
#include <algorithm>
using namespace std;
int c1[105],c2[105],ans;
int main(){
    int t;
    cin>>t;
    if (t==1){//minimize total speed
        cin>>t;
        for (int i=0;i<t;i++)cin>>c1[i];
        for (int i=0;i<t;i++)cin>>c2[i];
        sort(c1,c1+t);
        sort(c2,c2+t);
        for (int i=0;i<t;i++)ans+=max(c1[i],c2[i]);
        cout<<ans<<endl;
    }
    else {
        cin>>t;
        for (int i=0;i<t;i++)cin>>c1[i];
        for (int i=0;i<t;i++)cin>>c2[i];
        sort(c1,c1+t);
        sort(c2,c2+t);
        for (int i=0;i<t;i++){
            //cout<<c1[i]<<" "<<c2[i]<<endl;v
            ans+=max(c1[i],c2[t-i-1]);
        }
        cout<<ans<<endl;
    }
}
