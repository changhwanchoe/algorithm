#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, distance=1;
    cin>>N>>M;
    int arr[N][M]={};
    bool vis[N][M]={};
    for(int i=0;i<N;i++) {
        string str;
        cin>>str;
        for(int j=0;j<M;j++) {
            arr[i][j] = str[j]-48;
        }
    }
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<pair<int, int>> q;
    vis[0][0]=true;
    q.push({0,0});
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for(int dir = 0 ; dir < 4 ; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(vis[nx][ny] || arr[nx][ny]==0) continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
            arr[nx][ny] = arr[cur.first][cur.second] + 1;
            if(nx==N-1 && ny==M-1) distance = arr[nx][ny];
        }
    }
    cout<<distance;
    return 0;
}