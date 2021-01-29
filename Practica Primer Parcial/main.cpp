#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// 3
struct ferreteria{
int codArt;
char descripcionArt[50];
int cantVendida;
float precioUnitario;
};

// 4

struct calificaciones{
int legajo;
char materia[50];
int codCurso;
int nota;
};

struct aprobados{
int legajo;
char materia[50];
int curso;
};

int fecha (int dia, int mes, int anio);
void Union (int vecA[],int vecB[],int lenA, int lenB);
void mostrar(int vec[],int len);
int busquedaSecuencial(int vec[], int len, int valorBuscado);
void agregar(ferreteria vec[],int n, int& len, int v);

int main(){
/* // 1
int dia, mes, anio;

cout << "Dia: ";
cin >> dia;

cout << "Mes: ";
cin >> mes;

cout << "Anio: ";
cin >> anio;

int diaSem = fecha(dia,mes,anio);
string nombreDia;


switch (diaSem){

case 0: nombreDia = "Domingo"; break;
case 1: nombreDia = "Lunes"; break;
case 2: nombreDia = "Martes"; break;
case 3: nombreDia = "Miercoles"; break;
case 4: nombreDia = "Jueves"; break;
case 5: nombreDia = "Viernes"; break;
case 6: nombreDia = "Sabado"; break;
}

cout << "El dia de la semana es: " << nombreDia << endl;
*/

/* // 2
int vec1[10] = {0,3,5,6,9,11};
int len1 = 6;
int vec2[10] = {0,1,7,8,10,18};
int len2 = 6;

Union(vec1,vec2,len1,len2);
*/


/* // 3
FILE * archivo1 = fopen("suck1.dat","rb");
FILE * archivo2 = fopen("suck2.dat","rb");

ferreteria regis1;
ferreteria vecF[100];
int lenVec = 0;
fread(&regis1,sizeof(ferreteria),1,archivo1);
ferreteria regis2;
fread(&regis2,sizeof(ferreteria),1,archivo2);
float totalSuck1 = 0;
float totalSuck2 = 0;


while (!feof(archivo1)){
  vecF[lenVec] = regis1;
  lenVec++;
  totalSuck1 = totalSuck1 + (regis1.cantVendida * regis1.precioUnitario);
  fread(&regis1,sizeof(ferreteria),1,archivo1);
}

int pos;

while (!feof(archivo2)){

totalSuck2 = totalSuck2 + (regis2.cantVendida * regis2.precioUnitario);
pos = busquedaSecuencial(vecF,lenVec,regis2);

    if (pos == -1){
        vecF[len] = regis2;
        lenVec++;
    }
}

Burbuja(ferreteria vecF,int lenVec); // ORDENO DE MAYOR A MENOR

for (int i = 0; i < 3; i++){

    cout << "Los 3 articulos mas vendidos son: " << vecF[i] << endl;
}

if (totalSuck1 > totalSuck2){

    cout << "La surcursal 1 tiene mas " << endl;

}else{
    cout << "La sucursal 2 tiene mas" << endl;
}
*/

//4

/*
FILE * archivo = fopen("notas.dat","wb+");

calificaciones regisCalificaciones;

regisCalificaciones.codCurso = 100;
regisCalificaciones.legajo = 1689944;
strcpy(regisCalificaciones.materia,"Lengua");
regisCalificaciones.nota = 7;

fwrite(&regisCalificaciones,sizeof(calificaciones),1,archivo);

regisCalificaciones.codCurso = 150;
regisCalificaciones.legajo = 1689944;
strcpy(regisCalificaciones.materia,"Matematica");
regisCalificaciones.nota = 10;

fwrite(&regisCalificaciones,sizeof(calificaciones),1,archivo);

regisCalificaciones.codCurso = 215;
regisCalificaciones.legajo = 2789045;
strcpy(regisCalificaciones.materia,"Discreta");
regisCalificaciones.nota = 2;

fwrite(&regisCalificaciones,sizeof(calificaciones),1,archivo);

regisCalificaciones.codCurso = 400;
regisCalificaciones.legajo = 2789045;
strcpy(regisCalificaciones.materia,"Lengua");
regisCalificaciones.nota = 8;

fwrite(&regisCalificaciones,sizeof(calificaciones),1,archivo);

regisCalificaciones.codCurso = 500;
regisCalificaciones.legajo = 2789045;
strcpy(regisCalificaciones.materia,"Quimica");
regisCalificaciones.nota = 10;

fwrite(&regisCalificaciones,sizeof(calificaciones),1,archivo);

regisCalificaciones.codCurso = 255;
regisCalificaciones.legajo = 1502244;
strcpy(regisCalificaciones.materia,"Algoritmos");
regisCalificaciones.nota = 3;

fwrite(&regisCalificaciones,sizeof(calificaciones),1,archivo);

regisCalificaciones.codCurso = 700;
regisCalificaciones.legajo = 1502244;
strcpy(regisCalificaciones.materia,"Algebra");
regisCalificaciones.nota = 9;

fwrite(&regisCalificaciones,sizeof(calificaciones),1,archivo);

rewind(archivo);
fread(&regisCalificaciones,sizeof(calificaciones),1,archivo);

while(!feof(archivo)){
cout << "Legajo: " << regisCalificaciones.legajo << endl;
cout << "Codigo: " << regisCalificaciones.codCurso << endl;
cout << "Materia: " << regisCalificaciones.materia << endl;
cout << "Nota: " << regisCalificaciones.nota << endl;
cout << " ---------------------- " << endl;


fread(&regisCalificaciones,sizeof(calificaciones),1,archivo);
}

fclose(archivo);
*/


FILE * archivo = fopen("notas.dat","rb");
FILE * archivo2 = fopen("aprobados.dat","wb+");

calificaciones registro;
aprobados regAprobados;

fread(&registro,sizeof(calificaciones),1,archivo);

int legajoAnterior;
float sumaXEstudiante;
int cantNotasXEstudiante;
float sumaMejorPromedio;
float notaMejorPromedio;
float mejorPromedio = 0;
int estudianteMejorPromedio;
float PeorNotaEstudiante = 0;
float PeorNota = 0;
float minNota = 99999;
int estudiantePeorNota;


while (!feof(archivo)){

legajoAnterior = registro.legajo;
sumaXEstudiante = 0;
sumaMejorPromedio = 0;
cantNotasXEstudiante = 0;
PeorNota = 0;

    while (!feof(archivo) && legajoAnterior == registro.legajo){

        sumaXEstudiante += registro.nota;
        cantNotasXEstudiante++;
        sumaMejorPromedio += registro.nota;
        PeorNota += registro.nota;

        if (registro.nota > 6){
        regAprobados.legajo = registro.legajo;
        regAprobados.curso = registro.codCurso;
        strcpy(regAprobados.materia,registro.materia);
        fwrite(&regAprobados,sizeof(aprobados),1,archivo2);
        }

        fread(&registro,sizeof(calificaciones),1,archivo);
    }

    cout << "El promedio del estudiante: " << legajoAnterior << " es: " << sumaXEstudiante/cantNotasXEstudiante << endl;
    notaMejorPromedio = sumaMejorPromedio/cantNotasXEstudiante;
    PeorNotaEstudiante = PeorNota / cantNotasXEstudiante;


    if (notaMejorPromedio > mejorPromedio){

        mejorPromedio = notaMejorPromedio;
        estudianteMejorPromedio = legajoAnterior;
    }

    if (PeorNotaEstudiante < minNota){

        minNota = PeorNotaEstudiante;
        estudiantePeorNota = legajoAnterior;
    }

}

cout << "Estudiante con el mejor promedio: " << estudianteMejorPromedio << " con " << mejorPromedio << endl;
cout << "Estudiante con la peor nota: " << estudiantePeorNota << " con " << minNota << endl;

fclose(archivo);

rewind(archivo2);
fread(&regAprobados,sizeof(aprobados),1,archivo2);

while (!feof(archivo2)){

cout << "Legajo: " << regAprobados.legajo << endl;
cout << "Materia: " << regAprobados.materia << endl;
cout << "Curso: " << regAprobados.curso << endl;
cout << "-------------" << endl;


fread(&regAprobados,sizeof(aprobados),1,archivo2);
}
fclose(archivo2);





return 0;
}

int fecha (int dia, int mes, int anio){

int diaSemana;
int x;

int vecRegular[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
int vecBisiesto[12] = { 0,3,4,0,2,5,0,3,6,1,4,6 };

if (anio%4 == 0 && anio&100 != 0 || anio%400 == 0){

    x = vecBisiesto[mes-1];

} else{

    x = vecRegular[mes-1];
}

diaSemana = ((anio-1)%7+((anio-1)/4 -(3/4)*((anio-1)/100 + 1)%7 + x + dia%7))%7;

return diaSemana;
}

int busquedaSecuencial(int vec[], int len, int valorBuscado){
	int pos = -1;

	int i = 0;
	while(i<len && vec[i] != valorBuscado) {
		i++;
	}

	if(vec[i] == valorBuscado) {
		pos = i;
	}

	return pos;
}

void Union(int vecA[],int vecB[],int lenA, int lenB){

int vecC[20];
int lenC = 0;

for (int i = 0; i < lenA; i++){

vecC[lenC] = vecA[i];
lenC++;

}

for (int i = 0; i < lenB; i++){

int pos = busquedaSecuencial(vecC,lenC,vecB[i]);

    if (pos == -1){

        vecC[lenC] = vecB[i];
        lenC++;
    }
}

mostrar(vecC,lenC);

}

void mostrar(int vec[],int len){

for (int i = 0; i < len; i++){

    cout << vec[i] << " " << endl;
}
}
