#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[91]={};
    pair<int, char> maxalpha(0,0);
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++) {
        maxalpha.first = max(maxalpha.first, ++arr[toupper(str[i])]);
        if(maxalpha.first == arr[toupper(str[i])])
            maxalpha.second = toupper(str[i]);
    }
    int count=0;
    for(int i=65;i<91;i++)
        if(maxalpha.first<=arr[i])
            ++count;

    if(count==1)
        cout<<maxalpha.second;
    else
        cout<<'?';

    return 0;
}