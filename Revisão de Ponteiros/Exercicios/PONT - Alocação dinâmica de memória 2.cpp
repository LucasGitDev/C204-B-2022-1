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

int main()
{

    dado *pessoa = NULL;
    int N;
    double medias;

    cin >> N;

    pessoa = new dado[N];

    for (int i = 0; i < N; i++)
        cin >> pessoa[i].nota1 >> pessoa[i].nota2 >> pessoa[i].nota3 >> pessoa[i].nota4;

    for (int i = 0; i < N; i++)
    {
        pessoa[i].media = (pessoa[i].nota1 + pessoa[i].nota2 + pessoa[i].nota3 + pessoa[i].nota4) / 4.0;
        medias += pessoa[i].media;
    }

    cout << fixed << setprecision(2) << medias / N << endl;

    return 0;
}