#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, d, k, c, ans;
int food[3001];
vector<int> table;

void input()
{
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		int foodNum;
		cin >> foodNum;
		temp.push_back(foodNum);
		table.push_back(foodNum);
	}
	for (int i = 0; i < n; i++) {
		table.push_back(temp[i]);
	}
}

void solution()
{
	int left, right, count;
	count = left = right = 0;
	count = 2;
	food[table[0]] ++;
	food[c] ++;
	while (left <= n) {
		if (right - left + 1 < k) {
			if (!food[table[++right]]) count++;
			food[table[right]] ++;
		}
		else {
			ans = max(ans, count);
			if (food[table[left]]==1) count--;
			food[table[left++]] --;
		}
	}
}

int main()
{
	cin >> n >> d >> k >> c;
	input();
	solution();
	cout << ans;
	return 0;
}
