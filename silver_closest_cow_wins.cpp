#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
pair<int,int> grass[200005];//first is position,second is tastiness
fcow[200005];
int g,n,j;
int main(){
    cin>>g>>n>>j;
    for (int i=0;i<g;i++)cin>>grass[i].first>>grass[i].second;
    sort(grass,grass+g);
    for (int i=0;i<n;i++)cin>>fcow[i];
    sort(fcow,fcow+n);
}
