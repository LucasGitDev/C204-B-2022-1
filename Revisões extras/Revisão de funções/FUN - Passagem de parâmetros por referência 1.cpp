#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void media(int x, int y, float &m) {
    m = sqrt(x * y);
}

int main()
{
    int x, y;
    float m;

    cin >> x >> y;
    media(x, y, m);

    cout << fixed << setprecision(2) << endl;
    cout << "Media = " << m << endl;

    return 0;
}