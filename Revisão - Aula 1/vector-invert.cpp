#include <iostream>

using namespace std;

//Função que recebe um vetor de inteiros e o inverte
void inverte(int v[], int tam){
    int aux;
    for(int i = 0; i < tam/2; i++){
        aux = v[i];
        v[i] = v[tam-1-i];
        v[tam-1-i] = aux;
    }
}

int main() {
    int v[] = {1, 2, 3, 4, 5};

    cout << "Antes da inversão: ";
    for(int i = 0; i < 5; i++)
        cout << v[i] << " ";
    cout << endl;

    cout << "Depois da inversão: ";
    inverte(v, 5);
    for(int i = 0; i < 5; i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}