#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,roomnum=1,t1,t2;
bool operator <(const node a,const node b){return a.e>b.e;}
struct node{
    int s,e,room;
};
priority_queue<node> guest;
vector<int> ans;
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        if (guest.size()){
            node m=guest.front();
            cin>>t1>>t2;
            if (m.e<t1){
                guest.push({t1,t2,m.room});
                ans.push_back(m.room);
                guest.pop();
            }
            else{
                ans.push_back(guest.size()+1);
                roomnum=max(roomnum,guest.size()+1);
                guest.push({t1,t2,guest.size()+1});
            }
        }
        else {
            guest.push({t1,t2,1});
            cout<<1<<endl;
        }
    }
    cout<<roomnum<<endl;;
    for (auto x:ans)cout<<x<<endl;
}
