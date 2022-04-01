#include <iostream>

using namespace std;

void soma(int x, int y, int *s){
    *s = x + y;
}

void soma_com_endereco(int x, int y, int &s){
    s = x + y;
}

int main() {

    int a = 2;
    int b = 3;
    int c = 0;

    soma(a, b, &c);

    cout << a << b << c << endl;

    soma_com_endereco(a, b, c);

    cout << a << b << c << endl;

    return 0;
}