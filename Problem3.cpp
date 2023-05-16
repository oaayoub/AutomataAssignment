#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<pair<pair<int ,char>,pair<char,char>>> graph[(int) 1e4];
// pair.F.F = Next state
// pair.F.S = Transition symbol
// pair.S.F = To be Popped from the stack if on top
// pair.S.S = To be Pushed to the stack
#define q0 0
#define q1 1
#define q2 2
#define q3 3
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
int main() {

    // * = epsilon
    graph[q0].push_back({{q1, '*'}, {'*', '$'}}); //pop nothing push $

    graph[q1].push_back({{q2,'*'}, {'*', '*'}});
    for (int i = 0; i < 26; i++) {
        char c = char('a' + i);
        graph[q1].push_back({{q1, c}, {'*', c}});
    }
    graph[q2].push_back({{q3,'*'}, {'$', '*'}});
    for (int i = 0; i < 26; i++) {
        char c = char('a' + i);
        graph[q2].push_back({{q2, c}, {c, '*'}});
    }

    cout << "Enter The String :\n";
    string t;
    cin >> t;
    if(t.size()&1)  t[t.size()/2]='*';
    else t.insert(t.size() / 2, "*");// insert epsilon in the middle of string
    string s = "*";
    s+=t+"*";
    cout << endl;
    short int CurrState = q0;
    stack<char> STACK;
    // pair.F.F = Next state
    // pair.F.S = Transition symbol
    // pair.S.F = To be Popped from the stack if on top
    // pair.S.S = To be Pushed to the stack
    for (int i = 0; i < s.size(); i++) {
        cout << "Current State is " << CurrState << endl;
        char TapeInput = s[i];

        for(auto child :graph[CurrState])
        {
            int NextState = child.FF;
            char CharTrans = child.FS;
            char toPOP = child.SF;
            char toPUSH = child.SS;
            if(TapeInput == CharTrans && ((!STACK.empty() && toPOP==STACK.top()) || toPOP=='*'))
            {
                if((!STACK.empty() && toPOP==STACK.top()))
                {
                    cout<<"Current stack top that will be popped : "<<STACK.top()<<endl;
                    STACK.pop();
                }
                if(toPUSH!='*')
                {
                    STACK.push(toPUSH);
                    cout<<"PUSHED :"<<toPUSH<<endl;
                }
                if(!STACK.empty()) cout<<"Current Stack top : "<<STACK.top()<<endl;
                else cout<<"STACK EMPTY\n";
                CurrState = NextState;
                break;
            }
        }

    }
    cout<<"\n--------------\n";
    if (CurrState == q3)
        cout << "Accepted String";
    else cout << "Declined String";

    return 0;
}
