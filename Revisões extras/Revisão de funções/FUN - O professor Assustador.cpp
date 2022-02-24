#include <iostream>
#include <iomanip>

using namespace std;

float media(int notas[], int nAlunos) {
    float media = 0;
    for (int i = 0; i < nAlunos; i++) {
        media += notas[i];
    }
    return media / nAlunos;
}

int main() {
    
    int nAlunos;
    int *notas = NULL;
    int *p;

    cin >> nAlunos;
    notas = new int[nAlunos];

    for (p = notas; p < notas + nAlunos; p++) {
        cin >> *p;
    }

    cout << fixed << setprecision(2) << "Media da turma = " << media(notas, nAlunos) << endl;


    return 0;
}