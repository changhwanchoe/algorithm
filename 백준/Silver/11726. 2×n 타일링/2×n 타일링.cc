#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, dp[1001];

void init()
{
	cin>>n;
}

int run(int len)
{
	if(len>n) return 0;
	if(dp[len]) return dp[len];
	if(len==n) return 1;

	int one, two;
	one=run(len+1)%10007;
	two=run(len+2)%10007;
	
	return dp[len]=(one+two)%10007;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run(0);
	cout<<dp[0];
}
