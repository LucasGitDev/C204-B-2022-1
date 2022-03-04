#include <iostream>

using namespace std;

// busca binária recursiva
int busca_binaria_recursiva(int *vetor, int inicio, int fim, int valor) {
    if (inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == valor) {
        return meio;
    } else if (vetor[meio] > valor) {
        return busca_binaria_recursiva(vetor, inicio, meio - 1, valor);
    } else {
        return busca_binaria_recursiva(vetor, meio + 1, fim, valor);
    }
}

// busca binária iterativa
int busca_binaria_iterativa(int *vetor, int inicio, int fim, int valor) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == valor) {
            return meio;
        } else if (vetor[meio] > valor) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}



int main() {

    int N, X, pos;

    N = 10000;

    int *vetor = new int[N];

    for (int i = 0; i < N; i++) {
        vetor[i] = i;
    }

    X = random() % N;

    pos = busca_binaria_recursiva(vetor, 0, N - 1, X);

    cout << pos << endl;

    pos = busca_binaria_iterativa(vetor, 0, N - 1, X);

    cout << pos << endl;


    return 0;
}