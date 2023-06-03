#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[101]={}, maxNum=0, index, size=0;
    while(cin>>arr[size]) ++size;
    
    for(int i=0;i<size;++i) {
        if(maxNum<arr[i]) {
            maxNum=arr[i];
            index=i+1;
        }
    }
    cout<<maxNum<<'\n'<<index;
    
    return 0;
}