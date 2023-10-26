#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,m;
vector<vector<int>> arr;
vector<vector<bool>> vis;
queue<pair<int, int>> q;

void init()
{
	cin>>n>>m;
	arr.resize(n, vector<int>(m));
	vis.resize(n, vector<bool>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			cin>>arr[i][j];
			if(arr[i][j]==2) q.push({i, j});
			else if(arr[i][j]==1) arr[i][j]=-1;
		}
}

void run()
{
	int dx[] = {1,0,-1,0};
	int dy[] = {0,1,0,-1};
	arr[q.front().first][q.front().second]=0;
	vis[q.front().first][q.front().second]=true;
	while(!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for(int i=0;i<4;i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
			if(arr[nx][ny]==0 || vis[nx][ny]) continue;
			vis[nx][ny]=true;
			arr[nx][ny]=arr[now.first][now.second]+1;
			q.push({nx, ny});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)
			cout<<arr[i][j]<<' ';
		cout<<endl;
	}	
	return 0;
}
