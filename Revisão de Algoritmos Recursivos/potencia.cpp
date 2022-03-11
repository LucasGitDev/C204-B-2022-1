#include <iostream>

using namespace std;

int potencia(int base, int expoente)
{
    if (expoente == 0)
        return 1;
    return base * potencia(base, expoente - 1);
}

int main() {

    int a, n;
    
    cin >> a >> n;

    cout << potencia(a, n) << endl;

    return 0;
}