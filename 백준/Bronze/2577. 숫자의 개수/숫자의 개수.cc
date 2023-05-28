#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1, n2, n3, arr[10]={};
    string str;
    cin>>n1>>n2>>n3;
    str=to_string(n1*n2*n3);
    for(int i=0;i<10;i++)
        arr[str[i]-48]++;
    
    for(int i=0;i<10;i++)
        cout<<arr[i]<<'\n';
    return 0;
}