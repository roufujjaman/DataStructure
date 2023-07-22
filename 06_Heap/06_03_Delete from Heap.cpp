#include<bits/stdc++.h>
using namespace std;
void insert_heap(vector<int>& v, int input_val) // O(logN)
{
    v.push_back(input_val);
    int current_index = v.size() - 1;
    while(current_index != 0)
    {
        int parent_index = (current_index - 1) / 2;
        if(v[current_index] > v[parent_index]) swap(v[current_index], v[parent_index]);
        else break;
        current_index = parent_index;
    }
}
void delete_heap(vector<int>& v) // O(logN)
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int current_index = 0;
    int last_index = v.size() - 1;
    while(true)
    {
        int left_index = (current_index * 2) + 1;
        int right_index = (current_index * 2) + 2;
        if (left_index <= last_index && right_index <= last_index)
        {
            if( v[left_index] >= v[right_index] && v[left_index] > v[current_index])
            {
                swap(v[left_index], v[current_index]);
                current_index = left_index;
            }
            else if( v[right_index] >= v[left_index] && v[right_index] > v[current_index] )
            {
                swap(v[right_index], v[current_index]);
                current_index = right_index;
            }
            else break;
        }
        else if (left_index <= last_index )
        {
            if(v[left_index] > v[current_index])
            {
                swap(v[left_index], v[current_index]);
                current_index = left_index;
            }
            else break;
        }
        else break;
    }
}
int main()
{
    vector<int> v;
    int input_val;
    while (true) // O(NlogN) to insert N elements;
    {
        cin >> input_val;
        if(input_val == -1) break;
        insert_heap(v, input_val);
    }
    delete_heap(v);
    // delete_heap(v);
    for(int i: v)
    {
        cout << i << ' ';
    }
    return 0;
}
