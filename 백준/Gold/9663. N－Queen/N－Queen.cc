#include <bits/stdc++.h>
using namespace std;

int N, cnt;
bool vis[30], vis1[30], vis2[30];

void Queen(int cur)
{
    if(cur == N) {
        ++cnt;
        return;
    }
    for(int i=0;i<N;++i) {
        if(vis[i] || vis1[i+cur] || vis2[i-cur+N-1])
            continue;
        vis[i] = true;
        vis1[i+cur] = true;
        vis2[i-cur+N-1] = true;
        Queen(cur+1);
        vis[i] = false;
        vis1[i+cur] = false;
        vis2[i-cur+N-1] = false;
    }
}

int main()
{
    cin>>N;
    Queen(0);
    cout<<cnt;
    return 0;
}