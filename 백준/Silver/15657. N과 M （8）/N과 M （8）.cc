#include <bits/stdc++.h>
using namespace std;

int N, S, arr[9], answer[9];
//1 7 8 9
void func(int cur)
{
    if(cur == S) {
        for(int i=0;i<S;++i)
            cout<<arr[answer[i]]<<' ';
        cout<<'\n';
        return;
    }
    int st = 0;
    if(cur!=0) st = answer[cur-1];
    for(int i=st;i<N;++i) {
        answer[cur] = i;
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