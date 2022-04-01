#include <iostream>

using namespace std;

int main()
{

    int v[100];
    int *p;
    int N;
    int pares_e_positivos = 0;

    cin >> N;

    // Inserir elementos no vetor usando ponteiros
    p = v;
    for (int i = 0; i < N; i++)
        cin >> *p++;

    // Iterar sobre o vetor usando ponteiros
    p = v;
    for (int i = 0; i < N; i++)
    {
        if (*p % 2 == 0 && *p > 0)
            pares_e_positivos++;
        p++;
    }

    cout << pares_e_positivos << endl;

    return 0;
}