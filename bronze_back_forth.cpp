#include <stdio.h>
#define ll long long
using namespace std;
int b1[10],b2[11];
int d1(int arr[],int arr2[],int tb1,int tb2){
    int valr;
    for (int i=0;i<10;i++){
        valr=arr[i];
        arr[i]=0;
        arr2[10]=valr;
        d2(arr,arr2,tb1-valr,tb2+valr,i);
        arr[i]=valr;
    }
}
int d2(int arr[],int arr2[],int tb1,int tb2,int removedidx){
    int valr;
    for (int i=0;i<11;i++){
        valr=arr2[i];
        arr2[i]=0;
        arr[removedidx]=valr;
        d3(arr,arr2,tb1+valr,tb2-valr,i);
        arr2[i]=valr;
    }
}
int d3(int arr[],int arr2[],int tb1,int tb2,int removedidx){
    int valr;
    for (int i=0;i<10;i++){
        valr=arr[i];
        arr[i]=0;
        arr2[removedidx]=valr;
        d4(arr,arr2,tb1-valr,tb2+valr,i);
        arr[i]=valr;
    }
}
int d4(int arr[],int arr2[],int tb1,int tb2,int removedidx){
    int valr;
    for (int i=0;i<11;i++){
        valr=arr2[i];
        arr2[i]=0;
        arr[removedidx]=valr;
        d3(arr,arr2,tb1+valr,tb2-valr,i);
        arr2[i]=valr;
    }
}
int main(){
    ll ans=
    for (int i=0;i<10;i++)
        scanf("%d",&b1[i]);
    for (int i=0;i<10;i++)
        scanf("%d",&b2[i]);
    d1(b1,b2,1000,1000);
}
