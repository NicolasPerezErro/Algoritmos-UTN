#include <iostream>

using namespace std;

void sumarHora(long h, long t, long& res, bool &nuevoDia);

int main()
{

long hora, tiempo, resultado;
bool nuevoDia = true;

cout << "Decime la hora: ";
cin >> hora;

cout << "Decime el tiempo para sumarle a esa hora: ";
cin >> tiempo;

sumarHora(hora,tiempo,resultado, nuevoDia);

cout << "La hora final es: " << resultado << endl;
cout << "Hubo un nuevo dia: " << nuevoDia << endl;


    return 0;
}


void sumarHora(long h, long t, long& res, bool &nuevoDia){

long hHora = h/10000;
long hMinutos = (h%10000) / 100;
long hSegundos = h % 100;

long tHora = t/10000;
long tMinutos = (t%10000) / 100;
long tSegundos = t % 100;

long segundosFinales = hSegundos + tSegundos;
long minutosFinales = hMinutos + tMinutos;
long horasFinales = hHora + tHora;

if (segundosFinales >= 60){

    segundosFinales - 60;
    minutosFinales ++;
}

if (minutosFinales >= 60){

    minutosFinales - 60;
    horasFinales++;

}

if (horasFinales > 24){

    horasFinales - 24;
    nuevoDia = true;

}

res = horasFinales*10000 + minutosFinales*100 + segundosFinales;

}
