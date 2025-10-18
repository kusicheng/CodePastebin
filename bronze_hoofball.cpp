#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[101];
vector<int> b[101];
int main(){
    int n;
    freopen("hoofball.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    fclose(stdin);
    sort(a,a+n);
    for (int i=0;i<n;i++){
        if (i==0)
            b[0].push_back(1);
        else if (i==n-1)
            b[i].push_back(i-1);
        else if (a[i]-a[i-1]<=a[i+1]-a[i])
            b[i].push_back(i-1);
        else b[i].push_back(i+1);
    }
    int balls=0;
    for (int i=0;i<n-1;i++){
        if (i==0){
            if (b[i+1][0]!=i)balls++;
        }
        else if (i==n-2){
            if (b[i-1][0]!=i&&b[i+1][0]!=i)balls++;
            if (b[i][0]!=i+1)balls++;
        }
        else if (b[i-1][0]!=i&&b[i+1][0]!=i){
            balls++;
        }
        if (i==0){
            if (b[i][0]==i+1&&b[i+1][0]==i&&b[i+2][0]!=i+1)balls++;
        }
        else if (i==n-2){
            if (b[i][0]==i+1&&b[i+1][0]==i&&b[i-1][0]!=i)balls++;
        }
        else {
            if (b[i][0]==i+1&&b[i+1][0]==i&&b[i-1][0]!=i&&b[i+2][0]!=i+1)balls++;
        }
    }
    freopen("hoofball.out","w",stdout);
    cout<<balls<<endl;
    fclose(stdout);
}
