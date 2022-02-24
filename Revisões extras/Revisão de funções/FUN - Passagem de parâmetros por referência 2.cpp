#include <iostream>
#include <iomanip>

using namespace std;

void converte(float F, float &C, float &K) {
    C = (F - 32) * 5 / 9;
    K = C + 273;
}

int main( ) {

    float F, C, K;

    cin >> F;

    converte(F, C, K);

    cout << fixed << setprecision(2) << endl;
    cout << "Celsius: " << C << endl;  
    cout << "Kelvin: " << K << endl;

    return 0;
}
