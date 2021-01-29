#include <iostream>

using namespace std;

bool esPrimo(int n);

int main()
{

int numero;


cout << "Ingrese un numero para saber si es primo o no es primo: ";
cin >> numero;

while (numero<=0){

    cout << "Ingrese un numero valido: ";
    cin >> numero;

}

if ((esPrimo(numero))){

    cout << "El numero es primo " << endl;

    } else { cout << "No es primo" << endl;}






    return 0;
}

bool esPrimo(int n){

bool resultado = true;

for (int i = 2; i <= n/2; ){

    if (n%i == 0){ // si es divisible por alguno menor a n

        resultado = false;
        break;
    }

    return resultado;
}

}
