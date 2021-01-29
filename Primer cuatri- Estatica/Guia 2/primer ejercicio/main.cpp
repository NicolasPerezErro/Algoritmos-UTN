#include <iostream>


using namespace std;

int main()
{

int numeros;
int mayor = 0;


for (int i = 0; i < 10; i++){

  cout << "Digite 10 numeros: ";
  cin >> numeros;

    if (numeros > mayor){

    mayor = numeros;

                      }

}


cout << "El mayor numero es: " << mayor << endl;


    return 0;
}
