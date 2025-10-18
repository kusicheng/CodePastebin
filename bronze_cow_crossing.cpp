#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<pair<int,int>> m;
int main()
{
    int n,arrive,need,ans=0,prevfinishtime=0;
    freopen("cowqueue.in","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arrive>>need;
        m.push_back({arrive,need});
    }
    fclose(stdin);
    sort(m.begin(),m.end());
    for (int i=0;i<n;i++){
        if (i==0){
            ans+=m[i].first+m[i].second;
            prevfinishtime+=m[i].first+m[i].second;
        }
        else {
            if (m[i].first>prevfinishtime)
                prevfinishtime=m[i].first+m[i].second;
            else
                prevfinishtime+=m[i].second;
        }
    }
    freopen("cowqueue.out","w",stdout);
    cout<<prevfinishtime<<endl;;
    fclose(stdout);
}
