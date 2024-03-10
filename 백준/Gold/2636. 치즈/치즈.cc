#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, arr[100][100], ansTime, ansCnt, dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
queue<pair<int, int>> q;

void init()
{
	int cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			cin>>arr[i][j];
			if(arr[i][j]==1) ++cnt;
		}
	ansCnt = cnt;
}

void findCheese()
{
	bool vis[100][100]={};
	queue<pair<int, int>> temp;
	temp.push({0,0});
	while(!temp.empty()) {
		pair<int, int> now = temp.front(); temp.pop();
		for(int i=0;i<4;i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
			if(vis[nx][ny]) continue;
			if(arr[nx][ny] == 1) {
				q.push({nx, ny});
				vis[nx][ny] = true;
			} else {
				temp.push({nx, ny});
				vis[nx][ny] = true;
			}
		}
	}
}

void meltCheese()
{
	while(!q.empty()) {
		arr[q.front().first][q.front().second] = 0;
		q.pop();
	}
}

bool checkCheese()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(arr[i][j] == 1) return false;
	return true;
}

bool run()
{
	findCheese();
	if(!q.empty()) {
		ansCnt = q.size();
		meltCheese();
	}

	if(!checkCheese())
		++ansTime;
	else {
		cout<<ansTime+1<<endl<<ansCnt;
		return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	while(run());
}
