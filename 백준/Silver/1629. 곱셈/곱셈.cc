#include <bits/stdc++.h>
using namespace std;

long long recursion (long long a, long long b, long long c)
{
    if(b==1) return a % c;
    long long value = recursion(a, b/2, c);
    value = value * value % c;
    if(b%2==0) return value;
    return value * a % c;
}

int main() {
    long long a, b, c;
    cin>>a>>b>>c;
    cout<<recursion(a, b, c);

    return 0;
}