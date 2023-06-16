#include <bits/stdc++.h>
using namespace std;

int N;
int arr[65][65];
stack<char> s;

bool check (int N, int row, int col)
{
    for(int i=row;i<row+N;++i)
        for(int j=col;j<col+N;++j)
            if(arr[row][col]!=arr[i][j])
                return false;
    return true;
}

void tree (int N, int row, int col)
{
    if(check(N, row, col)) {
        while (!s.empty()) {
            cout<<s.top();
            s.pop();
        }
        cout<<arr[row][col];
        return;
    }
    s.push('(');
    int n = N/2;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            tree(n, row+i*n, col+j*n);
    cout<<')';
}

int main()
{
    cin>>N;
    cin.get();
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j)
            arr[i][j] = cin.get()-48;
        cin.get();
    }
    tree(N,0,0);
    return 0;
}