#include <iostream>

using namespace std;

int main()
{

    int i;    // contadores
    int x;    // var aux
    int n;    // tamanho do problema
    int cont; // # vezes que a linha x = i*i foi executada

    cin >> n;
    cont = 0;
    for (i = 0; i < n; i++)
    {
        x = i * i;
        cont++;
    }

    cout << cont << endl;
}