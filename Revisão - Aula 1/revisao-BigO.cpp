#include <iostream>

using namespace std;

int main()
{

    int i, j; // contadores
    int x;    // var aux
    int n;    // tamanho do problema
    int cont; // # vezes que a linha x = i*i foi executada

    cin >> n;
    cont = 0;
    // i = 1;

    // while (i < n) // log2(n)
    // {
    //     x = i * i;
    //     i = i*2;
    //     cont++;
    // }

    // for (i = 0; i < n; i = i + 2) // O(n/2)
    // {
    //     x = i * i;
    //     cont++;
    // }

    // for (i = 0; i < n; i) // O(n)
    //     for (j = 0; j < n; j) // O(n)
    //     { 
    //         x = i * i;
    //         cont++; // O(n^2)
    //     }

    for (i = 0; i < n; i++) // O(n)
        j = 1;
        while (j < n) // O(log2(n))
        {
            x = i * i;
            j = j * 2;
            cont++; // O(n log n)
        }

    // while (i > n) { // O(log2(n))
    //     i /= 2;
    // }

    // j=0;
    // while( j < n) { // Total O(n log n)
    //     i=n;
    //     while(i>1) {
    //         cout << i;
    //         i/=2;
    //     }
    //     j++;
    // }


    cout << cont << endl;

    return 0;
}