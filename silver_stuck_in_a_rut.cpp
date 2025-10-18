#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
struct cow{
	int x,y;
} cows[1005];
vector<int> east,north;
int n,dxn,dxe,stopped[1005];
char m;
bool cmpe(int a,int b){
	if (cows[a].y==cows[b].y)return cows[a].x>cows[b].x;
	return cows[a].y<cows[b].y;
}
bool cmpn(int a, int b){
	if (cows[a].x==cows[b].x)return cows[a].y>cows[b].y;
	return cows[a].x<cows[b].x;
}
int main(){
	cin>>n;
	vector<int> blame(n);
	for (int i=0;i<n;i++){
		cin>>m>>cows[i].x>>cows[i].y;
		if (m=='N')north.pb(i);
		else east.pb(i);
	}
	sort(north.begin(),north.end(),cmpn);
	sort(east.begin(),east.end(),cmpe);
	for (int i:north){
		for (int j:east){//dxn=east cow y-north cow y
			dxn=cows[j].y-cows[i].y;
			dxe=cows[i].x-cows[j].x;
			if (dxe>=0&&dxn>=0&&dxn!=dxe&&!stopped[i]&&!stopped[j]){
				if (dxn<dxe){
					blame[i]+=blame[j]+1;
					stopped[j]=1;
				}
				else {
					blame[j]+=blame[i]+1;
					stopped[i]=1;
				}
			}
		}
	}
	for (int u:blame)cout<<u<<endl;
}
