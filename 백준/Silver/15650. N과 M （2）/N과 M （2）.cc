#include <bits/stdc++.h>
using namespace std;

int N, S, arr[9];
bool vis[9];

void func(int cur)
{
    if(cur == S) {
        for(int i=0;i<S;++i)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    int st;
    if(cur !=0 ) st = arr[cur-1] + 1;
    else if(cur == 0) st = 1;
    for(int i=st;i<=N;++i) {
        if(!vis[i]) {
            vis[i] = true;
            arr[cur] = i;
            func(cur+1);
            vis[i] = false;
        }
    }
}

int main()
{
    cin>>N>>S;
    func(0);
    return 0;
}