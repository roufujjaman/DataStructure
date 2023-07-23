#include <bits/stdc++.h>
using namespace std;
class compare
{
    public:
        bool operator()(int a, int b)
        {
            if(a > b) return true;
            else return false;
        }
};
int main()
{
    int count_val, input_val, query_val;
    cin >> count_val;
    priority_queue<int, vector<int>, compare> pq;
    for(int i = 0; i < count_val; i++)
    {
        cin >> input_val;
        pq.push(input_val);
    }
    cin >> count_val;
    for (int i = 0; i < count_val; i++)
    {
        cin >> query_val;
        if(query_val == 0)
        {
            cin >> input_val;
            pq.push(input_val);
            cout << pq.top() << endl;
        }
        else if(query_val == 1)
        {
            if(pq.empty()) cout << "Empty" << endl;
            else cout << pq.top() << endl;
        }
        else if(query_val == 2)
        {
            if(!pq.empty()) pq.pop();
            if(pq.empty()) cout << "Empty" << endl;
            else cout << pq.top() << endl;
        }
    }
    return 0;
}