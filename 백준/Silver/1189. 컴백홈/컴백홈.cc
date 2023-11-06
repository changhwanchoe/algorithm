#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, k, ans;
vector<vector<char>> arr;
vector<vector<bool>> vis;

void init()
{
	cin>>n>>m>>k;
	arr.resize(n, vector<char>(m));
	vis.resize(n, vector<bool>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
}

void dfs(int x, int y, int sum)
{
    if(sum>k) return;
    if(x<0 || y>=m || x>=n || y<0) return;
    if(arr[x][y]=='T') return;
	if(x==0 && y==m-1) {
		if(sum==k)
			ans++;
		return;
	}
	if(vis[x][y]) return;
	vis[x][y]=true;
	dfs(x, y+1, sum+1);
    dfs(x+1, y, sum+1);
    dfs(x, y-1, sum+1);
	dfs(x-1, y, sum+1);
	vis[x][y]=false;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    init();
	dfs(n-1,0,1);
	cout<<ans;
	return 0;
}
