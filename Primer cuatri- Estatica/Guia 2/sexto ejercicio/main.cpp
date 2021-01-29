#include <iostream>

using namespace std;

int main()
{
// a cuantos multiplos hay que llegar?
 int m; // CANTIDAD DE NUMEROS A IMPRIMIR
 int cantidadMultiplos = 0;
 int dividendo = 3;
 int suma = 0;

 cout << "Ingrese cuantos multiplos de 3 y no de 5 desea: ";
 cin >> m;

 cout << "Listado de multiplos: " << endl;

 while (cantidadMultiplos < m){


 if (dividendo % 3 == 0  && dividendo % 5 != 0){

    cantidadMultiplos++;
    suma = suma + dividendo;
    cout << dividendo << endl;


 }

    dividendo += 3;




 }


cout << "Suma: " << suma << endl;


    return 0;
}
