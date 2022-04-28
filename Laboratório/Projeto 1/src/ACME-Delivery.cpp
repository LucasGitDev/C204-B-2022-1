#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Dijkstra.cpp"

#define NAO_ORIENTADO 0

using namespace std;

struct Compra
{
    int id;
    int local;         // local de origem da Compra
    int peso;          // peso da Compra
    string refer;      // referência da Compra
    int menorTempo;    // menor tempo para entrega da Compra
    list<int> caminho; // caminho para entrega da Compra
    bool processado;   // indica se a Compra já foi processada
    bool jaEntregue;   // indica se a Compra já foi entregue
};

struct Entregador
{
    int id;
    int tempoTotal;                  // tempo total gasto pelo entregador
    int pesoTotal;                   // peso total gasto pelo entregador
    list<int> caminhoPercorrido;     // caminho percorrido pelo entregador
    vector<Compra> comprasEntregues; // compras entregues pelo entregador
};

void limpar_memoria(int nVertices, list<no> adj[]) // limpa a memória alocada para o grafo // Complexidade: O(nVertices)
{
    for (int i = 0; i < nVertices; i++)
    {
        adj[i].clear();
    }
}

Compra getCompraMaiorTempoNaoProcessada(vector<Compra> compras);   // retorna a compra com maior tempo não processada
void sortEntregadores(vector<Entregador> &entregadores);           // ordena os entregadores por tempo total
void sortEntregadoresId(vector<Entregador> &entregadores);         // ordena os entregadores por id
void setCompraProcessada(vector<Compra> &compras, int idCompra);   // seta a compra com id idCompra como processada
void setCompraNaoProcessadaSeNaoEntregue(vector<Compra> &compras); // seta todas as compras como não processadas se não foram entregues
void setCompraEntregue(vector<Compra> &compras, int idCompra);     // seta a compra com id idCompra como entregue

int main() // Complexidade: O(n^3) -> (qtdCompras * qtdLocais ^ 2)
{
    int qtdLocais;              // quantidade de locais
    int qtdEntregadores;        // quantidade de entregadores
    int qtdCompras;             // quantidade de compras
    int mercado;                // local do mercado
    int origem, destino, tempo; // origem, destino e tempo da aresta
    int pesoMaximo;             // peso máximo

    stringstream ss; // stringstream para ler o input
    string saux;     // string auxiliar para ler o input

    list<no> adj[20];                // lista de adjacência
    vector<Compra> compras;          // compras
    vector<Entregador> entregadores; // entregadores

    cout << "Quantidade de locais: \t";
    cin >> qtdLocais;

    cout << "Qual o numero referente ao local de origem: \t";
    cin >> mercado;

    cout << "Entre com o grafo dos locais (-1 -1 -1 para sair):" << endl;
    cin >> origem >> destino >> tempo;
    while (origem != -1 && destino != -1 && tempo != -1)
    {
        cria_aresta(adj, origem, destino, tempo, NAO_ORIENTADO); // Complexidade: O(1)
        cin >> origem >> destino >> tempo;
    }

    cout << "Quantidade de entregas: \t";
    cin >> qtdCompras;

    cout << "Entre com as entregas: \n";
    for (int i = 0; i < qtdCompras; i++) // Complexidade: O(qtdCompras)
    {
        Compra compraaux;
        cout << "Entrega para local: \t";
        cin >> compraaux.local;
        cout << "Peso da entrega: \t";
        cin >> compraaux.peso;

        // inicialização da referência da compra
        compraaux.id = i;
        compraaux.menorTempo = INT_MAX;
        compraaux.processado = false;

        compraaux.refer = "Compra ";
        ss << compraaux.local;
        ss >> saux;
        compraaux.refer.append(saux);
        ss.clear();

        ss << compraaux.peso;
        ss >> saux;
        compraaux.refer.append(" - ");
        compraaux.refer.append(saux);
        compraaux.refer.append("Kg");
        ss.clear();
        // o valor de compraaux.refer é: "Compra <local> - <peso>Kg"
        compras.push_back(compraaux);
    }

    cout << "Quantidade de entregadores: ";
    cin >> qtdEntregadores;

    cout << "Peso maximo por entregador: ";
    cin >> pesoMaximo;

    cout << "Entre com a distancia inicial do entregador até o mercado: \n";
    for (int i = 0; i < qtdEntregadores; i++) // Complexidade: O(qtdEntregadores)
    {
        Entregador entregadoraux;
        cout << "Entregador " << i + 1 << ": \t";
        entregadoraux.id = i;
        cin >> entregadoraux.tempoTotal; // tempo total gasto pelo entregador para sair do local inicial e ir ao mercado
        entregadoraux.pesoTotal = 0;
        entregadores.push_back(entregadoraux);
    }

    // inicializa o menor tempo de cada Compra (entregar compra[x] no local y saindo do mercado)
    for (int i = 0; i < qtdCompras; i++) // Complexidade: O(qtdCompras)
    {
        return_dijkstra aux;
        aux = dijkstra(adj, qtdLocais + 1, mercado, compras[i].local); // Complexidade: O(n^2) -> (qtdLocais ^ 2)
        compras[i].menorTempo = aux.distancia;
        compras[i].caminho = aux.caminho;
    }

    // ordenar entregadores por menor tempo total para c++98
    sortEntregadores(entregadores);

    // Adicionar compras para entregadores
    for (int i = 0; i < entregadores.size(); i++) // Complexidade: (entregadores.size() * compras.size())
    {
        for (int j = 0; j < compras.size(); j++) // Complexidade: (compras.size())
        {
            Compra compra_aux = getCompraMaiorTempoNaoProcessada(compras); // se uma compra não for adicionada, ficará repetido.
            // em caso da compra_aux ter menorTempo == 0, significa que todas as compras já foram entregues
            // então não é necessário adicionar mais compras para os entregadores

            if (compra_aux.menorTempo != 0)
            {
                if (entregadores[i].caminhoPercorrido.size() == 0)
                {
                    if (entregadores[i].pesoTotal + compra_aux.peso <= pesoMaximo && !compra_aux.jaEntregue)
                    {
                        entregadores[i].comprasEntregues.push_back(compra_aux);
                        entregadores[i].pesoTotal += compra_aux.peso;
                        entregadores[i].tempoTotal += compra_aux.menorTempo;
                        entregadores[i].caminhoPercorrido = compra_aux.caminho;
                        setCompraEntregue(compras, compra_aux.id);
                    }

                    if (entregadores[i].pesoTotal == pesoMaximo)
                    {
                        break;
                    }
                }
                else
                { // Verificar se alguma compra não processada está no caminho do entregador

                    if (find(entregadores[i].caminhoPercorrido.begin(), entregadores[i].caminhoPercorrido.end(), compra_aux.local) != entregadores[i].caminhoPercorrido.end())
                    {
                        if (entregadores[i].pesoTotal + compra_aux.peso <= pesoMaximo && !compra_aux.jaEntregue)
                        {
                            entregadores[i].comprasEntregues.push_back(compra_aux);
                            entregadores[i].pesoTotal += compra_aux.peso;
                            entregadores[i].tempoTotal += compra_aux.menorTempo;
                            setCompraEntregue(compras, compra_aux.id);
                        }
                    }

                    if (entregadores[i].pesoTotal == pesoMaximo)
                    {
                        break;
                    }
                }
            }
            setCompraProcessada(compras, compra_aux.id);
        }
        // remover todas as repetições do mercado do caminho percorrido
        entregadores[i].caminhoPercorrido.remove(mercado);
        entregadores[i].caminhoPercorrido.push_front(mercado);
        setCompraNaoProcessadaSeNaoEntregue(compras);
    }

    // Verificar se alguma compra não foi entregue, se sim, adicionar ao entregador mais proximo
    for (int i = 0; i < compras.size(); i++) // Complexidade: (compras.size() * entregadores.size())
    {
        if (!compras[i].jaEntregue)
        {
            int menorTempo = INT_MAX;
            int menorTempoEntregador = 0;
            for (int j = 0; j < entregadores.size(); j++) // Complexidade: (entregadores.size())
            {
                // medir distancia do entregador até a compra considerando o caminho percorrido
                return_dijkstra aux;
                aux = dijkstra(adj, qtdLocais + 1, entregadores[j].caminhoPercorrido.front(), compras[i].local);
                if (aux.distancia + entregadores[j].tempoTotal < menorTempo)
                {
                    menorTempo = aux.distancia + entregadores[j].tempoTotal;
                    menorTempoEntregador = j;
                }
            }

            int localEntregador = entregadores[menorTempoEntregador].caminhoPercorrido.back();

            // mudar caminho da compra e tempo
            return_dijkstra aux;
            aux = dijkstra(adj, qtdLocais + 1, localEntregador, compras[i].local);

            compras[i].caminho = aux.caminho;
            compras[i].menorTempo = aux.distancia;

            // adicionar compra ao entregador

            entregadores[menorTempoEntregador].comprasEntregues.push_back(compras[i]);
            entregadores[menorTempoEntregador].pesoTotal += compras[i].peso;
            entregadores[menorTempoEntregador].tempoTotal += compras[i].menorTempo;
            compras[i].caminho.pop_front();
            entregadores[menorTempoEntregador].caminhoPercorrido.insert(entregadores[menorTempoEntregador].caminhoPercorrido.end(), compras[i].caminho.begin(), compras[i].caminho.end());
            setCompraEntregue(compras, compras[i].id);
        }
    }

    // Ordenar entregadores por menor tempo total
    sortEntregadoresId(entregadores);

    // Imprimir entregadores
    cout << "\n\n################################" << endl;
    cout << "################################" << endl;
    cout << "########## Resultados ##########" << endl;
    cout << "################################" << endl;

    cout << "\nEntregadores: \n\n";
    for (int i = 0; i < entregadores.size(); i++) // Complexidade: (entregadores.size() * (entregadores[i].comprasEntregues.size()) * (entregadores[i].caminhoPercorrido.size()))
    {
        cout << "Entregador " << entregadores[i].id + 1 << ": " << endl;
        cout << "Tempo total: " << entregadores[i].tempoTotal << endl;
        cout << "Peso total: " << entregadores[i].pesoTotal << endl;
        cout << "Compras entregues: " << entregadores[i].comprasEntregues.size() << endl;
        for (int j = 0; j < entregadores[i].comprasEntregues.size(); j++) // Complexidade: (entregadores[i].comprasEntregues.size())
        {
            cout << "\t" << entregadores[i].comprasEntregues[j].refer << "\n";
        }
        cout << "\nCaminho percorrido: ";
        for (list<int>::iterator p = entregadores[i].caminhoPercorrido.begin(); p != entregadores[i].caminhoPercorrido.end(); p++) // Complexidade: (entregadores[i].caminhoPercorrido.size())
        {
            cout << *p << " ";
        }
        cout << "\n################################\n\n";

        entregadores[i].caminhoPercorrido.clear();
        entregadores[i].comprasEntregues.clear();
    }

    // limpar memoria das listas de compras e entregadores
    limpar_memoria(qtdLocais, adj);
    for (int i = 0; i < qtdCompras; i++) // Complexidade: (qtdCompras)
    {
        compras[i].caminho.clear();
    }
    compras.clear();
    entregadores.clear();

    return 0;
}

Compra getCompraMaiorTempoNaoProcessada(vector<Compra> compras) // Complexidade: (compras.size())
{
    Compra compraM;
    compraM.menorTempo = 0;

    for (int i = 0; i < compras.size(); i++)
    {
        if (compras[i].menorTempo > compraM.menorTempo && compras[i].processado == false)
        {
            compraM = compras[i];
        }
    }

    return compraM;
}

// Torna uma compra processada dado o seu id
void setCompraProcessada(vector<Compra> &compras, int idCompra) // Complexidade: (compras.size())
{
    for (int i = 0; i < compras.size(); i++)
    {
        if (compras[i].id == idCompra)
        {
            compras[i].processado = true;
        }
    }
}

void setCompraNaoProcessadaSeNaoEntregue(vector<Compra> &compras) // Complexidade: (compras.size())
{
    for (int i = 0; i < compras.size(); i++)
    {
        if (!compras[i].jaEntregue)
        {
            compras[i].processado = false;
        }
    }
}

void setCompraEntregue(vector<Compra> &compras, int idCompra) // Complexidade: (compras.size())
{
    for (int i = 0; i < compras.size(); i++)
    {
        if (compras[i].id == idCompra)
        {
            compras[i].jaEntregue = true;
        }
    }
}

void sortEntregadores(vector<Entregador> &entregadores) // Complexidade: (entregadores.size() ^ 2)
{
    for (int i = 0; i < entregadores.size(); i++)
    {
        for (int j = 0; j < entregadores.size(); j++)
        {
            if (entregadores[i].tempoTotal < entregadores[j].tempoTotal)
            {
                Entregador aux = entregadores[i];
                entregadores[i] = entregadores[j];
                entregadores[j] = aux;
            }
        }
    }
}

void sortEntregadoresId(vector<Entregador> &entregadores) // Complexidade: (entregadores.size() ^ 2)
{
    for (int i = 0; i < entregadores.size(); i++)
    {
        for (int j = 0; j < entregadores.size(); j++)
        {
            if (entregadores[i].id < entregadores[j].id)
            {
                Entregador aux = entregadores[i];
                entregadores[i] = entregadores[j];
                entregadores[j] = aux;
            }
        }
    }
}