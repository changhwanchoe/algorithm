#include <bits/stdc++.h>
using namespace std;

int N, S, arr[8];

void func(int cur)
{
    if(cur == S) {
        for(int i=0;i<S;++i)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    int st;
    if(cur == 0) st = 0;
    else st = arr[cur-1] - 1;

    for(int i=st;i<N;++i) {
        arr[cur] = i+1;
        func(cur+1);
    }
}

int main()
{
    cin>>N>>S;
    func(0);
    return 0;
}