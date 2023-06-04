#include <bits/stdc++.h>
using namespace std;

int N;
int arr [2200][2200];
int result[3];

bool check (int row, int col, int N)
{
    for(int i=row;i<row+N;++i) {
        for(int j=col;j<col+N;++j) {
            if(arr[row][col]!=arr[i][j])
                return false;
        }
    }
    return true;
}

void Z(int row, int col, int N)
{
    if(check(row, col, N)) {
        ++result[arr[row][col]+1];
        return;
    }
    int z = N/3;
    for(int i=0;i<3;++i) {
        for(int j=0;j<3;++j) {
            Z(row+i*z, col+j*z, z);
        }
    }
}

int main()
{
    cin>>N;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            cin>>arr[i][j];
    Z(0,0,N);
    cout<<result[0]<<'\n'<<result[1]<<'\n'<<result[2];
    return 0;
}