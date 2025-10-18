#include <iostream>
using namespace std;
int a[100001];
int diff[100001];
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    for (int i=0;i<n;i++){
        cin>>diff[i];
        diff[i]=a[i]-diff[i];
    }
    int idx=0,next,dir,ans=0;
    while (true){
        next=idx+1;
        if (diff[next]<0){
            int add=-2147483647;
            while (diff[next]<0){
                add=max(diff[next],add);
                next++;
            }
            for (int i=idx+1;i<next;i++){
                diff[i]-=add;
            }
            ans-=add;
        }
        else if (diff[next]>0){
            int add=2147483647;
            while (diff[next]>0){
                add=min(diff[next],add);
                next++;
            }
            for (int i=idx+1;i<next;i++){
                diff[i]-=add;
            }
            ans+=add;
        }
        idx=next;
        for (int i=0;i<n;i++)
            if (diff[i]!=0)
                continue;
        break;
    }
    cout<<ans<<endl;
}
