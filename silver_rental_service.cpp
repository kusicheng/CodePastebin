#include <cmath>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
int cow,store,rent;
struct s{
	long long price,amount;
};
bool cmp(s a,s b){
	return a.price>b.price;
}
int main(){
	freopen("rental.in","r",stdin);
	cin>>cow>>store>>rent;
	vector<long long> prod(cow+1);
	prod[0]=0;
	for (int i=1;i<=cow;i++)cin>>prod[i];
	sort(prod.begin()+1,prod.end(),greater<int>());
	vector<s> storebuy(store);
	for (int j=0;j<store;j++)cin>>storebuy[j].amount>>storebuy[j].price;
	sort(storebuy.begin(),storebuy.end(),cmp);
	vector<long long> rentp(rent+1);
	rentp[0]=0;
	for (int k=1;k<=rent;k++)cin>>rentp[k];
	sort(rentp.begin()+1,rentp.end(),greater<int>());
	for (int u=1;u<=rent;u++)rentp[u]+=rentp[u-1];
	fclose(stdin);
	long long ans=0,snum=0,t=0;
	for (int z=0;z<=cow;z++){
		//add the new cow produce sold to store to t
		//cout<<prod[z]<<endl; 
		while (prod[z]>0&&snum<store){
			int sold=min(prod[z],storebuy[snum].amount);
			t+=sold*storebuy[snum].price;
			prod[z]-=sold;
			storebuy[snum].amount-=sold;
			if (storebuy[snum].amount==0)
				snum++;
		}
		//cout<<t<<" "<<rentp[min(cow-z,rent)]<<endl;
		ans=max(ans,t+rentp[min(cow-z,rent)]);
	}
	freopen("rental.out","w",stdout);
	cout<<ans<<endl;
	fclose(stdout);
}
