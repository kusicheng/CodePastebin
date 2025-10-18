#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a[8]={"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
string constraints[7][2],t;
int main(){
    sort(a,a+8);
    freopen("lineup.in","r",stdin);
    int n;cin>>n;
    for (int i=0;i<n;i++){
        cin>>constraints[i][0];
        cin>>t;cin>>t;cin>>t;cin>>t;
        cin>>constraints[i][1];
    }
    fclose(stdin);
    bool good;
    do {
        for (int i=0;i<n;i++){
            good=false;
            for (int it=0;it<7;it++){
                if (a[it]==constraints[i][0]&&a[it+1]==constraints[i][1]||a[it]==constraints[i][1]&&a[it+1]==constraints[i][0]){
                    good=true;
                    break;
                }
            }
            if (!good)break;
        }
        if (good){
            freopen("lineup.out","w",stdout);
            for (int i=0;i<8;i++)cout<<a[i]<<endl;
            fclose(stdout);
            break;
        }
    } while (next_permutation(a,a+8));
}
