#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

int n,m,cnt;
unordered_map<int,bool> um;
vector<pair<string, int>> arr;

bool compare(pair<string, int> s1, pair<string, int> s2)
{
	return s1.second < s2.second;
}

void init()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		string temp;
		int power;
		cin>>temp>>power;
		if(um.find(power)==um.end()) {
			arr.push_back({temp, power});
			um.insert({power, true});
			cnt++;
		}
	}
	sort(arr.begin(), arr.end(), compare);
}

void run()
{
	for(int i=0;i<m;i++) {
		int power;
		cin>>power;
		int left=0, right=cnt-1;
		while(left <= right) {
			int mid = (left+right)/2;
			if(arr[mid].second == power) {
				cout<<arr[mid].first<<'\n';
				break;
			} else if(arr[mid].second < power) {
				if(left==mid) {
					cout<<arr[mid+1].first<<'\n';
					break;
				}
				left=mid;
			} else {
				if(left==mid) {
					cout<<arr[mid].first<<'\n';
					break;
				}
				right=mid;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	run();
	return 0;
}
