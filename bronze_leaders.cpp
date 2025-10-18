#include <iostream>
using namespace std;
char cows[100002];
int ranges[100002],dh,dg,n,cnt;
int leaderh=-1,leaderg=-1;
int main(){
    int lead1=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>cows[i];
        if (cows[i]=='G')dg++;
        else dh++;
    }
    for (int i=1;i<=n;i++)
        cin>>ranges[i];
    //test for if cow g is leader who has list of all their cows
    for (int i=1;i<=n;i++){
        if (cows[i]=='G'){
            for (int m=i;m<=ranges[i];m++){
                if (cows[m]=='G')
                    cnt++;
            }
            if (cnt==dg){
                leaderg=i;
            }
            break;
        }
    }
    //second case, where h has a leader
    cnt=0;
    for (int i=1;i<=n;i++){
        if (cows[i]=='H'){
            for (int m=i;m<=ranges[i];m++){
                if (cows[m]=='H')
                    cnt++;
            }
            if (cnt==dh){
                leaderh=i;
            }
            break;
        }
    }
    //cout<<leaderh<<" "<<leaderg<<endl;
    int ans=0;
    //assume the leader is the g cow, if it exists, then we count all pair of cows that have lists including cow g leader
    for (int i=1;i<leaderg;i++){
        if (cows[i]=='H'){
            if (ranges[i]>=leaderg&&i!=leaderh){
                ans++;
            }
        }
    }
    //assume the leader is the h cow, if it exists, then we count all pair of cows that have lists including cow h leader
    for (int i=1;i<leaderh;i++){
        if (cows[i]=='G'){
            if (ranges[i]>=leaderh&&i!=leaderg){
                ans++;
            }
        }
    }
    //what if we have two leaders? we add it back.
    if (leaderg!=-1&&leaderh!=-1)ans++;
    cout<<ans<<endl;
}
