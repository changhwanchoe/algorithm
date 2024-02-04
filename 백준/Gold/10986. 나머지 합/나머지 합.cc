#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	long long n, k, ans=0;
	vector<long long> arr, psum, cnt;
	cin>>n>>k;
	arr=vector<long long>(n);
	psum=vector<long long>(n+1);
	cnt=vector<long long>(1000);
	
	for(int i=0;i<n;i++)
		cin>>arr[i];

	psum[0]=arr[0];
	cnt[psum[0]%k]++;
	for(int i=1;i<n;i++) {
		psum[i] = psum[i-1] + arr[i];
		cnt[psum[i]%k]++;
	}

	for(int i=0;i<k;i++)
		ans+=cnt[i]*(cnt[i]-1)/2;
	
	cout<<ans+cnt[0];
	return 0;
}
