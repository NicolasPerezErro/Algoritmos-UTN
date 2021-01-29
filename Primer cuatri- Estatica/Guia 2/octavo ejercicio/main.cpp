#include <iostream>

using namespace std;

int main()
{
int dia, mes, anio;
int fecha;

cout << "Anio: ";
cin >> anio;

cout << "Mes: ";
cin >> mes;

cout << "Dia: ";
cin >> dia;


fecha = (anio*10000) + (mes*100) + (dia);

cout << fecha << endl;



    return 0;
}
