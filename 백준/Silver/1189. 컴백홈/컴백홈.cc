#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, k, ans;
vector<vector<char>> arr;
vector<vector<bool>> vis;
vector<pair<int, int>> path;

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
	if(arr[x][y]=='T') return;
	if(x==0 && y==m-1 && sum==k) {
		ans++;
		return;
	}
	int dx[] = {1,0,-1,0};
	int dy[] = {0,1,0,-1};

	for(int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
		if(vis[nx][ny]) continue;
		vis[nx][ny]=true;
		dfs(nx, ny, sum+1);
		vis[nx][ny]=false;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	vis[n-1][0]=true;
	dfs(n-1,0,1);
	cout<<ans;
	return 0;
}
