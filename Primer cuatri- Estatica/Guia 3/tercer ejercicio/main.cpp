#include <iostream>

using namespace std;

float calcularPorcentajeDiferencia (float a, float b);

int main()
{

float n1;
float n2;
float mostrar;

cout << "Numero 1: ";
cin >> n1;

cout << "Numero 2: ";
cin >> n2;

if (n2 >= n1){

mostrar = calcularPorcentajeDiferencia(n1,n2);

cout << "Porcentaje de la diferencia es: " << mostrar << endl;

} else { cout << "Error, el " << n1 << " es mayor al " << n2 << endl;}



    return 0;
}


float calcularPorcentajeDiferencia (float a, float b){

float resultado;

resultado = ((b-a) *100)/(a+b);

return resultado;

}
