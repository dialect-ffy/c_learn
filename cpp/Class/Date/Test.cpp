#include "Date.h"
void TestDate1()
{
    Date d1(2014,4,14);
    Date d2 = d1 + 30000;
    d1.Print();
    d2.Print();
    Date d3(2024,4,14);
    Date d4 = d3 - 5000;
    d3.Print();
    d4.Print();
    Date d5(2024,4,14);
    d5 += -5000;
    d5.Print();
}
void TestDate4()
{
    Date d1(2024, 4, 14);
    Date d2 = d1 + 30000;
    // operator<<(cout, d1)
    cout << d1;
    cout << d2;
    cin >> d1 >> d2;
    cout << d1 << d2;
}
int main()
{
    // TestDate1();
    TestDate4();
    return 0;
}