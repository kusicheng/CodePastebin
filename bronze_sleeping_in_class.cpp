#include <iostream>
using namespace std;
int a[100001],testcases,n,sum;
int main(){
    cin>>testcases;
    for (int i=0;i<testcases;i++){
        cin>>n;
        for (int idx=0;idx<n;idx++)cin>>a[idx];
        sum=0;
        for (int i=0;i<n;i++)sum+=a[i];
        int flag=0;
        for (int i=n;i>=1;i--){
            //cout<<"i: "<<i<<endl;
            if (sum%i!=0)
                continue;
            int goal=sum/i;
            int rangesum=0;
            for (int it=0;it<n;it++){
                //cout<<"iterating: "<<it<<endl;
                rangesum+=a[it];
                if (rangesum>goal){
                    flag=1;
                    break;
                }
                else if (rangesum==goal)rangesum=0;
            }
            if (!flag){
                cout<<n-i<<endl;
                break;
            }
            flag=0;
        }
    }
}
