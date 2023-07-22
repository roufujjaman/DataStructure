#include<bits/stdc++.h>
using namespace std;
void fun( set<int>& s)
{
    s = {10, 20, 30, 40, 50, 60, 100, 22, 20, 10 ,30, 50};
}
int main()
{
    int k = 4;
    vector<int> v = {2, 1, 3};
    // traverse(root, v);
    bool found = false;
    for(int i = 0; i < v.size() - 1; i++)
    {
        for(int j = i + 1; j < v.size(); j++)
        {
            if(v[i] + v[j] == k)
            {
                cout << v[i] << ' ' << v[j] << '\n';
                break;
            }
        }
    }  
    return 0;
}