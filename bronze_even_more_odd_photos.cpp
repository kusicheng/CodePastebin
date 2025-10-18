#include <iostream>
using namespace std;
int oddnum,evennum,n,t,ans;
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>t;
        if (t%2)oddnum++;
        else evennum++;
    }
    int minminus=min(oddnum,evennum);
    oddnum-=minminus;
    evennum-=minminus;
    ans+=minminus*2;
    while (oddnum>=5){
        oddnum-=3;
        ans+=2;
    }
    switch (oddnum){
        case 5:ans+=3;break;
        case 4:ans+=1;break;
        case 3:ans+=2;break;
        case 2:ans+=1;break;
        case 1:break;
        case 0:break;
    }
    if (evennum)ans++;
    cout<<ans<<endl;
}
