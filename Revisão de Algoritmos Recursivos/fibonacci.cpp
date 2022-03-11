#include <iostream>

using namespace std;

int fibonacci(int n) // O(2^n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int[] sequencia_fibonacci(int n) // O(n)
{
    int[] sequencia = new int[n];
    sequencia[0] = 0;
    sequencia[1] = 1;
    for (int i = 2; i < n; i++)
    {
        sequencia[i] = sequencia[i - 1] + sequencia[i - 2];
    }
    return sequencia;
}

int main() {

    int lista[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 10; i++)
    {
        cout << "Fibonacci de " << lista[i] << " = " << fibonacci(lista[i]) << endl;
    }

    return 0;
}