#include <bits/stdc++.h>
using namespace std;

int N, M, arr[10];
bool vis[10];

void NM(int start)
{
    if(start==M) {
        for(int i=0;i<M;++i)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }

    for (int i=1;i<=N;++i) {
        if(!vis[i]) {
            vis[i] = true;
            arr[start] = i;
            NM(start+1);
            vis[i] = false;
        }
    }
}

int main()
{
    cin>>N>>M;
    NM(0);
    return 0;
}