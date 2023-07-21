#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {50, 40, 45, 30, 35, 42, 32, 25, 20, 10}; // max heap
    int input_val;
    cin >> input_val;
    v.push_back(input_val);
    int current_index = v.size() - 1;
    while ( current_index != 0 )
    {
        int parent_index = (current_index - 1) / 2;
        if(v[parent_index] < v[current_index])
        {
            swap(v[parent_index], v[current_index]);
        }
        else break;
        current_index = parent_index;
    }
    for( int i: v)
    {
        cout << i << ' ';
    }
    return 0;
}
