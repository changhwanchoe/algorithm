#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct medal {
	int sq;
	int g,s,b;
};

bool compare (medal left, medal right)
{
	if(left.g == right.g)
		if(left.s == right.s)
			if(left.b == right.b)
				return left.sq > right.sq;
			else return left.b > right.b;
		else return left.s > right.s;
	else return left.g > right.g;
}

int n, target;
vector<medal> v;
vector<int> ranking;

void init()
{
	cin>>n>>target;
	ranking.resize(n+1);
	for(int i=0;i<n;i++) {
		int sq, g, s, b;
		cin>>sq>>g>>s>>b;
		v.push_back({sq, g, s, b});
	}
	sort(v.begin(), v.end(), compare);
}

void run()
{
	int index=1;
	for(int i=0;i<v.size();i++) {
		if(ranking[v[i].sq]) continue;
		if(i==v.size())
			ranking[v[i].sq] = index;

		ranking[v[i].sq] = index++;
		if(v[i].g == v[i+1].g)
			if(v[i].s == v[i+1].s)
				if(v[i].b == v[i+1].b)
					ranking[v[i+1].sq] = index-1;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	cout<<ranking[target];
	return 0;
}
