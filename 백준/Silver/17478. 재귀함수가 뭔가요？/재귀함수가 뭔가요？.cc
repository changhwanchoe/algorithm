#include <bits/stdc++.h>
using namespace std;

int N;
string str="\"재귀함수가 뭔가요?\"";
string str1="\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string str2="마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string str3="그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";

void func(int start)
{
    if(start==N) {
        string s;
        for(int i=0;i<start;i++) s+="____";
        cout<<s<<"\"재귀함수가 뭔가요?\"\n";
        cout<<s<<"\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        cout<<s<<"라고 답변하였지.\n";
        return;
    }
    string s;
    for(int i=0;i<start;i++) s+="____";
    cout<<s<<str<<'\n';
    cout<<s<<str1<<'\n';
    cout<<s<<str2<<'\n';
    cout<<s<<str3<<'\n';
    func(start+1);
    cout<<s<<"라고 답변하였지.\n";
}

int main() {
    cin>>N;
    cout<<"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    func(0);

    return 0;
}