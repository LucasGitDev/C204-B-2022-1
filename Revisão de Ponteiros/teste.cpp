#include <iostream>

using namespace std;

int main()
{

    int x, y;
    int *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;

    cout << x << " "<< y << *p;


    return 0;
}