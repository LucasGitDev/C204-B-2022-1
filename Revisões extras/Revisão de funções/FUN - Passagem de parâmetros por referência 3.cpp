#include <iostream>

using namespace std;

void troca(int &X, int &Y) {
    int aux;
    aux = X;
    X = Y;
    Y = aux;
}

int main() {
    int X, Y;
    cin >> X >> Y;
    troca(X, Y);
    cout << X << " " << Y << endl;

    return 0;
}