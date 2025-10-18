#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int stalls[101];
int aircon[10][4];
int checkstalls[101];
int ans=2147483647;
int n,m,cow1,cow2,dcool,maxstall=0;
int check(){
    for (int i=0;i<101;i++){
        if (stalls[i]>checkstalls[i])
            return 0;
    }
    return 1;
}
int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>cow1>>cow2>>dcool;
        maxstall=max(maxstall,max(cow1,cow2));
        for (int j=cow1;j<=cow2;j++)stalls[j]=dcool;
    }
    for (int i=0;i<m;i++){
        cin>>aircon[i][0]>>aircon[i][1]>>aircon[i][2]>>aircon[i][3];//lhs,rhs,cool amount,cost
    }
    int l=pow(2,m);
	for (int i=0;i<l;i++){
        int idx=0;
        int costloop=0;
        int di=i;
        while (di){
            if (di%2){
                for (int x=aircon[idx][0];x<=aircon[idx][1];x++){
                    checkstalls[x]+=aircon[idx][2];
                    //cout<<checkstalls[x]<<endl;
                }
                costloop+=aircon[idx][3];
            }
            idx++;
            di/=2;
        }
        if (check()){
            ans=min(ans,costloop);
        }
        //for (int x=0;x<maxstall;x++){
        //    cout<<checkstalls[x]<<" "<<stalls[x]<<endl;
        //}
        //cout<<endl;
        for (int x=0;x<101;x++)checkstalls[x]=0;
	}
	cout<<ans<<endl;
}
