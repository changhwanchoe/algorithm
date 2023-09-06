#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str;
	int countA = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		if (str[i] == 'a') countA++;

	str += str;

	int left = 0, right = 0, ans=21e8;
	int temp = str[0]=='a' ? 0 : 1;
	while (left < str.size() && right < str.size()) {
		if (right - left +1 < countA) {
			if (str[++right] == 'b') temp++;
		}
		else {
			ans = min(ans, temp);
			if (str[left++] == 'b') temp--;
		}
	}
	cout << ans;

	return 0;
}
