#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool cmp (const pair<string, int> l, const pair<string, int> r)
{
	if(l.second == r.second)
		if(l.first.size() == r.first.size())
			return l.first < r.first;
		else return l.first.size() > r.first.size();
	else return l.second > r.second;
}

int n, len;
map<string, int> m;

void init()
{
	cin>>n>>len;
	string str;
	for(int i=0;i<n;i++) {
		cin>>str;
		m[str]++;
	}
}

void run()
{
	vector<pair<string, int>> v (m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	for(auto& item : v) {
		if(item.first.size() < len) continue;
		cout<<item.first<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	return 0;
}
