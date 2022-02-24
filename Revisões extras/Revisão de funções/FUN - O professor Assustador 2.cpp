#include <iostream>
#include <iomanip>

using namespace std;

float media(int notas[], int nAlunos)
{
    float media = 0;
    for (int i = 0; i < nAlunos; i++)
    {
        media += notas[i];
    }
    return media / nAlunos;
}

int nAbaixo(int notas[], int nAlunos, float media)
{
    int nAbaixo = 0;
    for (int i = 0; i < nAlunos; i++)
    {
        if (notas[i] < media)
        {
            nAbaixo++;
        }
    }
    return nAbaixo;
}

int nAcima(int notas[], int nAlunos, float media)
{
    int nAcima = 0;
    for (int i = 0; i < nAlunos; i++)
    {
        if (notas[i] > media)
        {
            nAcima++;
        }
    }
    return nAcima;
}

int main()
{

    int nAlunos;
    int *notas = NULL;
    int *p;

    cin >> nAlunos;
    notas = new int[nAlunos];

    for (p = notas; p < notas + nAlunos; p++)
    {
        cin >> *p;
    }

    cout << fixed << setprecision(2) << "Media da turma = " << media(notas, nAlunos) << endl;

    cout << "Alunos com nota abaixo da media: " << nAbaixo(notas, nAlunos, media(notas, nAlunos)) << endl;
    cout << "Alunos com nota acima da media: " << nAcima(notas, nAlunos, media(notas, nAlunos)) << endl;

    return 0;
}