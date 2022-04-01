#include <iostream>

using namespace std;

struct entrega
{
    int tempo;
    int qtdPizzas;
};

int main() {

    int qtdMaxPizzas;
    int qtdPedidos;

    int pd[100][100];
    int caminho[100][100];
    entrega v[100];


    cin >> qtdMaxPizzas;
    cin >> qtdPedidos;

    for (int i = 0; i < qtdPedidos; i++) {
        cin >> v[i].tempo >> v[i].qtdPizzas;
    }

    // inicializacao:
    // casos base

    for(int i = 0; i <= qtdMaxPizzas; i++)
        pd[qtdPedidos][i] = 0;

    for(int i = 0; i <= qtdPedidos; i++)
        pd[i][0] = 0;

    // programacao dinamica:
    // caso geral

    for(int i = qtdPedidos - 1; i >= 0; i--)
		for(int j = 1; j <= qtdMaxPizzas; j++)
		{
			int pega, npega; 
			
			npega = pd[i + 1][j];

			if(j >= v[i].qtdPizzas) 
				pega = pd[i + 1][j - v[i].qtdPizzas] + v[i].tempo;
		
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

    int i,j;
	i = 0;
	j = qtdMaxPizzas;
    int tempoFinal = 0;
	
	while(i != qtdPedidos){ 
		if(caminho[i][j] == 0) 
			i++;
		
		else 
		{
			tempoFinal += v[i].tempo;
			j-= v[i].qtdPizzas; 
		}
	}

    cout << tempoFinal << " min." << endl;

    return 0;
}