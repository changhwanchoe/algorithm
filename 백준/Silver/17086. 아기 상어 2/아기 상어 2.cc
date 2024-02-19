#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int x, y, arr[50][50], ans;
bool vis[50][50];
queue<pair<int, int>> q;

void init()
{
	cin>>x>>y;
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++) {
			cin>>arr[i][j];
			if(arr[i][j]==1) {
				q.push({i,j});
                vis[i][j]=true;
            }
		}
}

void run()
{
	int dx[] = {-1,-1,-1,0,1,1,1,0};
	int dy[] = {-1,0,1,1,1,0,-1,-1};
	
	while(!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for(int i=0;i<8;i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if(nx<0 || ny<0 || nx>=x || ny>=y) continue;
			if(vis[nx][ny]) continue;
			vis[nx][ny]=true;
			arr[nx][ny]=arr[now.first][now.second] + 1;
			ans = max(ans, arr[nx][ny]);
			q.push({nx,ny});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	cout<<ans-1;
	return 0;
}
