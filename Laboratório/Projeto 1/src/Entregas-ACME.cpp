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
    int id;
    int local;
    int peso;
};

struct entregador
{
    int id;
    int distanciaInicialAteMercado;
    int localAtual;
    int tempoTotal;
    int pesoTotal;
    list<int> caminho;
};

bool compra_ja_foi_entregue(int idCompra, list<int> entregas)
{
    for (list<int>::iterator it = entregas.begin(); it != entregas.end(); it++)
    {
        if (*it == idCompra)
        {
            return true;
        }
    }
    return false;
}

bool is_in_list(int id, list<int> lista)
{
    for (list<int>::iterator it = lista.begin(); it != lista.end(); it++)
    {
        if (*it == id)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    int qtdLocais;                // quantidade de locais
    int qtdEntregas;              // quantidade de entregas
    int qtdEntregadores;          // quantidade de
    entregador entregadores[100]; // vetor de entregadores
    int pesoMaximoEntrega;        // peso maximo de uma entrega
    int mercado;                  // mercado de origem
    compra entregas[100];         // entregas
    compra pack_entrega[10][10];  // pack_entrega[i][n] -> i-esimo entregador, n-esimo pack (quais packs vai pegar)
    int qtdPacksMontados = 0;
    list<int> comprasJaProcessadas; // compras ja processadas

    list<no> adj[20];
    int origem, destino, tempo;

    int naoOrientado = 0;

    cout << "Quantidade de locais: \t";
    cin >> qtdLocais;

    cout << "Qual o numero referente ao local de origem: \t";
    cin >> mercado;

    cout << "Entre com o grafo dos locais (-1 -1 -1 para sair):" << endl;
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
        entregas[i].id = i;
    }

    cout << "Quantidade de entregadores: ";
    cin >> qtdEntregadores;

    cout << "Peso maximo por entregador: ";
    cin >> pesoMaximoEntrega;

    cout << "Entre com a distancia inicial do entregador ate o mercado: \n";
    for (int i = 0; i < qtdEntregadores; i++)
    {
        cout << "Entregador " << i + 1 << ": \t";
        entregadores[i].id = i;
        cin >> entregadores[i].distanciaInicialAteMercado;
        entregadores[i].localAtual = -1;
        entregadores[i].tempoTotal = 0;
        entregadores[i].pesoTotal = 0;
    }

    // O algoritmo deve verificar quais entregas serao atendidas por cada entregador
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

    // Verificar quais entregas serao atendidas por cada entregador levando em consideraçao o peso maximo
    for (int i = 0; i < qtdEntregadores; i++)
    {
        if (comprasJaProcessadas.size() == qtdEntregas)
            break;

        int j = 0;
        int k = 0;
        while (j < qtdEntregas)
        {
            if (!compra_ja_foi_entregue(entregas[j].id, comprasJaProcessadas) && entregadores[i].pesoTotal + entregas[j].peso <= pesoMaximoEntrega)
            {
                comprasJaProcessadas.push_back(entregas[j].id);
                entregadores[i].pesoTotal += entregas[j].peso;
                pack_entrega[i][k].id = entregas[j].id;
                pack_entrega[i][k].local = entregas[j].local;
                pack_entrega[i][k].peso = entregas[j].peso;
                k++;
                qtdPacksMontados++;
            }
            j++;
        }
        pack_entrega[i][k].local = -1; // indica fim do pack
        pack_entrega[i][k].peso = -1;  // indica fim do pack
    }

    // Calcular o tempo total de cada entregador
    int packsContabilizados = 0;
    for (int i = 0; i < qtdEntregadores; i++)
    {

        int j = 0;

        if (entregadores[i].localAtual == -1)
        {
            entregadores[i].localAtual = mercado;
            entregadores[i].caminho.push_back(entregadores[i].localAtual);
            entregadores[i].tempoTotal = entregadores[i].distanciaInicialAteMercado;
        }

        while (pack_entrega[i][j].local != -1 && packsContabilizados < qtdPacksMontados)
        {
            if (!is_in_list(pack_entrega[i][j].local, entregadores[i].caminho))
            {
                return_dijkstra aux;
                aux = dijkstra(adj, qtdLocais, entregadores[i].localAtual, pack_entrega[i][j].local);
                entregadores[i].tempoTotal += aux.distancia;
                entregadores[i].localAtual = pack_entrega[i][j].local;
                if (j != 0)
                {   
                    // remover o primeiro elemento de aux.caminho
                    aux.caminho.erase(aux.caminho.begin());
                    entregadores[i].caminho.insert(entregadores[i].caminho.end(), aux.caminho.begin(), aux.caminho.end());
                }
                else
                {
                    entregadores[i].caminho = aux.caminho;
                }
            }
            j++;
            packsContabilizados++;
        }
    }

    // TODO Verificar se algum entregador ficou sem entregas, se sim, escolher o entregador com o maior tempo total e retirar a menor compra

    // Imprimir o resultado
    cout << "\n############################################################" << endl;
    cout << "############################################################" << endl;
    cout << "############################################################" << endl;
    cout << "############################################################" << endl;
    cout << "Resultado: \n\n\n";
    int cont = 0;
    for (int i = 0; i < qtdEntregadores; i++)
    {
        cout << "Entregador " << entregadores[i].id + 1 << ": \n";
        cout << "Distancia inicial: " << entregadores[i].distanciaInicialAteMercado << endl;
        cout << "Tempo total: " << entregadores[i].tempoTotal << endl;
        cout << "Local atual: " << entregadores[i].localAtual << endl;
        cout << "Realizou entregas: ";
        for (int j = 0; j < entregadores[i].caminho.size(); j++)
        {
            if (pack_entrega[i][j].local != -1 && cont < qtdPacksMontados)
            {
                cout << pack_entrega[i][j].local << " ";
                cont++;
            }
            else
                break;
        }
        cout << endl;
        cout << "Caminho: ";
        for (list<int>::iterator p = entregadores[i].caminho.begin(); p != entregadores[i].caminho.end(); p++)
        {
            cout << *p << " ";
        }
        cout << endl;
        cout << "################\n\n\n";
    }

    return 0;
}