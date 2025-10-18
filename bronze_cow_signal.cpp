#include <iostream>
using namespace std;
char ans[11];
int main()
{
    char m1;
    int y,x,f;
    freopen("cowsignal.in","r",stdin);
    cin>>y>>x>>f;
    freopen("cowsignal.out","w",stdout);
    for (int i=1;i<=y;i++){
        for (int j=1;j<=x;j++){
            cin>>m1;
            ans[j]=m1;
            for (int i=0;i<f;i++)cout<<m1;
        }
        cout<<endl;
        for (int iter=1;iter<f;iter++){
            for (int j=1;j<=x;j++){
                for (int prt=0;prt<f;prt++)cout<<ans[j];
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
