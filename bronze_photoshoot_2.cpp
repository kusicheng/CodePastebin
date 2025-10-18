#include <iostream>
using namespace std;
int n,ans;
int has[100002];
int need[100002];
int used[100002];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)cin>>has[i];
    for (int i=1;i<=n;i++)cin>>need[i];
    int dx=0;
    for (int i=1;i<=n;i++){
        if (has[i-dx]!=need[i]&&used[has[i-dx]]==0){
            dx++;
            ans++;
            used[need[i]]=1;
        }
        else if (has[i-dx]==need[i]){
            continue;
        }
        else {
            while (used[has[i-dx]]&&dx>0)dx--;
            if (has[i-dx]!=need[i]&&used[has[i-dx]]==0){
                dx++;
                ans++;
                used[need[i]]=1;
            }
        }
    }
    cout<<ans<<endl;
}
