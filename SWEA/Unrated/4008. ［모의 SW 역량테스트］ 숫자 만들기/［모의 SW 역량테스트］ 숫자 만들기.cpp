#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
vector<int> numbers, operators, calc;

void init()
{
	calc.clear();
	N=0;
	cin>>N;
	numbers=vector<int>(N);
	operators=vector<int>(4);
	for(int i=0;i<4;i++)
		cin>>operators[i];
	for(int i=0;i<N;i++)
		cin>>numbers[i];
}

void solution(int lev, int sum)
{
	if(lev==N) {
		calc.push_back(sum);
		return;
	}
	if(operators[0]) {
		operators[0]--;
		solution(lev+1, sum+numbers[lev]);
		operators[0]++;
	}
	if(operators[1]) {
		operators[1]--;
		solution(lev+1, sum-numbers[lev]);
		operators[1]++;
	}
	if(operators[2]) {
		operators[2]--;
		solution(lev+1, sum*numbers[lev]);
		operators[2]++;
	}
	if(operators[3]) {
		operators[3]--;
		solution(lev+1, sum/numbers[lev]);
		operators[3]++;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++) {
		init();
		solution(1,numbers[0]);
		sort(calc.begin(), calc.end());
		cout<<'#'<<i<<' '<<calc[calc.size()-1]-calc[0]<<endl;
	}
	return 0;
}
