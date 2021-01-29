#include <iostream>

using namespace std;

int main()
{

float lado1;
float lado2;
float lado3;

cout << "Lado1: ";
cin >> lado1;

cout << "Lado2: ";
cin >> lado2;

cout << "Lado3: ";
cin >> lado3;

if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3){

    cout << "Es un triangulo equilatero" << endl;

} else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3){

    cout << "Es un triangulo isosceles" << endl;

} else if (lado1 != lado2 && lado2 != lado3 && lado1 != lado3){

    cout << "Es un triangulo escaleno" << endl;
}



    return 0;
}
