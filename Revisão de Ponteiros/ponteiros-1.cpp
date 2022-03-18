#include <iostream>

using namespace std;

int main()
{

    int *pti;
    int i = 10;
    pti = &i;

    cout << "O endereço de i é: " << &i << endl;
    cout << "O endereço de pti é: " << &pti << endl;
    cout << "O valor de i é: " << i << endl;
    cout << "O valor de *pti é: " << *pti << endl;

    cout << "###########################" << endl;

    int a;
    int *b;
    a = 2;
    b = &a;

    cout << "O endereço de a é: " << &a << endl;
    cout << "O endereço de b é: " << &b << endl;
    cout << "O valor de a é: " << a << endl;
    cout << "O valor de *b é: " << *b << endl;

    cout << "###########################" << endl;

    i = 99;
    int j;
    int *p;
    p = &i;
    j = *p + 100;

    cout << j << endl;

    return 0;
}