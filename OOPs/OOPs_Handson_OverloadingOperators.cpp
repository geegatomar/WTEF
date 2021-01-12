#include <bits/stdc++.h>
using namespace std;

class item
{
public:
    int id, price;
    string doe;

    item(int id, int price, string doe)
    {
        this->id = id;
        this->price = price;
        this->doe = doe;
    }
};

int operator+(item i1, item i2) // operator overloading (overloading the meaning of the + operator)
{
    return i1.price + i2.price;
}

int main()
{
    item i1(3, 4, "jan8"), i2(4, 100, "jan13");
    cout << i1 + i2 << endl;
}