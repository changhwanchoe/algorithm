#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	int target;
	cin >> target;
	for(int i=0;i<target;i++)
		for (int j = 0; j < target; j++) {
			int num;
			cin >> num;
			if (pq.size() < target)
				pq.push(num);
			else {
				pq.push(num);
				pq.pop();
			}
		}
	int ans = pq.top();
	cout << ans;
	return 0;
}