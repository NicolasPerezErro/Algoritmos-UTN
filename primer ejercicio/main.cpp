#include <iostream>

using namespace std;

/*
EJERCICIO: SUMAR, RESTAR Y MULTIPLICAR 2 NUMEROS ENTEROS
*/

int main()
{

int numero1;
int numero2;
int sum = 0;
int rest = 0;
int multiplic = 0;

cout << "N1: ";
cin >> numero1;

cout << "N2:";
cin >> numero2;

sum = numero1 + numero2;
rest = numero1 - numero2;
multiplic = numero1*numero2;


cout << "Suma: " << sum << endl;
cout << "Multiplicacion: " << multiplic << endl;

if (rest >= 0){

    cout << "Resta: " << rest << endl;
} else{

    cout << "La resta es menor a 0 " << endl;

}




    return 0;
}
