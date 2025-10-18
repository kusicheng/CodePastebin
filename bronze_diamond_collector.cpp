#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int main()
{
    int n,lim,ans=0;
    freopen("diamond.in","r",stdin);
    cin>>n>>lim;
    for (int i=0;i<n;i++)cin>>a[i];
    fclose(stdin);
    sort(a,a+n);
    if (a[n-1]-a[0]<=lim)ans=n;
    for (int i=0;i<n-1;i++){
        int r=i+1;
        long long sum=0;
        while (r<n&&sum<=lim){
            sum+=a[r];
            r++;
        }
        sum-=a[r];
        i=r-1;
    }
    freopen("diamond.out","w",stdout);
    cout<<ans<<endl;
    fclose(stdout);
}
