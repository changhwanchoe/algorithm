#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int H,W,N,M,ans;

void init()
{
	cin>>H>>W>>N>>M;
}

void solution()
{
	for(int i=0;i<H;i+=N+1)
		for(int j=0;j<W;j+=M+1)
				++ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	init();
	solution();
	cout<<ans;
	return 0;
}
