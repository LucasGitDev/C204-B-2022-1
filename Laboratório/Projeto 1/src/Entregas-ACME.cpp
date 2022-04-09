#include <iostream>
#include <list>
#include "Dijkstra.cpp"

using namespace std;

void limpar_memoria(int nVertices, list<no> adj[])
{
    for (int i = 0; i < nVertices; i++)
    {
        adj[i].clear();
    }
}

struct compra
{
    int local;
    int peso;
};

struct entregador
{
    int id;
    int distanciaInicialAteMercado = 0;
    int localAtual = -1;
    int tempoAtual = 0;
    int tempoTotal = 0;
    int caminho[100];
};

int main()
{

    int qtdLocais;                // quantidade de locais
    int qtdEntregas;              // quantidade de entregas
    int qtdEntregadores;          // quantidade de
    entregador entregadores[100]; // vetor de entregadores
    int pesoMaximoEntrega;        // peso máximo de uma entrega
    int mercado;                  // mercado de origem
    compra entregas[100];         // entregas
    compra pack_entrega[10][10];  // pack_entrega[i] = j, entrega i é para o entregador j

    list<no> adj[20];
    int origem, destino, tempo;

    int naoOrientado = 0;

    cout << "Quantidade de locais: \t";
    cin >> qtdLocais;

    cout << "Qual o numero referente ao local de origem: \t";
    cin >> mercado;

    cout << "Entre com o grafo dos locais (-1 -1 -1 para sair): \n"
         << endl;
    cin >> origem >> destino >> tempo;
    while (origem != -1 && destino != -1 && tempo != -1)
    {
        cria_aresta(adj, origem, destino, tempo, naoOrientado);
        cin >> origem >> destino >> tempo;
    }

    cout << "Quantidade de entregas: \t";
    cin >> qtdEntregas;

    cout << "Entre com as entregas: \n";
    for (int i = 0; i < qtdEntregas; i++)
    {
        cout << "Entrega para local: \t";
        cin >> entregas[i].local;
        cout << "Peso: \t";
        cin >> entregas[i].peso;
    }

    cout << "Quantidade de entregadores: ";
    cin >> qtdEntregadores;

    cout << "Peso maximo por entregador: ";
    cin >> pesoMaximoEntrega;

    cout << "Entre com a distancia inicial do entregador até o mercado: \n";
    for (int i = 0; i < qtdEntregadores; i++)
    {
        cout << "Entregador " << i + 1 << ": \t";
        entregadores[i].id = i;
        cin >> entregadores[i].distanciaInicialAteMercado;
    }

    // O algoritmo deve verificar quais entregas serão atendidas por cada entregador
    // e calcular o tempo total de cada entregador.

    // Ordenar as entregas por maior peso
    for (int i = 0; i < qtdEntregas; i++)
    {
        for (int j = i + 1; j < qtdEntregas; j++)
        {
            if (entregas[i].peso < entregas[j].peso)
            {
                compra aux = entregas[i];
                entregas[i] = entregas[j];
                entregas[j] = aux;
            }
        }
    }

    // Ordenar entregadores por distancia inicial
    for (int i = 0; i < qtdEntregadores; i++)
    {
        for (int j = i + 1; j < qtdEntregadores; j++)
        {
            if (entregadores[i].distanciaInicialAteMercado > entregadores[j].distanciaInicialAteMercado)
            {
                entregador aux = entregadores[i];
                entregadores[i] = entregadores[j];
                entregadores[j] = aux;
            }
        }
    }




    return 0;
}