#include <bits/stdc++.h>
using namespace std;

int main() {
    int count=0;
    string str, s;
    getline(cin, str);
    stringstream ss(str);
    while(ss>>s) {
        count++;
    }
    cout<<count;
    return 0;
}