#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, ans, target, mini;
vector<int> arr;

void init()
{
	ans=21e8;
	cin>>N>>target;
	arr.resize(N);
	for(int i=0;i<N;i++)
		cin>>arr[i];
}

void solution(int level, int now)
{
	if(level>N) return;
	if(ans<=now) return;
	if(now>=target) {
		ans=now;
		return;
	}
	solution(level+1, now+arr[level]);
	solution(level+1, now);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++) {
		init();
		solution(0, 0);
		cout<<'#'<<i<<' '<<ans-target<<endl;
	}
	return 0;
}
