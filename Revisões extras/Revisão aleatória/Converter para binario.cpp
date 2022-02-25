#include <iostream>
#include <math.h>

using namespace std;

// Função que converte um número decimal para binário e retorna o resultado
int decimalParaBinario(int numeroDecimal) {
    int numeroBinario = 0;
    int resto = 0;
    int contador = 0;

    // Enquanto o número decimal for maior que 0
    while (numeroDecimal > 0) {
        // Obtém o resto da divisão do número decimal por 2
        resto = numeroDecimal % 2;
        // Atualiza o número binário com o resto da divisão
        numeroBinario = numeroBinario + resto * pow(10, contador);
        // Atualiza o número decimal com o número decimal dividido por 2
        numeroDecimal = numeroDecimal / 2;
        // Incrementa o contador
        contador++;
    }

    return numeroBinario;
}

int main() {

    int numeroDecimal;

    cin >> numeroDecimal;

    cout << decimalParaBinario(numeroDecimal) << endl;

    return 0;
}