#include <iostream>
#include "vectores.h"

using namespace std;

int main()
{
/*
float vecA[5] = {3,7,9,14,20};
float vecB[6] = {2,5,10,11,25,30};
float vecC[11];
int lenA = 5;
int lenB = 6;
int lenC = 0;
int posA = 0;
int posB = 0;


while(posA < lenA && posB < lenB) { // MIENTRAS NO SE TERMINEN LOS VECTORES COMPARA Y AGREGA AL VECTOR C
    if(vecA[posA] < vecB[posB]) {
      agregar(vecC,11,lenC,vecA[posA]);
      posA++;

    } else {
      agregar(vecC,11,lenC,vecB[posB]);
      posB++;
    }
}

while(posA < lenA) { // SI SE TERMINO EL VECTOR Y QUEDAN ELEMENTOS POR AGREGAR, AGREGALOS
    agregar(vecC,11,lenC,vecA[posA]);
    posA++;
}

while(posB < lenB) { // SI SE TERMINO EL VECTOR Y QUEDAN ELEMENTOS POR AGREGAR, AGREGALOS
    agregar(vecC,11,lenC,vecB[posB]);
    posB++;
}

mostrar(vecC,lenC);
*/

/*
estudiantes est1[10] = {{123,"Perez",8},{305,"Ramirez",10},{400,"Echenique",9}};
estudiantes est2[10] = {{257,"Miranda",5},{367,"Pepe",7},{600,"Nauri",2}};
estudiantes est3[20];
int len1 = 3;
int len2 = 3;
int len3 = 0;
int pos1 = 0;
int pos2 = 0;


while (pos1 < len1 && pos2 < len2){

  if (est1[pos1].legajo<est2[pos2].legajo){

    agregarEstudiantes(est3,20,len3,est1[pos1]); // ESTOY AGREGANDO TODO, SOLO COMPARO LEGAJO
    pos1++;


  }  else {

            agregarEstudiantes(est3,20,len3,est2[pos2]);
            pos2++;

    }

}

while (pos1 < len1){

    agregarEstudiantes(est3,20,len3,est1[pos1]);

    pos1++;

}

while (pos2 < len2){

    agregarEstudiantes(est3,20,len3,est2[pos2]);

    pos2++;

}

mostrarEstudiantes(est3,len3);
*/

estudiantePA vecPA[8000] ={{123,"Perez","Discreta",6},
{123,"Perez","Analisis",7.5},
{123,"Perez","AED",8},
{100,"Lopez","Algebra",9},
{100,"Lopez", "AED",10},
{100, "Lopez","Arq",8.5},
{540,"Rodriguez","IngYSoc",9.5},
{540,"Rodriguez","Quimica",7}};
int lenPA = 8;
int posPA = 0;
float promedioPorEstudiante;
float sumaNotasPorEstudiante;
int cantNotasPorEstudiante;

/*Inicializar todas las variables que me sirvan para el procesamiento
  global de los datos. Por ejemplo: Mejor Promedio
*/
float maxPromedio = 0;
int legajoMaxPromedio;

while(posPA < lenPA) {
  /*Inicializar todas las variables que me sirvan para el procesamiento   de cada lote de datos. Por ejemplo: Promedio de cada estudiante
  */
  int legajoAnterior = vecPA[posPA].legajo;
  promedioPorEstudiante = 0;
  sumaNotasPorEstudiante = 0;
  cantNotasPorEstudiante = 0;

  while(vecPA[posPA].legajo == legajoAnterior && posPA < lenPA) {
    //proceso cada lote de datos (misma clave)
    sumaNotasPorEstudiante += vecPA[posPA].notaFinal;
    cantNotasPorEstudiante ++;
    posPA++;
  }

  /*Voy a informar (mostrar por pantalla) todo lo relacionado a el procesamiento de cada lote de datos. Por ejemplo: Promedio de cada estudiante
  */
  promedioPorEstudiante = sumaNotasPorEstudiante/cantNotasPorEstudiante;
  cout << "El promedio del estudiante nroLegajo: " << legajoAnterior << endl;
  cout << promedioPorEstudiante << endl;
  lineaSeparatoria();

  //proceso los datos globales. Por ejemplo: Mejor Promedio
  if(promedioPorEstudiante > maxPromedio) {
    maxPromedio = promedioPorEstudiante;
    legajoMaxPromedio = legajoAnterior;
  }

}
  /*Voy a informar (mostrar por pantalla) todo lo relacionado a el procesamiento global de los datos. Por ejemplo: Mejor Promedio
  */
  cout << "El mejor promedio es: " << maxPromedio << " y pertenece a: " << legajoMaxPromedio << endl;



    return 0;
}
