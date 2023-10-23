#include <bits/stdc++.h>
using namespace std;

struct Node {
	int h,x,y;
};

bool what;
int N,M,H,ans;
int arr[100][100][100];
queue<Node> q, q2;
int dx[] = {1,0,-1,0,0,0};
int dy[] = {0,1,0,-1,0,0};
int dh[] = {0,0,0,0,1,-1};

void init()
{
	cin>>M>>N>>H;
	for(int h=0;h<H;h++)
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++) {
				cin>>arr[h][i][j];
				if(arr[h][i][j]==1)
					q.push({h,i,j,});
			}
}

bool check()
{
	for(int h=0;h<H;h++)
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(arr[h][i][j]==0)
					return false;
	return true;
}

bool bfs()
{
	int w=false;
	if(!q.empty()) {
		while(!q.empty()) {
			Node now = q.front(); q.pop();
			for(int i=0;i<6;i++) {
				int nh = now.h + dh[i];
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				if(nx<0 || ny<0 || nh<0 || nx>=N || nh>=H || ny>=M) continue;
				if(arr[nh][nx][ny]==-1 || arr[nh][nx][ny]==1) continue;
				w=true;
				arr[nh][nx][ny] = 1;
				q2.push({nh, nx, ny});
			}
		}
		if(w) ans++;
		return true;
	} else if(!q2.empty()) {
		while(!q2.empty()) {
			Node now = q2.front(); q2.pop();
			for(int i=0;i<6;i++) {
				int nh = now.h + dh[i];
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				if(nx<0 || ny<0 || nh<0 || nx>=N || nh>=H || ny>=M) continue;
				if(arr[nh][nx][ny]==-1 || arr[nh][nx][ny]==1) continue;
				w=true;
				arr[nh][nx][ny] = 1;
				q.push({nh, nx, ny});
			}
		}
		if(w) ans++;
		return true;
	} else {
		if(check())
			what=true;
		return false;
	}
}

int main()
{
	init();
	if(check()) {
		cout<<0;
		return 0;
	}
	for(;bfs(););
	if(what)
		cout<<ans;
	else
		cout<<-1;
	return 0;
}
