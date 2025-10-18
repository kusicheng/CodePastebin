#include <iostream>
#include <string>
using namespace std;
int l,q,stepfromleft[100005],stepfromright[100005],r;
int appeared[26];
string s;
int main(){
	cin>>l>>q>>s;
	for (int i=0;i<26;i++)appeared[i]=-1;
	for (int i=1;i<=l;i++){
		for (int j=0;j<26;j++)appeared[j]=min(appeared[j],s[i-1]-'A');
		if (appeared[s[i-1]-'A']<s[i-1]-'A')stepfromleft[i]++;
		appeared[s[i-1]-'A']=s[i-1]-'A';
		stepfromleft[i]+=stepfromleft[i-1];
	}
	for (int i=0;i<26;i++)appeared[i]=-1;
	for (int i=l;i>0;i--){
		for (int j=0;j<26;j++)appeared[j]=min(appeared[j],s[i-1]-'A');
		if (appeared[s[i-1]-'A']<s[i-1]-'A')stepfromright[i]++;
		appeared[s[i-1]-'A']=s[i-1]-'A';
		stepfromright[i]+=stepfromright[i+1];
	}
	//for (int i=0;i<=l;i++)cout<<stepfromleft[i];
	//cout<<endl;
	//for (int i=0;i<=l;i++)cout<<stepfromright[i];
	//cout<<endl;
	while (q--){
		cin>>l>>r;
		cout<<stepfromleft[l-1]+stepfromright[r+1]<<endl;
	}
}
