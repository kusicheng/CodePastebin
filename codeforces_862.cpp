#include <iostream>
#include <vector>
#define N 100005
using namespace std;
vector<int> graph[N];
bool visited[N];
int n,u,v,c1,c2;
void dfs(const int &node,const int &lastcolor){
    visited[node]=1;
    (lastcolor)?c1++:c2++;
    for (int x:graph[node])
        if (!visited[x])
            dfs(x,!lastcolor);
}
int main() {
    cin>>n;
    for (int i=0;i<n-1;i++){
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0,0);
    cout<<(long long)c1*c2-n+1<<endl;
}
