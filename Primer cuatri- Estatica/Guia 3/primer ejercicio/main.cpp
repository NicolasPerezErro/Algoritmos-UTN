#include <iostream>

using namespace std;

long unificarFecha(int ano, int mes, int dia);

int main()
{

int dia, mes, ano;
long mostrar;

cout << "Decime el ano: ";
cin >> ano;

cout << "Decime el mes: ";
cin >> mes;

cout << "Decime el dia: ";
cin >> dia;


mostrar = unificarFecha(ano,mes,dia);

cout << "Mostrar: " << mostrar << endl;



    return 0;
}


long unificarFecha(int ano, int mes, int dia){

long resultado;

resultado = ano*10000 + mes*100 + dia;

return resultado;

}

