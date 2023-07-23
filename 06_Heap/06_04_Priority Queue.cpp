#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    while (true)
    {
       int command_val;
       cin >> command_val;
       int input_val;
       if(command_val == 0)
       {
            cin >> input_val;
            pq.push(input_val);
       }
       else if(command_val == 1)
       {
            pq.pop();
       }
       else if(command_val == 2)
       {
            cout << pq.top() << '\n';
       }
       else if(command_val == 3) break;
    }
    return 0;
}