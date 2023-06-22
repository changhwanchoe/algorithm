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
    for(int i=0;i<N;++i) {
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