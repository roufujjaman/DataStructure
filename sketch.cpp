#include<bits/stdc++.h>
using namespace std;
int main()
{
     map<string, int> mp;
     mp.insert({"Dilder Hossain", 1});
     mp.insert({"Rejia Khatun", 2});
     mp.insert({"Roufujjaman Rahat", 3});
     mp.insert({"Umme Humayra", 4});


     for (auto it = mp.begin(); it != mp.end(); it++)
     {
          cout << it->first << '\n';
     }
     
     return 0;
}