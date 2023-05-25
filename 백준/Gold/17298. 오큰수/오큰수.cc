#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    stack<int> s, temp, answer;
    cin>>T;
    while(T--) {
        int num;
        cin>>num;
        s.push(num);
    }
    answer.push(-1);
    for(;!s.empty();) {
        bool what=true;
        temp.push(s.top());
        s.pop();
        for(;!temp.empty();) {
            if(s.empty()) {
                what=false;
                break;
            }
            if(s.top() < temp.top()) {
                answer.push(temp.top());
                what=false;
                break;
            } else {
                temp.pop();
            }
        }
        if(what)
            answer.push(-1);
    }
    while(!answer.empty()) {
        cout<<answer.top()<<' ';
        answer.pop();
    }
    return 0;
}