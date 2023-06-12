#include <bits/stdc++.h>
using namespace std;

int N;
int arr[128][128];
int result[2];

bool check(int x, int y, int N)
{
    int num=arr[x][y];
    for(int i=x;i<x+N;++i)
        for(int j=y;j<y+N;++j)
            if(num!=arr[i][j])
                return false;
    return true;
}

void paper(int x, int y, int N)
{
    if(check(x,y,N)) {
        ++result[arr[x][y]];
        return;
    }
    int z=N/2;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            paper(x+i*z, y+j*z, z);
}

int main()
{
    cin>>N;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            cin>>arr[i][j];
    paper(0,0,N);
    cout<<result[0]<<'\n'<<result[1];
    return 0;
}