#include <iostream>
using namespace std;
char a[3][3];
char b[3][3];
int correct[26];
int binA[26];
int binB[26];
int main(){
    int i,j;
    for (i=0;i<3;i++)
        for (j=0;j<3;j++)
            cin>>a[i][j];
    for (i=0;i<3;i++)
        for (j=0;j<3;j++)
            cin>>b[i][j];
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            int idx=a[i][j]-'A',idx2=b[i][j]-'A';
            if (a[i][j]==b[i][j]){
                correct[idx]++;
            }
            binA[idx]++;
            binB[idx2]++;
        }
    }
    int corcnt=0;
    for (i=0;i<26;i++)
        corcnt+=correct[i];
    int incnt=0;
    for (i=0;i<26;i++){
        incnt+=min(binA[i],binB[i]);
    }
    incnt-=corcnt;
    cout<<corcnt<<endl<<incnt<<endl;
}
