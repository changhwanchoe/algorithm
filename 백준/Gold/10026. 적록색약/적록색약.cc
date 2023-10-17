#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, ans, ans2;
vector<vector<char>> nomal, qt;

void init()
{
	cin>>N;
	nomal.resize(N, vector<char>(N));
	qt.resize(N, vector<char>(N));
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++) {
			cin>>nomal[i][j];
			if(nomal[i][j]=='G')
				qt[i][j]='R';
			else
				qt[i][j]=nomal[i][j];
		}
}

void nomal_bfs(char target, int x, int y)
{
	queue<pair<int, int>> q;
	q.push({x, y});
	int dx[] = {1,0,-1,0};
	int dy[] = {0,1,0,-1};

	while(!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for(int i=0;i<4;i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if(nx<0 || ny<0 || nx>=N ||ny>=N) continue;
			if(nomal[nx][ny] != target) continue;
			nomal[nx][ny]='A';
			q.push({nx, ny});
		}
	}
}

void qt_bfs(char target, int x, int y)
{
	queue<pair<int, int>> q;
	q.push({x, y});
	int dx[] = {1,0,-1,0};
	int dy[] = {0,1,0,-1};

	while(!q.empty()) {
		pair<int, int> now = q.front(); q.pop();
		for(int i=0;i<4;i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if(nx<0 || ny<0 || nx>=N ||ny>=N) continue;
			if(qt[nx][ny] != target) continue;
			qt[nx][ny]='A';
			q.push({nx, ny});
		}
	}
}

void solution()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(nomal[i][j]!='A') {
				ans++;
				char target=nomal[i][j];
				nomal[i][j]='A';
				nomal_bfs(target, i, j);
			}
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(qt[i][j]!='A') {
				ans2++;
				char target=qt[i][j];
				qt[i][j]='A';
				qt_bfs(target, i, j);
			}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	solution();
	cout<<ans<<' '<<ans2;
	return 0;
}
