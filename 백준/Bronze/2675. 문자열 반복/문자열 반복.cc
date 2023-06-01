#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    string str;
    cin>>T;
    for(int i=0;i<T;i++) {
        cin>>N>>str;
        for(int j=0;j<str.length();j++)
            for(int k=0;k<N;k++)
                cout<<str[j];
        cout<<'\n';
    }

    return 0;
}