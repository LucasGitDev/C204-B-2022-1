#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double raiz_quadrada(double x, double x0, double epsilon)
{

    if (abs((x0 * x0) - x) <= epsilon)
    {
        return x0;
    }
    else
    {
        return raiz_quadrada(x, (((x0 * x0) + x) / (2 * x0)), epsilon);
    }

    return 0;
}

int main()
{

    double x, x0, e;

    cin >> x >> x0 >> e;

    cout << fixed << setprecision(4) << raiz_quadrada(x, x0, e) << endl;

    return 0;
}