#include <iostream>
#include <algorithm>
using namespace std;
int n,a[101],b[101],ans=-1;
int main(){
    freopen("outofplace.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    fclose(stdin);
    for (int i=0;i<n;i++)b[i]=a[i];
    sort(a,a+n);
    for (int i=0;i<n;i++)if (a[i]!=b[i])ans++;
    freopen("outofplace.out","w",stdout);
    cout<<ans<<endl;
    fclose(stdout);
}
