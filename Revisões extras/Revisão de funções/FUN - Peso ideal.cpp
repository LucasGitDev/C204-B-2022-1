#include <iostream>
#include <iomanip>

using namespace std;

float ideal(float h, char sexo)
{
    float pesoIdeal;
    if (sexo == 'm' || sexo == 'M')
    {
        pesoIdeal = (72.7 * h) - 58;
    }
    else
    {
        pesoIdeal = (62.1 * h) - 44.7;
    }
    return pesoIdeal;
}

int main()
{
    float altura, pesoIdeal;
    char sexo;

    cin >> altura >> sexo;

    pesoIdeal = ideal(altura, sexo);

    cout << fixed << setprecision(2) << endl;
    cout << "Peso ideal = " << pesoIdeal <<" kg" << endl;

    return 0;
}
