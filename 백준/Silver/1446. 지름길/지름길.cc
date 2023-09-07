#include <bits/stdc++.h>
using namespace std;

int n, d, ans=21e8;
vector<pair<pair<int, int>, int>> way;
vector<bool> vis;

void input()
{
	cin>>n>>d;
	vis=vector<bool>(n);
	for(int i=0;i<n;i++) {
		int from, to, cost;
		cin>>from>>to>>cost;
		way.push_back({{from, to}, cost});
	}
}

void solution(int path, int tempCost)
{
	if(path>d) return;

	if(path==d) {
		ans=min(ans, tempCost);
		return;
	} else if(path<d) {
		int calCost = d-path;
		ans=min(ans, tempCost+calCost);
	}

	for(int i=0;i<n;i++) {
		if(!vis[i]) {
			vis[i] = true;
			int calCost=0;
			if(path==way[i].first.first) {
				solution(way[i].first.second, tempCost+way[i].second);
			} else if(path<way[i].first.first) {
				int calCost = way[i].first.first - path;
				solution(way[i].first.second, tempCost+calCost+way[i].second);
			}
			vis[i] = false;
		}
	}
}

int main()
{
	input();
	solution(0, 0);
	cout<<ans;
	return 0;
}
