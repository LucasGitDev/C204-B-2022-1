#include <iostream>

using namespace std;


int main() {

    int v[100];
    int N;
    int *p;
    int maior = -99999;

    cin >> N;

    // Inserir elementos no vetor usando ponteiros
    p = v;
    for (int i = 0; i < N; i++)
        cin >> *p++;

    // Encontrar o maior elemento do vetor
    p = v;
    for (int i = 0; i < N; i++) {
        if (*p > maior)
            maior = *p;
        p++;
    }
    
    cout << maior << endl;


    return 0;
}