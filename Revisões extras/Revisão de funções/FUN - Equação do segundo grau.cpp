#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

float calc_delta(float a, float b, float c)
{
    float delta;
    delta = (b * b) - (4 * a * c);
    return delta;
}

int calc_raizes(float a, float b, float c, float &x1, float &x2)
{
    float delta;
    delta = calc_delta(a, b, c);
    if (delta < 0)
    {
        return 0;
    }
    else
    {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        return 1;
    }
}

int main()
{

    int a, b, c;
    float x1, x2;
    int existe_raizes;

    cin >> a >> b >> c;

    // if x1 and x2 are -0.00 and 0.00, they receive the value 0 and not -0.00

    existe_raizes = calc_raizes(a, b, c, x1, x2);

    if (existe_raizes == 0)
    {
        cout << "Nao ha raizes reais" << endl;
    }
    else
    {
        // show the minor first
        if (x1 == 0 && x2 == 0)
        {
            cout << "x = 0" << endl;
        }
        else
        {

            if (x1 < x2)
            {
                cout << fixed << setprecision(2) << "x1 = " << x1 << endl;
                cout << fixed << setprecision(2) << "x2 = " << x2 << endl;
            }
            else
            {
                cout << fixed << setprecision(2) << "x1 = " << x2 << endl;
                cout << fixed << setprecision(2) << "x2 = " << x1 << endl;
            }
        }
    }

    return 0;
}