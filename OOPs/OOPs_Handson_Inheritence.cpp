#include <bits/stdc++.h>
using namespace std;

class BaseClass
{
private:
    int private_base;

protected:
    int protected_base;

public:
    int public_base;
};

class DerivedClass : public BaseClass
{
private:
    int derived_private;

public:
    DerivedClass(int pb1, int pb2, int pb3)
    {
        this->protected_base = pb1;
        this->public_base = pb2;
        this->derived_private = pb3;
    }
    void get_members()
    {
        cout << this->derived_private << " " << this->protected_base << " "
             << this->public_base << endl;
    }
};

int main()
{
    DerivedClass D(3, 4, 5);
    D.public_base = 30;
    D.get_members();
}