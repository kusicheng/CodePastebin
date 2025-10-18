#include <iostream>
#include <cstring>
using namespace std;
int T;
int p;
string compress(string a){
	string res="";
	int lpos=0,rpos;
	while (lpos<n){
		rpos=lpos;
		res+=a[lpos];
		while (rpos<n&&a[rpos]==a[lpos])
			rpos++;
		lpos=rpos;
	}
	return res;
}
int main(){
	cin>>T;
	while (T--){
		int l,ans=0,l1,l2;
		int divide=1;
		string s1,s2;
		vector<pair<int,int> > moves;
		cin>>l>>p;
		cin>>s1>>s2;
		s1=compress(s1);
		s2=compress(s2);
		l1=s1.length()-1;
		l2=s2.length()-1;
		//case discussions
		if (l1>1&&l2>1){
			if (s1[0]!=s2[0]){
				if (s1[l1]!=s1[0]){
					
				}
				else if (s2[l1]!=s1[0]){
					
				}
				
			}
			else{
				
			}
		}
		else if (l1==0&&l2>0){
			divide=2;
			swap(s1,s2);
			if (s1[l1]==s2){
				ans.push_back({1,2});
				s1.pop_back();
			}
			ans.push_back({1,3});
			s3=s1[s1.length()-1];
			ans.pop_back();
		}
		else if (l1>0&&l2==0){
			if (s1[l1]==s2){
				ans.push_back({1,2});
				s1.pop_back();
			}
			ans.push_back({1,3});
			s3=s1[l1];
			ans.pop_back();
		}
		else {
			if (s1==s2&&(p==2||p==3)){
				cout<<"1\n1 2\n";
			}
			else if (s1==s2&&p==1) {
				cout<<1<<endl;
			}
			else cout<<0<<endl;
		}
	}
}
