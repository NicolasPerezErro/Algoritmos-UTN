#include <iostream>
#include "vectores.h"
#include <string.h>
#include <string>
#include <stdio.h> // ACA ESTA DECLARADO EL FOPEN


using namespace std;



int main()
{
/*

//30 días(Abril) * Cantidad de Sucursales
//Suponemos que tiene 3 sucursales
sucursal vecSuc[90] = {{1,1,1000.50},
{1,2,1500},
{1,3,800.2},
{2,1,600},
{2,2,767.3},
{2,3,875},
{3,1,469},
{3,2,800.7},
{3,3,2700}};
int lenVecSuc = 9;
int pos = 0;
int sucursalAnterior;
float dineroRecaudadoXSucursalEnElMes;
float maxDineroSucursal;
int diaMaxDineroSucursal;

float minRecaudacionEnElMes = 999999999999999999999999999.0;
int NroSucursalminRecaudacionEnElMes = -1;


while(pos < lenVecSuc) {
  sucursalAnterior = vecSuc[pos].sucursal;
  dineroRecaudadoXSucursalEnElMes = 0;
  maxDineroSucursal = -1;
  diaMaxDineroSucursal = -1;

  while(pos < lenVecSuc && sucursalAnterior == vecSuc[pos].sucursal) {
    dineroRecaudadoXSucursalEnElMes += vecSuc[pos].dineroRecaudado;

    if(vecSuc[pos].dineroRecaudado > maxDineroSucursal) {
      maxDineroSucursal = vecSuc[pos].dineroRecaudado;
      diaMaxDineroSucursal = vecSuc[pos].dia;
    }
    pos++;
  }

  cout << "La sucursal nro " << sucursalAnterior <<  " recaudó " << dineroRecaudadoXSucursalEnElMes << endl;

  cout << "El día que más dinero recaudó fue " << diaMaxDineroSucursal << " de Abril " << " con $ " <<  maxDineroSucursal << endl;

  if(dineroRecaudadoXSucursalEnElMes < minRecaudacionEnElMes){
    minRecaudacionEnElMes = dineroRecaudadoXSucursalEnElMes;
    NroSucursalminRecaudacionEnElMes = sucursalAnterior;
  }

}

cout << "La sucursal nro " << NroSucursalminRecaudacionEnElMes << "  fue la que menos recaudó con un total de $" << minRecaudacionEnElMes << endl;

*/

/*
claustro reg;

FILE * archivo = fopen("noDocentes.dat","wb+"); // ESTOY METIENDO UNA ESTRUCTURA CON SUS PARAMETROS EN UN ARCHIVO

strcpy(reg.nombre,"Mingo");
reg.legajo = 650;

fwrite(&reg,sizeof(claustro),1,archivo);

strcpy(reg.nombre,"Juan");
reg.legajo = 423;

fwrite(&reg,sizeof(claustro),1,archivo);

rewind(archivo);

fread(&reg,sizeof(claustro),1,archivo);

while (!feof(archivo)){

    cout << "El Legajo es: " << reg.legajo << endl;
    cout << "El nombre es: " << reg.nombre << endl;

    cout << "------------------" << endl;

    fread(&reg,sizeof(claustro),1,archivo);
}
*/

// CREA 2 VARIABLES PARA ACCEDER A LAS ESTRUCTURAS

claustro reg; // reg ES VARIABLE DE LA PRIMERA ESTRUCTURA (ES EL REGISTRO DEL ARCHIVO ACTUAL)
claustroConsolidado regConsolidado; // regConsolidado ES VARIABLE DE LA SEGUNDA ESTRUCTURA

FILE * archivoEst = fopen("estudiantes.dat","rb"); // LEEMOS EL ARCHIVO PARA QUE NOS PERMITA AÑADIR A LA NUEVA ESTRUCTURA LOS DATOS

claustroConsolidado vecEstudiante[10];
int lenEstudiante = 0;

fread(&reg,sizeof(claustro),1,archivoEst); //LEES LA ESTRUCTURA CON LA QUE FUERON CREADOS LOS ARCHIVOS (reg)

while (!feof(archivoEst)){
    regConsolidado.claustro1 = reg; // ESTAS METIENDO LO QUE LEI RECIEN DE REG (LEGAJO Y NOMBRE) DEL ARCHIVO.
    strcpy(regConsolidado.descripcion,"Estudiante"); // INSERTA EN LA ESTRUCTURA DIRECTAMENTE
    insertarOrdenadoClaustro(vecEstudiante,lenEstudiante,regConsolidado);//INSERTA LOS DATOS DE LA ESTRUCTURA 2 EN EL VECTOR ESTUDIANTE.
    // vecEstudiante[lenEstudiante] = regConsolidado; lenEstudiante++; ??
    // vecESTUDIANTE CONTIENE EL regCONSOLIDADO.reg y .descripción

    fread(&reg,sizeof(claustro),1,archivoEst);
}

fclose(archivoEst);



FILE * archivoGraduado = fopen("graduados.dat","rb");

claustroConsolidado vecGradudado[10];
int lenGraduado = 0;


fread(&reg,sizeof(claustro),1,archivoGraduado);

while (!feof(archivoGraduado)){
regConsolidado.claustro1 = reg;
strcpy(regConsolidado.descripcion,"Graduado");
insertarOrdenadoClaustro(vecGradudado,lenGraduado,regConsolidado);

fread(&reg,sizeof(claustro),1,archivoGraduado);
}


fclose(archivoGraduado);



FILE * archivoDoc = fopen("docentes.dat","rb");

claustroConsolidado doc[10];
int lenDoc = 0;

fread(&reg,sizeof(claustro),1,archivoDoc);

while (!feof(archivoDoc)){

regConsolidado.claustro1 = reg;
strcpy(regConsolidado.descripcion,"Docente");
insertarOrdenadoClaustro(doc,lenDoc,regConsolidado);

fread(&reg,sizeof(claustro),1,archivoDoc);
}


fclose(archivoDoc);


FILE * archivoNoDoc = fopen("noDocentes.dat","rb");

claustroConsolidado noDoc[10];
int lenNoDoc = 0;

fread(&reg,sizeof(claustro),1,archivoNoDoc);

if (!feof(archivoNoDoc)){

regConsolidado.claustro1 = reg;
strcpy(regConsolidado.descripcion,"No docente");
insertarOrdenadoClaustro(noDoc,lenNoDoc,regConsolidado);

   fread(&reg,sizeof(claustro),1,archivoNoDoc);
}

fclose(archivoNoDoc);


FILE * archivoConsolidado = fopen("consolidado.dat","wb+");

claustroConsolidado estYgrad[20];
claustroConsolidado docYnoDoc[20];
int lenEsyGrad = 0;
int lenDocyNoDoc = 0;
int posEst = 0;
int posGrad = 0;
int posDoc = 0;
int posNoDoc = 0;

while (posEst < lenEstudiante && posGrad < lenGraduado){

    if (vecEstudiante[posEst].claustro1.legajo < vecGradudado[posGrad].claustro1.legajo){

        estYgrad[lenEsyGrad] = vecEstudiante[posEst];
        posEst++;
        lenEsyGrad++;
    } else {

        estYgrad[lenEsyGrad] = vecGradudado[posGrad];
        posGrad++;
        lenEsyGrad;
    }

}

while (posEst < lenEstudiante){

    estYgrad[lenEsyGrad] = vecEstudiante[posEst];
    posEst++;
    lenEsyGrad++;
}

while (posGrad < lenGraduado){

    estYgrad[lenEsyGrad] = vecGradudado[posGrad];
    posGrad++;
    lenEsyGrad++;
}


while (posDoc < lenDoc && posNoDoc < lenNoDoc){

    if (doc[posDoc].claustro1.legajo < noDoc[posNoDoc].claustro1.legajo){

        docYnoDoc[lenDocyNoDoc] = doc[posDoc];
        posDoc++;
        lenDocyNoDoc++;
    } else {

        docYnoDoc[lenDocyNoDoc] = noDoc[posNoDoc];
        posNoDoc++;
        lenDocyNoDoc++;
    }

}

while (posDoc < lenDoc){

    docYnoDoc[lenDocyNoDoc] = doc[posDoc];
    posDoc++;
    lenDocyNoDoc++;
}

while (posNoDoc < lenNoDoc){

    docYnoDoc[lenDocyNoDoc] = noDoc[posNoDoc];
    posNoDoc++;
    lenDocyNoDoc++;
}

int posEstyGrad = 0;
int posDocyNoDoc = 0;

while (posEstyGrad < lenEsyGrad && posDocyNoDoc < lenDocyNoDoc){

    if (estYgrad[posEstyGrad].claustro1.legajo < docYnoDoc[posDocyNoDoc].claustro1.legajo){

        fwrite(&estYgrad[posEstyGrad],sizeof(claustroConsolidado),1,archivoConsolidado); // LO GRABO DIRECTAMENTE EN EL ARCHIVO, TRAMO FINAL
        posEstyGrad++;                                                                   // NO HACE FALTA EN OTRO VECTOR

        // CON EL FWRITRE GRABAS EN EL ARCHIVO EL LEGAJO MENOR DE LOS DOS, POR ESO SE PONE EL VECTOR[POS]

    } else {

        fwrite(&docYnoDoc[posDocyNoDoc],sizeof(claustroConsolidado),1,archivoConsolidado);
        posDocyNoDoc++;
    }


}


while (posEstyGrad < lenEsyGrad){

    fwrite(&estYgrad[posEstyGrad],sizeof(claustroConsolidado),1,archivoConsolidado);
    posEstyGrad++;
}

while (posDocyNoDoc < lenDocyNoDoc){

    fwrite(&docYnoDoc[posDocyNoDoc],sizeof(claustroConsolidado),1,archivoConsolidado);
    posDocyNoDoc++;
}


rewind(archivoConsolidado);

claustroConsolidado regLectura; // CON CUALQUIER VARIABLE QUE TENGA EL MISMO TIPO DE DATO (CLAUSTROCONSOLIDADO) ME SIRVE PARA LEER Y ESCRBIR EN EL ARCHIVO
                                // ACA USA REGLECTURA, PODRIA USAR NORMALMENTE REGCONSOLIDADO
fread(&regLectura,sizeof(claustroConsolidado),1,archivoConsolidado);

while (!feof(archivoConsolidado)){

    cout << "Legajo: " << regLectura.claustro1.legajo << endl;
    cout << "Nombre: " << regLectura.claustro1.nombre << endl;
    cout << "Descripcion: " << regLectura.descripcion << endl;
    cout << "------------------------------" << endl;

    fread(&regLectura,sizeof(claustroConsolidado),1,archivoConsolidado);
}


fclose(archivoConsolidado);




    return 0;
}


