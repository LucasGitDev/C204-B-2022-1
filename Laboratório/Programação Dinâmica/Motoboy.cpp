#include <iostream>

using namespace std;


int main() {

    int Q; // Quantidade máxima de pizzas
    int N; // Quantidade de pedidos
    int D; // Tempo de duração da entrega do pedido N em minutos
    int X; // Quantidade de pizzas no pedido N
    int tempoTotal = 0; // Tempo total de entrega
    int custotempo[100][100]; // Custo do tempo de entrega

    // Verificar quais pedidos são possíveis de entregar no maior tempo possível
    // OBS: Não é necessário verificar se o pedido N é possível de entregar

    // Entrada
    cin >> Q;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> D >> X;
    }


    // Processamento
    // Verificar possíveis conjuntos de entregas de pedidos que possam ser entregues no tempo máximo
    // OBS: Não é necessário verificar se o pedido N é possível de entregar



    // Saída
    cout << tempoTotal << endl;

    return 0;
}