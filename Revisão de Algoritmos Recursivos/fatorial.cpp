#include <iostream>

using namespace std;

int fatorial(int n)
{
    if (n == 0)
        return 1;
    return n * fatorial(n - 1);
}

int main()
{

    int lista[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 10; i++)
    {
        cout << "Fatorial de " << lista[i] << " = " << fatorial(lista[i]) << endl;
    }

    return 0;
}