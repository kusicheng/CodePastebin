#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#undef ll
#define ll long long
#undef LL_MAX
#define LL_MAX 9223372036854775807
#undef INT_MAX
#define INT_MAX 2147483647
#undef F
#define F first
#undef S
#define S second
#undef UNS
#define UNS using namespace std;
#undef P
#define P pair<int,int>
#define v(l) vector<l>
#define lp(n) for(int i=0;i<n;i++)
UNS
int btree,basket,a[1005];
bool check(int bnum){
    int ihave=basket/2;

}
int main(){
    cin>>btree>basket;
    lp(btree)cin>>a[i];
    sort(a,a+btree);
    int l=0,r=1000000,mid,ans;
    while (l<=r){
        mid=(l+r)>>1;
        if (check(mid)){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
}
