#include <iostream>
#include <climits>

using namespace std;


int main() {

    int custo[100][100]; // 100 -> numero maximo de cidades
	int casa_inicial = 0;
	int n;
	
	cin >> n;

    for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++) 
		{
			cin >> custo[i][j];
			custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
		}
    
    bool vis[100]; // marca se ja visitou ou nao uma cidade
	int menor_custo; // menor custo da viagem
	int custo_at; // menor custo atual
	int casa_atual; // cidade atual
	int proxima_casa; // proxima cidade
		
	// inicializando vetor vis (nenhuma cidade foi visitada no inicio)
	for(int i = 0;i < n;i++)
		vis[i] = false;
	
	// guloso
	menor_custo = 0;
	casa_atual = casa_inicial;
	for(int i = 0;i < n-1;i++) // n-1 vezes = qnt de caminhos (exceto a volta para a cidade inicial)
	{
		vis[casa_atual] = true; // marco que ja visitei a cidade atual
		// encontrar qual a proxima cidade mais proxima
		custo_at = INT_MAX;
		for(int j = 0;j < n;j++)
		{
			if(!vis[j] && custo_at > custo[casa_atual][j])
			{
				proxima_casa = j;
				custo_at = custo[casa_atual][j];
			}	
		}
		menor_custo += custo_at;
		casa_atual = proxima_casa;
	}
	menor_custo += custo[casa_atual][casa_inicial];
	cout << "Menor custo = " << menor_custo << endl;

    return 0;
}