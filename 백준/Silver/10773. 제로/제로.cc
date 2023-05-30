#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    stack<int> s;
    int n,sum=0;
    cin>>n;
    while(n--) {
        int t;
        cin>>t;
        if(t!=0)
            s.push(t);
        else
            s.pop();
    }
    while(!s.empty()) {
        sum+=s.top();
        s.pop();
    }
    cout<<sum;
    return 0;
}