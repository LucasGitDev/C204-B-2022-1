#include <iostream>
#include <iomanip>

using namespace std;

int calc_a(int x)
{
    int a;

    a = 2 * (x * x) + 3 * x - 1;

    return a;
}
int calc_b(int x)
{
    int b;

    b = x * x * x;

    return b;
}
int calc_c(int y)
{
    int c;

    c = y * y * y;
    
    return c;
}

int main()
{
    int a, b, c, x, y;
    cin >> x >> y;
    // a = 2x^2 + 3x - 1;
    a = calc_a(x);
    cout << "a = " << a << endl;
    // b = x^3;
    b = calc_b(x);
    cout << "b = " << b << endl;
    // c = y^3;
    c = calc_c(y);
    cout << "c = " << c << endl;
    return 0;
}