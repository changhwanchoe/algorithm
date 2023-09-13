#include <bits/stdc++.h>
using namespace std;

int arr[20], ans, N;

void init()
{
	ans=N=0;
	cin>>N;
	fill(arr, arr+20, 0);
	for(int i=0;i<20;i++)
		cin>>arr[i];
}

void solution()
{
	for(int i=1;i<20;i++) {
		for(int j=0;j<i;j++) {
			if(arr[j]>arr[i]) {
				int temp=arr[i];
				for(int k=i;k>j;k--) {
					arr[k] = arr[k-1];
					ans++;
				}
				arr[j] = temp;
			}
		}
	}
}

int main()
{
    int T;
	cin>>T;
	while(T--) {
		init();
		solution();
		cout<<N<<' '<<ans<<endl;
	}
	return 0;
}
