#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, nn, k, ans;
deque<pair<int, bool>> belt;

void init()
{
	int du;
	cin>>n>>k;
	nn=2*n;
	for(int i=0;i<nn;i++) {
		cin>>du;
		belt.push_back({du, false});
	}
}

void load()
{
	if(belt.front().first)
		belt.front() = make_pair(belt.front().first-1, true);
}

void rotation()
{
	pair<int, bool> temp = belt.back();
	belt.pop_back();
	belt.push_front(temp);
	if(belt[n-1].second) belt[n-1].second=false;
}

void move()
{
	for(int i=n-2;i>=0;--i)
		if(belt[i].second && belt[i+1].first && !belt[i+1].second) {
			--belt[i+1].first;
			belt[i+1].second=true;
			belt[i].second=false;
		}
	if(belt[n-1].second)
		belt[n-1].second=false;
}

bool check()
{
	int cnt=0;
	for(int i=0;i<belt.size();++i)
		if(!belt[i].first) ++cnt;

	if(cnt>=k) return true;
	else return false;
}

void run()
{
	while(!check()) {
		rotation();
		move();
		load();
		++ans;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	cout<<ans;
}
