#include <bits/stdc++.h>
using namespace std;

int func (int N, int x, int y)
{
    if(N==0) return 0;
    int half = pow(2, N)/2;
    if(x<half && y<half) return func(N-1, x, y);
    else if(x<half && y>=half) return half*half+func(N-1, x, y-half);
    else if(x>=half && y<half) return 2*half*half+func(N-1, x-half, y);
    else return 3*half*half+func(N-1, x-half, y-half);
}

int main() {
    int N,x,y;
    cin>>N>>x>>y;
    cout<<func(N,x,y);
    return 0;
}