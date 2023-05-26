#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, minNum=1000001, maxNum=-1000001;
    cin>>T;
    while(T--) {
        int num;
        cin>>num;
        minNum = min(minNum, num);
        maxNum = max(maxNum, num);
    }
    cout<<minNum<<' '<<maxNum;
    return 0;
}