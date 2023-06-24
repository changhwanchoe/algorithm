#include <bits/stdc++.h>
using namespace std;

int N, S, arr[8], answer[8];

void func(int cur)
{
    if(cur == S) {
        for(int i=0;i<S;++i)
            cout<<answer[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<N;++i) {
        answer[cur] = arr[i];
        func(cur+1);
    }
}

int main()
{
    cin>>N>>S;
    for(int i=0;i<N;++i)
        cin>>arr[i];
    sort(arr, arr+N);
    func(0);
    return 0;
}