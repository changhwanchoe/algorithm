#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;

int n, score, p, ans;
vector<int> v;

void init()
{
	ans=1;
	cin>>n>>score>>p;
	v.resize(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
}

void run()
{
	int cnt=0;
	for(int i=0;i<v.size();i++) {
		if(v[i] > score)
			ans++;
		else if(v[i] < score)
			break;
		cnt++;
	}
	if(n==0)
		ans=1;
	else if(p==cnt)
		ans=-1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	cout<<ans;
	return 0;
}
