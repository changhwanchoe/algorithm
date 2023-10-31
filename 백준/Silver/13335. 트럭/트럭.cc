#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Truck {
	int weight, time;
};

int n, len, weight, total, ans;
queue<Truck> wating, ing;

void init()
{
	cin>>n>>len>>weight;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		wating.push({num, len});
	}
}

void bridge()
{
	if(wating.empty()) return;
	if(total + wating.front().weight <= weight) {
		ing.push({wating.front().weight, wating.front().time-1});
		total += wating.front().weight;
		wating.pop();
	}
}

bool move()
{
	if(ing.empty()) return true;
	bool what=false;
	if(ing.front().time==0) {
		total -= ing.front().weight;
		ing.pop();
		what=true;
	} 
	int cur=ing.size();
	for(int i=0;i<cur;i++) {
		ing.push({ing.front().weight, ing.front().time-1});
		ing.pop();
	}
	if(what) {
		bridge();
		return true;
	} else return false;
}

void run()
{
	while(true) {
		if(wating.empty() && ing.empty()) break;
		ans++;
		if(ing.empty() && !wating.empty())
			bridge();
		else {
			if(!move())
				bridge();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	run();
	cout<<ans;
	return 0;
}
