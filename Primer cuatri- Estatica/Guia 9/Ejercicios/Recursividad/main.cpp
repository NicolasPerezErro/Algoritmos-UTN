#include <iostream>
#include "vectores.h"
#include <stdio.h>

using namespace std;

int factorial (int numero);
int potencia (int base, int exponen);
int Fibonacci (int numero);

int main()
{
/*
int numero;

cout << "Numero: ";
cin >> numero;

int res = factorial(numero);

cout << res << endl;

*/

/*

int numero;
int poten;

cout << "Decime la base: ";
cin >> numero;

cout << "Decime el exponente: ";
cin >> poten;

int res = potencia(numero,poten);

cout << res << endl;

*/

int numero;

cout << "Digite numero: ";
cin >> numero;

int res = Fibonacci(numero);

cout << res << endl;



    return 0;
}

int factorial (int numero){

int resultado;

if (numero == 0){ // CASO BASE

    resultado = 1;

}else{

resultado = numero * factorial(numero-1); // PONGO LA PALABRA FACTORIAL PARA NO PONER EL ! FORMULA --> (n)! = n * (n-1)!


    }

return resultado;
}

int potencia (int base, int exponen){

int resultado;

if (exponen == 0){

    resultado = 1;

} else{

  if (base > 1){

resultado =  base * potencia(base,exponen-1); // DOS PARAMETROS

        } else {cout << "Numero menor a 1" << endl;}

    }

    return resultado;
}

int Fibonacci (int numero){

int resultado;

if (numero == 0 || numero == 1){

    resultado = numero; // MAL CONSIGNA, FIB(0) = 0 Y FIB(1) = 1;


}else{

resultado = Fibonacci(numero-1) + Fibonacci(numero-2);

        }

return resultado;

}
