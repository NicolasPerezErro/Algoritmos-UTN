#include <iostream>

using namespace std;

bool esMultiplo (int a, int b);

int main()
{

int n1, n2;

bool mostrar;

cout << "Numero 1: ";
cin >> n1;

cout << "Numero 2: ";
cin >> n2;

mostrar = esMultiplo (n1,n2);

if (mostrar){

    cout << "Es multiplo" << endl;

} else { cout << "No es multiplo" << endl;}







    return 0;
}


bool esMultiplo (int a, int b){

if (a%b == 0){

return true;

} else { return false; }


}
