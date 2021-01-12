#include <bits/stdc++.h>
using namespace std;

class student
{
private:
    int id;
    string name, college;

public:
    student(int id, string name, string college); // constructor itself
    string get_name();
};

student::student(int id, string name, string college)
{
    this->id = id;
    this->name = name;
    this->college = college;
}

string student::get_name()
{
    return this->name;
}

int main()
{
    student s1(9, "shivangi", "nitk");
    student *s2 = new student(4, "lakshya", "iitm");
    cout << s1.get_name() << " " << s2->get_name() << endl;
}