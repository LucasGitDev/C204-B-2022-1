#include <iostream>

using namespace std;

struct dado
{
    char nome[100];
    int n1;
    int n2;
    int n3;
    int n4;
};

int strongest(dado atletas[], int nAtletas)
{
    int maior = 0;
    int indice = 0;
    for (int i = 0; i < nAtletas; i++)
    {
        if (atletas[i].n1 + atletas[i].n2 + atletas[i].n3 + atletas[i].n4 > maior)
        {
            maior = atletas[i].n1 + atletas[i].n2 + atletas[i].n3 + atletas[i].n4;
            indice = i;
        }
    }
    return indice;
}

int main()
{

    int N;
    dado *atletas;
    cin >> N;
    atletas = new dado[N];

    // leitura dos dados
    for (int i = 0; i < N; i++)
    {
        cin.ignore();
        cin.getline(atletas[i].nome, 100);
        cin >> atletas[i].n1 >> atletas[i].n2 >> atletas[i].n3 >> atletas[i].n4;
    }

    // calculo do mais forte
    int indice = strongest(atletas, N);

    // impressao do nome do mais forte
    cout << "Vencedor: " << atletas[indice].nome << endl;

    return 0;
}