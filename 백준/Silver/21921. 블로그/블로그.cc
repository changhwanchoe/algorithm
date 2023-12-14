#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, ans, cnt;
vector<int> v;
unordered_map<int, int> m;

void init()
{
	int temp;
	cin>>temp>>n;
	v.resize(temp);
	for(int i=0;i<temp;i++)
		cin>>v[i];
}

void run()
{
	int left, right, sum;
	left=right=sum=0;
	while(right<=v.size()) {
		if(right-left < n)
			sum+=v[right++];
		else {
			if(m.find(sum)==m.end())
				m.insert({sum, 1});
			else
				m[sum]++;
			ans=max(ans, sum);
			sum-=v[left++];
		}
	}
	cnt=m[ans];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	if(ans!=0)
		cout<<ans<<endl<<cnt;
	else
		cout<<"SAD";
	return 0;
}
