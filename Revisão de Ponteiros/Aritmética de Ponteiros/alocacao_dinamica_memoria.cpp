#include <iostream>

using namespace std;

struct dado
{
    int info1;
    int info2;
};

void alocacaoDinamicaDeUmaStruct()
{

    dado *pessoa = NULL;

    pessoa = new dado;

    pessoa->info1 = 2;
    pessoa->info2 = 3;

    cout << pessoa->info1 << endl;
    cout << pessoa->info2 << endl;

    delete pessoa;  // Libera a memória alocada dinamicamente
}

void alocacaoDinamicaDeVetor()
{
    int *vetor = NULL; // Declara um ponteiro para inteiro
    int N; // Número de elementos do vetor
    int i; // Índice do vetor

    // Leitura do tamanho do vetor

    cin << N;

    // Alocando memória para o vetor

    vetor = new int[N];

    // Leitura dos elementos do vetor

    for (i = 0; i < N; i++)
        cin >> vetor[i];

    // Impressão dos elementos do vetor

    for (int i = 0; i < N; i++)
        cout << vetor[i] << endl;

    // Liberação da memória alocada dinamicamente

    delete[] vetor;  // Libera a memória alocada dinamicamente
}

int main()
{

    alocacaoDinamicaDeVetor();

    return 0;
}