#include<bits/stdc++.h>
using namespace std;
// void fun(int * &ptr) //taking pointer + reference as input
// {
//     ptr = NULL;
// }
int main()
{
    int val = 10;
    int *ptr = &val;
    int **ptrr = &ptr;
    int ***ptrrr = &ptrr;
    cout << ***ptrrr << endl;
    return 0;
}