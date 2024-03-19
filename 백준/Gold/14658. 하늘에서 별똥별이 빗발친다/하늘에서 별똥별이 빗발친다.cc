#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,m,k,l,ans;
vector<pair<int, int>> v;

void init()
{
	cin>>n>>m>>l>>k;
	for(int i=0;i<k;i++) {
		int x, y;
		cin>>x>>y;
		v.push_back({x,y});
	}
}

void run()
{
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++) {
			int cnt=0;
			int x=v[i].first;
			int y=v[j].second;
			for(int z=0;z<k;z++) {
				int nx=v[z].first;
				int ny=v[z].second;
				if(x<=nx && nx<=x+l && y<=ny && ny<=y+l) ++cnt;
			}
			ans=max(ans, cnt);
		}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	cout<<k-ans;
}
