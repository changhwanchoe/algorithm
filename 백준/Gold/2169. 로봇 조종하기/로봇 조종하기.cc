#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, arr[1000][1000], dp[1000][1000][3];
bool vis[1000][1000];
int dx[] = {1,0,0};
int dy[] = {0,1,-1};

void init()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			cin>>arr[i][j];
			dp[i][j][0] = -21e8;
			dp[i][j][1] = -21e8;
			dp[i][j][2] = -21e8;
		}
}

int run(int x, int y, int dir)
{
	if(x==n-1 && y==m-1) return arr[x][y];
	if(dp[x][y][dir]!=-21e8) return dp[x][y][dir];

	int maxData = -21e8;
	vis[x][y] = true;
	for(int i=0;i<3;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
		if(vis[nx][ny]) continue;
		maxData = max(maxData, run(nx, ny, i));
	}
	vis[x][y] = false;
	return dp[x][y][dir] = arr[x][y] + maxData;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	cout<<run(0,0,0);
}
