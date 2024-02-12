#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;
int arr[1001][1001], dp[1001][1001];

void init()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
}

void run()
{
	dp[0][0] = arr[0][0];

	for(int i=1;i<n;i++)
		dp[i][0] = dp[i-1][0] + arr[i][0];

	for(int i=1;i<m;i++)
		dp[0][i] = dp[0][i-1] + arr[0][i];

	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			dp[i][j] = max(dp[i-1][j] + arr[i][j], dp[i][j-1] + arr[i][j]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	cout<<dp[n-1][m-1];
	return 0;
}
