#include <iostream>
#include <vector>
using namespace std;
vector<int> one,two,three;
int n,breed,l,r,q;
int main(){
	freopen("bcount.in","r",stdin);
	cin>>n>>q;
	one.resize(n+5);two.resize(n+5);three.resize(n+5);
	for (int i=1;i<=n;i++){
		cin>>breed;
		switch(breed){
			case 1:one[i]++;break;
			case 2:two[i]++;break;
			case 3:three[i]++;break;
			default:break;
		}
		one[i]+=one[i-1];
		two[i]+=two[i-1];
		three[i]+=three[i-1];
	}
	freopen("bcount.out","w",stdout);
	for (int i=0;i<q;i++){
		cin>>l>>r;
		l--;
		cout<<one[r]-one[l]<<" "<<two[r]-two[l]<<" "<<three[r]-three[l]<<endl;
	}
	fclose(stdout);
	fclose(stdin);
} 
