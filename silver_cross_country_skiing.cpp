#include <iostream>
#include <queue>
#include <cmath>
#define maxn 505
using namespace std;
int row,col,t,p1row,p1col;
int grid[maxn][maxn];
int flags[maxn][maxn];
int mapped[maxn][maxn];
void memset(){
    for (int i=0;i<maxn;i++)for (int j=0;j<maxn;j++)mapped[i][j]=0;
}
bool reachable(int d){
    memset();
    queue<pair<int,int>> q;
    q.push({p1row,p1col});
    mapped[p1row][p1col]=1;
    while (q.size()){
        int rown=q.front().first,coln=q.front().second;
        q.pop();
        if (mapped[rown+1][coln]!=1&&rown+1<row){
            if (abs(grid[rown+1][coln]-grid[rown][coln])<=d){
                q.push({rown+1,coln});
                mapped[rown+1][coln]=1;
            }
            else {
                mapped[rown+1][coln]=-1;
            }
        }
        if (mapped[rown-1][coln]!=1&&rown-1>=0){
            if (abs(grid[rown-1][coln]-grid[rown][coln])<=d){
                q.push({rown-1,coln});
                mapped[rown-1][coln]=1;
            }
            else {
                mapped[rown-1][coln]=-1;
            }
        }
        if (mapped[rown][coln+1]!=1&&coln+1<col){
            if (abs(grid[rown][coln+1]-grid[rown][coln])<=d){
                q.push({rown,coln+1});
                mapped[rown][coln+1]=1;
            }
            else {
                mapped[rown][coln+1]=-1;
            }
        }
        if (mapped[rown][coln-1]!=1&&coln-1>=0){
            if (abs(grid[rown][coln-1]-grid[rown][coln])<=d){
                q.push({rown,coln-1});
                mapped[rown][coln-1]=1;
            }
            else {
                mapped[rown][coln-1]=-1;
            }
        }
    }
    //cout<<"d="<<d<<endl;for (int i=0;i<row;i++){for (int j=0;j<col;j++){cout<<mapped[i][j]<<" ";}cout<<endl;}cout<<endl;
    for (int i=0;i<row;i++)
        for (int j=0;j<col;j++)
            if (flags[i][j]&&mapped[i][j]!=1)
                return false;
    return true;
}
int main(){
    freopen("ccski.in","r",stdin);
    cin>>row>>col;
    for (int i=0;i<row;i++)
        for (int j=0;j<col;j++)
            cin>>grid[i][j];
    bool first=true;
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            cin>>flags[i][j];
            if (first&&flags[i][j]){
                p1row=i;p1col=j;first=false;
            }
        }
    }
    fclose(stdin);
    //cout<<reachable(21)<<endl<<endl;
    int dmin=0,dmax=1000000000,ans,mid;
    while (dmin<=dmax){
        mid=((dmax-dmin)>>1)+dmin;
        if (reachable(mid)){
            dmax=mid-1;
            ans=mid;
        }
        else
            dmin=mid+1;
    }
    freopen("ccski.out","w",stdout);
    cout<<ans<<endl;
    fclose(stdout);
}
