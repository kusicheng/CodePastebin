#include <iostream>
#include <cmath>
using namespace std;
const int N=100005;
int n;
char a;
int paper[N],scissor[N],hoof[N];
int main(){
	freopen("hps.in","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a;
		hoof[i]=hoof[i-1];scissor[i]=scissor[i-1];paper[i]=paper[i-1];
		switch(a){
			case 'H':hoof[i]++;break;
			case 'P':paper[i]++;break;
			case 'S':scissor[i]++;break;
			default:break;
		}
	}//1 beats 3, 2 beats 1, 3 beats 2 
	fclose(stdin);
	int ans=0;
	for (int i=1;i<=n;i++){
		ans=max(ans,max(paper[i],max(scissor[i],hoof[i]))+max(paper[n]-paper[i],max(scissor[n]-scissor[i],hoof[n]-hoof[i])));
	}
	freopen("hps.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
} 
