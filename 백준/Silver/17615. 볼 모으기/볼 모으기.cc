#include <bits/stdc++.h>
using namespace std;

int N, red, blue, ans;
vector<char> arr;

void init()
{
	cin>>N;
	arr.resize(N);
	for(int i=0;i<N;i++) {
		cin>>arr[i];
		if(arr[i]=='R')
			red++;
		else
			blue++;
	}
}

void solution()
{
	int r=0,b=0,temp=0;

	for(int i=0;i<N;i++) {
		if(r==red) {
			ans = b;
			break;
		} else if(b==blue) {
			ans = r;
			break;
		} else if(arr[i]=='R')
			r++;
		else if(arr[i]=='B')
			b++;
	}
	ans = min(r, b);
	r=b=0;

	for(int i=N-1;i>=0;i--) {
		if(r==red) {
			temp = b;
			break;
		} else if(b==blue) {
			temp = r;
			break;
		} else if(arr[i]=='R')
			r++;
		else if(arr[i]=='B')
			b++;
	}
	ans = min(ans, temp);
}

int main()
{
	init();
	solution();
	cout<<ans;
	return 0;
}
