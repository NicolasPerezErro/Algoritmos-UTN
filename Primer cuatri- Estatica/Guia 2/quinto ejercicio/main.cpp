#include <iostream>

using namespace std;

int main()
{

int sueldos;
int cantEmpleadosMenor2000 = 0;
int cantEmpleadosMayor2000Menor3000 = 0;
int cantEmpleadosMayor3000Menor5000 = 0;
int cantEmpleadosMayor5000 = 0;

cout << "Ingrese sueldo: ";
cin >> sueldos;

while (sueldos != 0){

if (sueldos < 2000){

cantEmpleadosMenor2000++;   }


if (sueldos >= 2000 && sueldos < 3000){

cantEmpleadosMayor2000Menor3000++;   }

if (sueldos >= 3000 && sueldos < 5000){

cantEmpleadosMayor3000Menor5000++;   }

if (sueldos >= 5000){

cantEmpleadosMayor5000++;   }


cout << "Ingrese sueldo: ";
cin >> sueldos;

}

cout << "Menor a 2000: " << cantEmpleadosMenor2000 << endl;
cout << "Mayor a 2000 y menor a 3000: " << cantEmpleadosMayor2000Menor3000 << endl;
cout << "Mayor a 3000 y menor a 5000: " << cantEmpleadosMayor3000Menor5000 << endl;
cout << "Mayor a 5000: " << cantEmpleadosMayor5000 << endl;




    return 0;
}
