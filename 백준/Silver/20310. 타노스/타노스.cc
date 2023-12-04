#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

string str, ans;
int cnt[2];

void init()
{
	cin>>str;
	for(int i=0;i<str.size();i++) {
		char ch=str[i];
		cnt[atoi(&ch)]++;
	}
	cnt[0]/=2;
	cnt[1]/=2;
}

void run()
{
	for(int i=str.size()-1;i>=0;i--) {
		if(cnt[0]>0 && str[i]=='0') {
			cnt[0]--;
			str[i]='A';
		}
	}

	for(int i=0;i<str.size();i++) {
		if(cnt[1]>0 && str[i]=='1') {
			cnt[1]--;
			str[i]='A';
		}
	}

	for(int i=0;i<str.size();i++)
		if(str[i]!='A')
			ans+=str[i];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	cout<<ans;
	return 0;
}
