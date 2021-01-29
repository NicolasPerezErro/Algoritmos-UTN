#include <iostream>

using namespace std;

int main()
{

 int mes;
 int anio; // PUEDE QUE SEA AÑO BISIESTO

 cout << "Mes: " << endl;
 cin >> mes;

 cout << "Año: ";
 cin >> anio;

 switch (mes){

 case 1: cout << "31 dias " << endl; break;
 case 2: {if ((anio%4 == 0 && anio%100 != 0) || anio%400 == 0){
            cout << "29 dias" << endl;
            } else { cout << "28 dias" << endl;
                   }}
 case 3: cout << "31 dias " << endl; break;
 case 4: cout << "30 dias " << endl; break;
 case 5: cout << "31 dias " << endl; break;
 case 6: cout << "30 dias " << endl; break;
 case 7: cout << "31 dias " << endl; break;
 case 8: cout << "31 dias " << endl; break;
 case 9: cout << "30 dias " << endl; break;
 case 10: cout << "31 dias" << endl; break;
 case 11: cout << "30 dias " << endl; break;
 case 12: cout << "30 dias " << endl; break;
 default: cout << "Ingreso mes incorrecto " << endl; break;


 }



    return 0;
}
