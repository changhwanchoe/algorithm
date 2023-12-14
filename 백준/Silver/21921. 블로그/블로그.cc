#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void run()
{
	int n, k, sum=0;
	deque<int> dq;
	cin>>n>>k;
	n-=k;
	while(k--) {
		int x; cin>>x;
		sum+=x; dq.push_back(x);
	}
	int mx=sum, cnt=1;
	while(n--) {
		int x; cin>>x;
		sum+=x; dq.push_back(x);
		sum-=dq.front(); dq.pop_front();
		if(sum>mx) {
			mx=sum;
			cnt=1;
		} else if(sum==mx) cnt++;
	}
	if(mx!=0)
		cout<<mx<<endl<<cnt;
	else
		cout<<"SAD";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	run();
	return 0;
}
