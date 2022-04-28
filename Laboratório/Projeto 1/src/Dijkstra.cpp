#include <iostream>
#include <list>
#define INT_MAX 999

using namespace std;

struct no
{
    int v;    // destino da aresta
    int peso; // peso da aresta
};

struct return_dijkstra
{
    int distancia;
    list<int> caminho;
};

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
    no novo;
    novo.v = v;
    novo.peso = p;
    adj[u].push_back(novo);
    if (orientado == 0)
    {
        novo.v = u;
        adj[v].push_back(novo);
    }
}

return_dijkstra dijkstra(list<no> adj[], int nVertices, int start, int end)
{
    int distancia[nVertices];
    int parent[nVertices];
    bool intree[nVertices];
    int v, destino, weight, dist;
    int custo;
    int i;
    custo = 0;
    for (i = 0; i < nVertices; i++)
    {
        distancia[i] = INT_MAX;
        parent[i] = -1;
        intree[i] = false;
    }

    distancia[start] = 0;
    v = start;

    while (intree[v] == false)
    {
        intree[v] = true;
        for (list<no>::iterator p = adj[v].begin(); p != adj[v].end(); p++)
        {
            destino = p->v;
            weight = p->peso;

            if (distancia[destino] > distancia[v] + weight)
            {
                distancia[destino] = distancia[v] + weight;
                parent[destino] = v;
            }
        }

        v = 0;
        dist = INT_MAX;
        for (i = 0; i < nVertices; i++)
        {
            if (intree[i] == false && distancia[i] < dist)
            {
                dist = distancia[i];
                v = i;
            }
        }
    }

    list<int> pilha;

    pilha.push_front(end);

    for (int pai = parent[end]; pai != -1; pai = parent[pai])
    {
        pilha.push_front(pai);
    }

    return_dijkstra retorno;
    retorno.distancia = distancia[end];
    int j = 0;
    for (list<int>::iterator p = pilha.begin(); p != pilha.end(); p++)
    {
        retorno.caminho.push_back(*p);
        j++;
    }

    return retorno;
}