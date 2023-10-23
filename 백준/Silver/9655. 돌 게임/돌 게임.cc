#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int T, stone[]={1,3};
string str[]={"SK", "CY"};
bool player[2];

void init()
{
	cin>>T;
}

void dfs(int p_lev, int sum)
{
	if(player[0] || player[1]) return;
	if(sum>T) return;
	if(sum==T) {
		player[(p_lev)%2]=true;
		return;
	}
	dfs((p_lev+1)%2, sum+stone[0]);
	dfs((p_lev+1)%2, sum+stone[1]);
}

string check()
{
	if(player[0])
		return str[0];
	else
		return str[1];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	dfs(-1, 0);
	cout<<check();
	return 0;
}
