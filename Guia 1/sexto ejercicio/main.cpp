#include <iostream>

using namespace std;

int main()
{

int numero;
int quintaParte;
int septimaParte;
int resto;

cout << "Numero: ";
cin >> numero;

quintaParte = numero/5;
resto = (numero%5);
septimaParte = quintaParte / 7;

cout << "Quinta parte: " << quintaParte << endl;
cout << "Resto: " << resto << endl;
cout << "Septima parte de la quinta parte: " << septimaParte << endl;


    return 0;
}
