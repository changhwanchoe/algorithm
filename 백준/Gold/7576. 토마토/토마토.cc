#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin>>M>>N;
    int board[N][M]={};
    bool vis[N][M]={};
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    queue<pair<int, int>> q;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>board[i][j];
            if(board[i][j]==1)
                q.push({i,j});
        }
    }

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        vis[cur.first][cur.second] = true;
        for(int dir=0;dir<4;dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(vis[nx][ny] || board[nx][ny]!=0) continue;
            vis[nx][ny] = true;
            q.push({nx,ny});
            board[nx][ny] = board[cur.first][cur.second] + 1;
        }
    }
    int day=0;
    bool com=true;
    for(int i=0;i<N && com;i++) {
        for(int j=0;j<M && com;j++) {
            if(board[i][j]==0) {
                com=false;
                break;
            }
            day = max(day, board[i][j]);
        }
    }

    if(com)
        cout<<day-1;
    else
        cout<<-1;
    return 0;
}