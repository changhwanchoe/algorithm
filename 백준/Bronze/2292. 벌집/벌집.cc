#include<bits/stdc++.h>
using namespace std;

int N, ans;

void solution()
{
	int sum=1;
	for(int i=1;;i++) {
		if(N<=sum) {
			ans=i;
			return;
		}
		sum+=6*i;
	}
}

int main()
{
	cin>>N;
	solution();
	cout<<ans;
	return 0;
}
