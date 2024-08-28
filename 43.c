#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double A, B, C;
    
    // Lê os valores de A, B e C
    cin >> A >> B >> C;
    
    // Define o valor de pi
    const double pi = 3.14159;
    
    // Calcula as áreas conforme descrito no problema
    double areaTriangulo = (A * C) / 2.0;
    double areaCirculo = pi * pow(C, 2);
    double areaTrapezio = ((A + B) * C) / 2.0;
    double areaQuadrado = B * B;
    double areaRetangulo = A * B;
    
    // Define a precisão para 3 casas decimais
    cout << fixed << setprecision(3);
    
    // Imprime os resultados
    cout << "TRIANGULO: " << areaTriangulo << endl;
    cout << "CIRCULO: " << areaCirculo << endl;
    cout << "TRAPEZIO: " << areaTrapezio << endl;
    cout << "QUADRADO: " << areaQuadrado << endl;
    cout << "RETANGULO: " << areaRetangulo << endl;

    return 0;
}
