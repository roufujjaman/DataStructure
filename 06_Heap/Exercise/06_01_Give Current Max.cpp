#include <bits/stdc++.h>

using namespace std;
class Student
{
    public:
        string name;
        int roll;
        int marks;
        Student(string name, int roll, int marks)
        {
            this->name = name;
            this->roll = roll;
            this->marks = marks;
        }
};
class compare
{
    public:
        bool operator()(Student a, Student b)
        {
            if (a.marks < b.marks) return true;
            else if(a.marks > b.marks) return false;
            else
            {
                if(a.roll > b.roll) return true;
                else return false;
            }
            
        }
};
int main()
{
    // Write your code here
    priority_queue<Student, vector<Student>, compare> pq;
    int count_val, query_val;
    cin >> count_val;
    for (int i = 0; i < count_val; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }
    cin >> count_val;
    for (int i = 0; i < count_val; i++)
    {
        cin >> query_val;
        if (query_val == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student obj(name, roll, marks);
            pq.push(obj);
            cout << pq.top().name << ' ' << pq.top().roll << ' ' << pq.top().marks << '\n';
        }
        else if (query_val == 1)
        {
            if(pq.empty()) cout << "Empty" << '\n';
            else cout << pq.top().name << ' ' << pq.top().roll << ' ' << pq.top().marks << '\n';
        }
        else if (query_val == 2)
        {
            if(!pq.empty()) pq.pop();
            if(pq.empty()) cout << "Empty" << '\n';
            else cout << pq.top().name << ' ' << pq.top().roll << ' ' << pq.top().marks << '\n';
        }
    }
    return 0;
}