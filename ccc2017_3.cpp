#include <iostream>
using namespace std;
int length,boards[2005],boardcopy[2005];
void copyboard(){
    for (int i=0;i<2005;i++)boardcopy[i]=boards[i];
}
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>length;
        boards[length]++;
    }
    int maxlength=-1,fml=0;//#fences max length
    for (int i=1;i<=3000;i++){//i is target length
        int fencemax=0;
        copyboard();
        for (int idx=1;idx<=2000&&idx<i;idx++){//boardlength is idx
            if (i-idx==idx){
                fencemax+=boardcopy[idx]/2;
                continue;
            }
            int boardnum=boardcopy[idx];
            int fencesmade=min(boardcopy[i-idx],boardnum);
            fencemax+=fencesmade;
            boardcopy[i-idx]-=fencesmade;
            boardcopy[idx]-=fencesmade;
        }
        if (fencemax>maxlength){
            fml=1;
            maxlength=fencemax;
        }
        else if (fencemax==maxlength){
            fml++;
            cout<<i<<endl;
        }
    }
    cout<<maxlength<<" "<<fml<<endl;
}
