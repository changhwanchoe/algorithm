#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, D, sum=0, maxSize;
    cin>>N>>D;
    vector<int> arr(N);
    for(int i=0;i<N;i++) cin>>arr[i];
    for(int i=0;i<D;i++) sum+=arr[i];
    maxSize=sum;

    for(int i=D;i<N;i++) {
        maxSize = max(maxSize, sum-arr[i-D]+arr[i]);
        sum=sum-arr[i-D]+arr[i];
    }
    cout<<maxSize;
    return 0;
}