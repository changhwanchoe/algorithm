#include <bits/stdc++.h>
using namespace std;

int n, ans, vis[100001], target;
vector<int> arr;

void init()
{
    cin>>n>>target;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        arr.push_back(num);
    }
}

void run()
{
    int left=0, right=0, tmp=0;
    while(right < n) {
        if(vis[arr[right]] + 1 <= target) {
            tmp++;
            vis[arr[right++]]++;
            ans=max(ans, tmp);
        } else {
            ans=max(ans, tmp);
            vis[arr[left++]]--;
            tmp--;
        }
    }
}
int main()
{
    init();
    run();
    cout<<ans;
    return 0;
}