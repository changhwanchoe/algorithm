#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
vector<int> arr, dp;

void init()
{
	cin>>n;
	arr.resize(n);
	dp.resize(n, 1);
	for(int i=0;i<n;i++)
		cin>>arr[i];
}

void run()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(arr[i] > arr[j])
				dp[i] = max(dp[j]+1, dp[i]);
	sort(dp.begin(), dp.end(), greater<>());
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	cout<<dp[0];
	return 0;
}
