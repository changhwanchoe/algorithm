#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void run()
{
	int n;
	priority_queue <int, vector<int>, greater<>> pq;
	cin>>n;
	while(n--) {
		int t;
		cin>>t;
		if(t==0)
			if(!pq.empty()) {
				cout<<pq.top()<<endl;
				pq.pop();
			} else 
				cout<<0<<endl;
		else
			pq.push(t);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	run();
	return 0;
}
