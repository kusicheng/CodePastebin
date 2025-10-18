#include <iostream>
#include <vector>
using namespace std;
int ncow,n,nswap,l[100],r[100],p[100005];
vector<int> loop[100005];
int loopn[100005];
int looppos[100005];
int ans[100005];
int main(){
    freopen("swap.in","r",stdin);
    cin>>ncow>>n>>nswap;
    for (int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        l[i]--;
        r[i]--;
    }
    fclose(stdin);
    for (int i=0;i<ncow;i++){
        p[i]=i;
        for (int j=0;j<n;j++){
            if (l[j]<=p[i]&&p[i]<=r[j]){
                p[i]=l[j]+r[j]-p[i];
            }
        }
    }
    //finding lowest value x such that p^x[i]=i
    int loopnum=1;
    for (int i=0;i<ncow;i++){
        if (!loopn[i]){
            loopn[i]=loopnum;
            loop[loopnum].push_back(i);
            int next=p[i];
            if (next!=i)looppos[next]=1;
            while (next!=i){
                loop[loopnum].push_back(next);
                loopn[next]=loopnum;
                if (p[next]!=i)
                    looppos[p[next]]=looppos[next]+1;
                next=p[next];
            }
            loopnum++;
        }
    }
    for (int i=0;i<ncow;i++){
        ans[loop[loopn[i]][(nswap+looppos[i])%loop[loopn[i]].size()]]=i;
    }
    freopen("swap.out","w",stdout);
    for (int i=0;i<ncow;i++)cout<<ans[i]+1<<endl;
    fclose(stdout);
}
