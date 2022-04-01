#include <iostream>
#include <iomanip>

using namespace std;

struct dado
{
    int nota1;
    int nota2;
    int nota3;
    int nota4;
    double media;
};

int main() {

    dado *pessoa = NULL;

    pessoa = new dado;

    cin >> pessoa->nota1 >> pessoa->nota2 >> pessoa->nota3 >> pessoa->nota4;

    pessoa->media = (pessoa->nota1 + pessoa->nota2 + pessoa->nota3 + pessoa->nota4) / 4.0;

    cout << fixed << setprecision(2) << pessoa->media << endl;

    return 0;
}