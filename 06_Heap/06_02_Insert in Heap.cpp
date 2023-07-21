#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v; 
    int count, input_val;
    cin >> count;
    for(int i = 0; i < count; i++)
    {
        cin >> input_val;
        v.push_back(input_val);
        int current_index = i;
        while (current_index != 0)
        {
            int parent_index = (current_index - 1) / 2;
            if(v[parent_index] < v[current_index]) swap(v[parent_index], v[current_index]);
            else break;
            current_index = parent_index;
        }
    }
    for( int i: v)
    {
        cout << i << ' ';
    }
    return 0;
}
