#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct pos{
	pair<int, int> st, en;
};
int n, k;
vector<vector<int>> arr, dp;
vector<pos> p;

void init()
{
	cin>>n>>k;
	arr=vector<vector<int>>(n, vector<int>(n));
	dp=vector<vector<int>>(n+1, vector<int>(n+1));
	p=vector<pos>(k);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];

	for(int i=0;i<k;i++) {
		pair<int, int> s, e;
		cin>>s.first>>s.second>>e.first>>e.second;
		s={s.first, s.second};
		e={e.first, e.second};
		p[i]={s, e};
	}
}

void runHap()
{
	dp[1][1]=arr[0][0];
	for(int i=2;i<=n;i++) {
		dp[1][i] = dp[1][i-1] + arr[0][i-1];
		dp[i][1] = dp[i-1][1] + arr[i-1][0];
	}

	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i-1][j-1];
}

void run()
{
	for(int i=0;i<k;i++) {
		pair<int, int> s=p[i].st, e=p[i].en;
		cout<<dp[e.first][e.second] - dp[s.first-1][e.second] - dp[e.first][s.second-1] + dp[s.first -1][s.second-1]<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	runHap();
	run();
	return 0;
}
