#include <iostream>
using namespace std;
int amax,bmax,cmax,astart,bstart,cstart;
int main(){
    freopen("mixmilk.in","r",stdin);
    cin>>amax>>astart>>bmax>>bstart>>cmax>>cstart;
    for (int i=0;i<100;i++){
        if (i%3==0){
            if (astart>bmax-bstart){
                astart-=bmax-bstart;
                bstart=bmax;
            }
            else{
                bstart+=astart;
                astart=0;
            }
        }
        else if (i%3==1){
            if (bstart>cmax-cstart){
                bstart-=cmax-cstart;
                cstart=cmax;
            }
            else{
                cstart+=bstart;
                bstart=0;
            }
        }
        else {
            if (cstart>amax-astart){
                cstart-=amax-astart;
                astart=amax;
            }
            else{
                astart+=cstart;
                cstart=0;
            }
        }
    }
    freopen("mixmilk.out","w",stdout);
    cout<<astart<<endl<<bstart<<endl<<cstart;
    fclose(stdin);
    fclose(stdout);
}
