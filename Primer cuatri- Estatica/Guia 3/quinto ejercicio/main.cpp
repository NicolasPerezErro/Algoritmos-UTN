#include <iostream>

using namespace std;

double pow (double base, double exponente);

int main()
{

double b;
double e;
double resultado;

cout << "Base: ";
cin >> b;

cout << "Exponente: ";
cin >> e;

resultado = pow(b,e);

cout << "La potencia es: " << resultado << endl;



    return 0;
}


double pow (double base, double exponente){

double potencia = 1;

for (int i = 0; i < exponente; i ++){

    potencia = potencia * base;
}

return potencia;
}
