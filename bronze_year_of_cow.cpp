#include <map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string name1,name2,t,when,year;
map<string,string> nidx;
map<string,int> pnidx;
map<string,int> yearidx;
void readL(){
    cin>>name1;
    cin>>t;
    cin>>t;
    cin>>when;
    cin>>year;
    cin>>t;
    cin>>t;
    cin>>name2;
}
int id_year(string s){
    char a=s[0];
    char b=s[2];
    switch (a){
        case 'O': return 12;
        case 'T':return 11;
        case 'R':switch(b){
            case 'b':return 10;
            case 't':return 1;
            case 'o':return 4;
        }
        case 'D':switch(b){
            case 'a':return 9;
            case 'g':return 3;
        }
        case 'S':return 8;
        case 'H':return 7;
        case 'G':return 6;
        case 'M':return 5;
        case 'P':return 2;
        default:return 0;
    }
}
int main(){
    int n,ans=0;
    cin>>n;
    for (int i=0;i<n;i++){
        readL();
        nidx[name1]=name2;
        if (when[0]=='p')pnidx[name1]=1;
        else pnidx[name1]=0;
        yearidx[name1]=id_year(year);
    }
    string q="Elsie";
    do {
        int diff=0;
        if (pnidx[q]){
            //find the difference between yearidx[n] and yearidx[nidx[n]] when yearidx[n] is the previous (some) year from yearidx[nidx[n]]
            //Mildred born in previous Dragon year from Bessie
            //case that yearidx[n]<yearidx[nidx[n]]
            if (yearidx[q]<=yearidx[nidx[q]])diff=-(12-(yearidx[nidx[q]]-yearidx[q]));
            else diff=-(yearidx[q]-yearidx[nidx[q]]);
            if (diff==0)diff=-12;
        }
        else {
            //Mildred born in next Dragon year from Bessie
            if (yearidx[q]<=yearidx[nidx[q]])diff=yearidx[nidx[q]]-yearidx[q];
            else diff=12-(yearidx[q]-yearidx[nidx[q]]);
            if (diff==0)diff=12;
        }
        ans+=diff;
        q=nidx[q];
    }
    while (q!="Bessie");
    cout<<abs(ans)<<endl;
}
