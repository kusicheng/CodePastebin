#include <algorithm>
#include <vector>
#include <iostream>
#define INT_MAX 2147483647
using namespace std;
bool sieve[5000005];
int p1[5000005],p3[5000005];
int ans[100005];
void SieveOfAtkin(int limit){
    for (int i = 0; i <= limit; i++)
        sieve[i] = false;
    if (limit > 2)
        sieve[2] = true;
    if (limit > 3)
        sieve[3] = true;
    for (int x = 1; x * x <= limit; x++) {
        for (int y = 1; y * y <= limit; y++) {
            int n = (4 * x * x) + (y * y);
            if (n <= limit 
                && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit 
                && n % 12 == 11)
                sieve[n] ^= true;
        }
    }
    sieve[0]=0;
    sieve[1]=1;
    for (int r = 5; r * r <= limit; r++) {
        if (sieve[r]) {
            for (int i = r * r; i <= limit; i += r * r)
                sieve[i] = false;
        }
    }
    int last1=1,last3=3;
    for (int i=0;i<=limit;i++){
		if (sieve[i]&&i%4==1){
			last1=i;
		}
		else if (sieve[i]&&i%4==3){
			last3=i;
		}
		p1[i]=last1;
		p3[i]=last3;
	}
}
int findprime(int target,int marker){
	if (marker==1)
		return p1[target];
	return p3[target];
}
int T;
int n,num,s;
int main(){
	cin>>T;
	SieveOfAtkin(5000005); 
	while (T--){
		cin>>n;
		bool flag=0;
		for (int i=0;i<n;i++){
			cin>>num;
			if (sieve[num]){
				ans[i]=0;continue;
			}
			s=num%4;
			switch (s){
				case 0:ans[i]=-num/2-1;break;
				case 2:ans[i]=num/2;break;
				default:ans[i]=(num-findprime(num,s))/2+1;
			}
		}
		int minu=INT_MAX;
		for (int i=0;i<n;i++){
			if (ans[i]<0&&-ans[i]<minu){
				minu=-ans[i];
				flag=0;
			}
			else if (ans[i]>=0&&ans[i]<minu){
				minu=ans[i];
				flag=1;
			}
		}
		if (flag)cout<<"Farmer John"<<endl;
		else cout<<"Farmer Nhoj"<<endl;
	}
}
