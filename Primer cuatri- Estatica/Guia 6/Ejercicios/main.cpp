#include <iostream>
#include "vectores.h"


using namespace std;


int main(){

/* pais velocidad[150] = {{"Argentina", 120,60},{"Urugay", 190, 70}};

int lenVelocidad = 2; // 2 ELEMENTOS

int posMax = -1;
int posMin = -1; // DEBEMOS DARLE UNA POS INCIAL PARA QUE COMPARE

int maxVelocidad = buscarMaximaVelocidad(velocidad,lenVelocidad,posMax);
int minVelocidad = buscarMinimaVelocidad(velocidad,lenVelocidad,posMin);
int promedio = promedioVelocidadMax(velocidad,lenVelocidad);

cout << "Velocidad maxima la tiene " << velocidad[posMax].nombre << " y es " << maxVelocidad << endl;
cout << "La mínima velocidad la tiene el país: " << velocidad[posMin].nombre << " y es " <<  minVelocidad << endl;
cout << "El promedio de la velocidad maxima es: " << promedio << endl;

*/

// ---------------------------------------------------------

/*
alumnos alum[50] = {{2345,15},{8901,20},{1357,5}};

int lenAlum = 3;

int cantAlumMax = buscarMaximoAlumnos(alum, lenAlum);
int cantAlumMin = buscarMinimoAlumnos(alum,lenAlum);
float promedioI = promedioInscriptos(alum,lenAlum);

cout << "Maxima cantidad: " << cantAlumMax << endl;
cout << "Minima cantidad: " << cantAlumMin << endl;
cout << "Promedio de alumnos: " << promedioI << endl;

*/
// -----------------------------------------------------------

/*
quiosko q[10] = {{1234,"Coca",100,900},{2323,"Agua",65,2000},{1432,"Fanta",80,1500}};
int len = 3;
int opcion;
int n = 10;
string v;
string nombreModificar;
int stockModificar;
int precioModificar;

imprimirMenu();

cin >> opcion;

while (opcion > 0){

 switch (opcion){

case 1:{
    quiosko productoAInsertar;                      // IMPORTANTE, USA CREA OTRA VARIABLE DE TIPO QUIOSKO Y AGREGA EN CADA CAMPO
    cout << "Ingrese el codigo de producto: ";
    cin >> productoAInsertar.codigoProducto;

    cout << "Ingrese el nomnre del producto: ";
    cin >> productoAInsertar.nombre;

    cout << "Ingrese el precio del producto: ";
    cin >> productoAInsertar.precio;

    cout << "Ingrese el stock del producto: ";
    cin >> productoAInsertar.cantStock;

    agregarProducto(q,n,len,productoAInsertar);

    cout << " ---------------- " << endl;

    mostrarProducto(q,len);

    break;
}

case 2: {

    cout << "Nombre del producto: ";
    cin >> v;

    int posProducto = buscarProducto(q,len,v);

    if (posProducto != -1){

    cout << "La pos es " << posProducto << endl;

} else {cout << "Producto no encontrado" << endl;}

    break;
}

case 3:{

    cout << "Nombre de producto: ";
    cin >> nombreModificar;

    cout << "Nuevo precio: ";
    cin >> precioModificar;

    cout << "Nuevo Stock: ";
    cin >> stockModificar;

    modificar(q,len,nombreModificar,precioModificar,stockModificar);
    mostrarProducto(q,len);

    break;
}
    default: {
    cout << "Ingrese opcion correcta" << endl;
    break;

    }

 }

 imprimirMenu();
 cin >> opcion;

}

*/



// -----------------------------------------


notas notx[20] = {{167984,"alicia",7},{999923,"mauro",10},{444442,"nicolas",9}};

int len = 3;
string nombre;
bool bandera = false;


cout << "Ingrese nombre a buscar: ";
cin >> nombre;

int resultadoLegajo = buscarAlumno(notx,len,nombre);


for (int i = 0; i < len; i++){

    if (notx[i].legajo == resultadoLegajo){

        bandera = true;

        }

    }


if (bandera == true){

  cout << "El alumno " << nombre << " tiene legajo: " << resultadoLegajo << endl;

} else {cout << "No se encontro al alumno" << endl;}




cout << "-----------------------------" << endl;

int nota;

cout << "Nombre del alumno: ";
cin >> nombre;


cout << "Nota nueva: ";
cin >> nota;


modificarNota(notx,len,nombre,nota);

mostrarNotas(notx,len);




cout << "-----------------------------" << endl;

float promedio = promedioNotas(notx,len);

cout << "El promedio de todas las notas es: " << promedio << endl;

cout << "-----------------------------" << endl;

int posNotaMax = mejorNota(notx,len);

cout << "El estudiante con la mejor nota es: " << notx[posNotaMax].nombre << endl;

cout << "-----------------------------" << endl;

int posNotaMin = peorNota(notx,len);

cout << "El estudiante con la nota mas baja es: " << notx[posNotaMin].nombre << endl;


    return 0;
}
