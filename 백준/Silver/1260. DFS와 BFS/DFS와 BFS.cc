#include<bits/stdc++.h>
using namespace std;

int N, M, V;
vector<vector<int>> line;
vector<bool> vis;
vector<int> dfs_ans, bfs_ans;

void init()
{
	cin>>N>>M>>V;
	line.resize(N+1);
	vis.resize(N+1);
	for(int i=0;i<M;i++) {
		int from, to;
		cin>>from>>to;
		line[from].push_back(to);
		line[to].push_back(from);
	}

	for(int i=0;i<line.size();i++)
		sort(line[i].begin(), line[i].end());
}

void dfs(int now)
{
	for(int i=0;i<line[now].size();i++) {
		int next = line[now][i];
		if(!vis[next]) {
			vis[next]=true;
			dfs_ans.push_back(next);
			dfs(next);
		}
	}
}

void bfs()
{
	queue<int> q;
	q.push(V);
	vis[V]=true;
	bfs_ans.push_back(V);
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(int i=0;i<line[now].size();i++) {
			int next = line[now][i];
			if(!vis[next]) {
				vis[next]=true;
				bfs_ans.push_back(next);
				q.push(next);
			}
		}
	}
}

int main()
{
	init();	
	vis[V]=true;
	dfs_ans.push_back(V);
	dfs(V);
	fill(vis.begin(), vis.end(), false);
	bfs();
	for(int &i : dfs_ans)
		cout<<i<<' ';
	cout<<endl;
	for(int &i : bfs_ans)
		cout<<i<<' ';
	return 0;
}
