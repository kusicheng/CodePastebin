#include <stdio.h>
using namespace std;
long long limit,ans,primes[20];
unsigned short int primen;
int main(){
    scanf("%lld%hu",&limit,&primen);
    for (unsigned short int i=0;i<primen;i++)scanf("%lld",&primes[i]);
    long long pre=1<<primen;
    for (int i=1;i<pre;i++){
        long long check=1,subsetans=limit;
        unsigned short int idx=0;
        while (check<pre){
            if (check&i){
                subsetans/=primes[idx];
            }
            idx++;
            check<<=1;
            //printf("%lld\n",check);
        }
        if (__builtin_popcount(i)&1){//odd # of elements, positive
            ans+=subsetans;
        }
        else{//even # of elements, negative
            ans-=subsetans;
        }
    }
    printf("%lld\n",ans);
}
