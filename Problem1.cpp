#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>>graph[(int)1e4];
#define q0 0
#define q1 1
#define q2 2
#define q3 3
vector<string>State_name(4);

int main()
{
    State_name[q0] = "{Even 0s , Even 1s}";
    State_name[q1] = "{Even 0s , Odd 1s}";
    State_name[q2] = "{Odd 0s , Odd 1s}";
    State_name[q3] = "{Odd 0s , Even 1s}";
    graph[q0].push_back({q1,'1'});
    graph[q0].push_back({q3,'0'});

    graph[q1].push_back({q0,'1'});
    graph[q1].push_back({q2,'0'});

    graph[q2].push_back({q3,'1'});
    graph[q2].push_back({q1,'0'});

    graph[q3].push_back({q2,'1'});
    graph[q3].push_back({q0,'0'});
    cout<<"Enter The String :\n";
    string s;
    cin>>s;
    cout<<endl;
    short int CurrState = q0;
    for(int i=0;i<s.size();i++)
    {
        cout<<"Current State is "<<CurrState<<endl;
        for(auto child : graph[CurrState])
        {
            int transition = child.second;
            if(transition == s[i]) {
                cout<<"Going to state ("<<State_name[child.first]<<") by transition"<<transition-'0'<<endl;
                CurrState = child.first;
                break;
            }
        }
    }
    cout<<"-------------\n";
    if(CurrState==q0)
        cout<<"Accepted String";
    else cout<<"Declined String";

    return 0;
}
