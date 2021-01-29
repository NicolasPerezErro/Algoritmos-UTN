#include <iostream>
#include "vectores.h"
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
 Nota registro;
 NuevoNotas registroNuevo;

 FILE * archivo = fopen("notas.dat","rb");

 NuevoNotas VecNotas[10];
 int lenNotas = 0;

 fread(&registro,sizeof(Nota),1,archivo);

 while (!feof(archivo)){

registroNuevo.NotaInfo = registro;

agregarNotas(VecNotas,10,lenNotas,registroNuevo);

    fread(&registro,sizeof(Nota),1,archivo);
 }

 fclose(archivo);


int posVec = 0;
int legajoAnterior;
char NotaAnterior [50];
char CalificacionMasAlta [50];
int maximo;
float promedioCalificacionEstudiantes;
float SumaNotas;
int cantidadDeNotasXBloque;
float promedioTotalNotas = 0;
float SumaTotalNotas = 0;



while (posVec < lenNotas){

legajoAnterior = VecNotas[posVec].NotaInfo.legajo;
promedioCalificacionEstudiantes = 0;
cantidadDeNotasXBloque = 0;
SumaNotas = 0;
maximo = -1;
strcpy(CalificacionMasAlta,"");

while (posVec < lenNotas && legajoAnterior == VecNotas[posVec].NotaInfo.legajo){

SumaNotas = SumaNotas + VecNotas[posVec].NotaInfo.nota;

if (VecNotas[posVec].NotaInfo.nota > maximo){

    maximo = VecNotas[posVec].NotaInfo.nota;
    strcpy(CalificacionMasAlta,VecNotas[posVec].NotaInfo.materia);


    }

cantidadDeNotasXBloque++;
posVec++;

}


promedioCalificacionEstudiantes = SumaNotas/cantidadDeNotasXBloque;

SumaTotalNotas = SumaTotalNotas + SumaNotas;

promedioTotalNotas = SumaTotalNotas / posVec;

cout << "Promedio de notas de los estudiantes por legajo " << legajoAnterior << " es: " << promedioCalificacionEstudiantes << endl;

cout << "La materia con calificacion mas alta por estudiante " << legajoAnterior << " es: " << CalificacionMasAlta << endl;




}

cout << "Cantidad de notas procesadas: " << posVec << endl;
cout << "Promedio total de notas: " << promedioTotalNotas << endl;

cout << " ----------------- " << endl;
cout << " ----------------- " << endl;




FILE * archivo2 = fopen("notas.dat","rb");

fread(&registro,sizeof(Nota),1,archivo2);

 while (!feof(archivo2)){

cout << "Legajo: " << registro.legajo << endl;
cout << "Materia: " << registro.materia << endl;
cout << "Nota: " << registro.nota << endl;

cout << "--------" << endl;



    fread(&registro,sizeof(Nota),1,archivo2);
 }

 fclose(archivo2);



    return 0;
}
