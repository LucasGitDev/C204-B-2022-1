#include <iostream>

using namespace std;

struct brinquedo 
{
    int tempo;
    int nota;
};

int main() {

    int tempoTotal;
    int qtdBrinquedos;

    int pd[100][100];
    int caminho[100][100];

    brinquedo v[100];

    cin >> tempoTotal;
    cin >> qtdBrinquedos;

    for (int i = 0; i < qtdBrinquedos; i++) {
        cin >> v[i].tempo >> v[i].nota;
    }

    // inicializacao:
    // casos base
    for (int i = 0; i <= tempoTotal; i++) { //Independente de i
        pd[qtdBrinquedos][i] = 0;
    }

    for (int i = 0; i <= qtdBrinquedos; i++) { //Independente de i
        pd[i][0] = 0;
    }

    // programacao dinamica:
    // caso geral
    for(int i = qtdBrinquedos - 1; i >= 0; i--)
		for(int j = 1; j <= tempoTotal; j++)
		{
			int pega, npega; 
			
			npega = pd[i + 1][j];

			if(j >= v[i].tempo) 
				pega = pd[i + 1][j - v[i].tempo] + v[i].nota;
		
			else
				pega = 0; 

			
			
			if(pega > npega) 
			{
				pd[i][j] = pega;
				caminho[i][j] = 1;
			}
			
			else 
			{
				pd[i][j] = npega;
				caminho[i][j] = 0;
			}
		}


    // recuperar nota total
    int i, j;
    i = 0;
    j = tempoTotal;

    int notaTotal = 0;

    while (i != qtdBrinquedos) {
        if (caminho[i][j] == 0) {
            i++;
        } else{
            notaTotal += v[i].nota;
            j -= v[i].tempo;
        }
    }

    cout << notaTotal << endl;

    return 0;
}