#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

// EJERCICIO 1
struct curso{

char nombre[50];
int legajo;
char mail[50];

};


struct grabar{

curso dato;
int curso;

};

// EJERCICIO 2

struct datos{

int numeroCliente;
char articuloComprado[50];
int cantidadComprada;
int precioUnitario;

};

// TERCER EJERCICIO

struct listaDePrecios{

int codigoArt;
float precioUnitario;

};

struct stock{

int numeroArt;
int cantUnidades;
int posListaPrecios;

};

struct cabecera{

int idFactura;
int fecha;
int nroCliente;
float totalFactura;


};

struct detalle{

int idFactura;
int numeroArt;
int cant;

};


int main()
{
/*

// PRIMER EJERCICIO

curso vect1051[20] = {{"Nicolas",45,"nico@hotmail.com"},{"Matias",56,"mat@hotmail.com"},{"Jorge",254,"j@hotmail.com"}};
int len1051 = 3;
int pos1051 = 0;

curso vect1052[20] = {{"Coty",65,"co@hotmail.com"},{"Eze",97,"ez@hotmail.com"},{"Tom",876,"t@hotmail.com"}};
int len1052 = 3;
int pos1052 = 0;

grabar registro;

FILE * archivo = fopen("estudiantes.dat","wb+");


while (pos1051 < len1051 && pos1052 < len1052){

    if (vect1051[pos1051].legajo < vect1052[pos1052].legajo){
        registro.dato = vect1051[pos1051];                      // LE COPIO EL CONTENIDO DEL VECTOR
        registro.curso = 1;
        fwrite(&registro,sizeof(grabar),1,archivo);
        pos1051++;

    } else{

        registro.dato = vect1052[pos1052];
        registro.curso = 2;
        fwrite(&registro,sizeof(grabar),1,archivo);
        pos1052++;

    }

}

while (pos1051 < len1051) {

     registro.dato = vect1051[pos1051];
        registro.curso = 1;
        fwrite(&registro,sizeof(grabar),1,archivo);
        pos1051++;
}


while (pos1052 < len1052) {

    registro.dato = vect1052[pos1052];
        registro.curso = 2;
        fwrite(&registro,sizeof(grabar),1,archivo);
        pos1052++;

}

rewind(archivo);
fread(&registro,sizeof(grabar),1,archivo);

while (!feof(archivo)){

    cout << "Nombre: " << registro.dato.nombre << endl;
    cout << "Legajo: " << registro.dato.legajo << endl;
    cout << "Mail: " << registro.dato.mail << endl;
    cout << "Curso: " << registro.curso << endl;
    cout << "-----------" << endl;



   fread(&registro,sizeof(grabar),1,archivo);

}


fclose(archivo);
*/



// SEGUNDO EJERCICIO

/*

datos registro;



FILE * archivo = fopen("ventas.dat","wb+");

registro.numeroCliente = 64;
strcpy(registro.articuloComprado,"Pala");
registro.cantidadComprada = 4;
registro.precioUnitario = 120;

fwrite(&registro,sizeof(datos),1,archivo);

registro.numeroCliente = 64;
strcpy(registro.articuloComprado,"Copa");
registro.cantidadComprada = 10;
registro.precioUnitario = 67;

fwrite(&registro,sizeof(datos),1,archivo);

registro.numeroCliente = 234;
strcpy(registro.articuloComprado,"Cuchillo");
registro.cantidadComprada = 2;
registro.precioUnitario = 10;

fwrite(&registro,sizeof(datos),1,archivo);

registro.numeroCliente = 234;
strcpy(registro.articuloComprado,"Tenedor");
registro.cantidadComprada = 12;
registro.precioUnitario = 12;

fwrite(&registro,sizeof(datos),1,archivo);

registro.numeroCliente = 234;
strcpy(registro.articuloComprado,"Lampara");
registro.cantidadComprada = 200;
registro.precioUnitario = 6;

fwrite(&registro,sizeof(datos),1,archivo);

registro.numeroCliente = 544;
strcpy(registro.articuloComprado,"Impresora");
registro.cantidadComprada = 1;
registro.precioUnitario = 5000;

fwrite(&registro,sizeof(datos),1,archivo);

registro.numeroCliente = 544;
strcpy(registro.articuloComprado,"Cartucho");
registro.cantidadComprada = 3;
registro.precioUnitario = 52;

fwrite(&registro,sizeof(datos),1,archivo);


rewind(archivo);
fread(&registro,sizeof(datos),1,archivo);

while (!feof(archivo)){

    cout << "Numero Cliente: "  << registro.numeroCliente << endl;
    cout << "Articulo comprado: " << registro.articuloComprado << endl;
    cout << "Cantidad comprada: " << registro.cantidadComprada << endl;
    cout << "Precio Unitario: " << registro.precioUnitario << endl;
    cout << "-----------" << endl;

    fread(&registro,sizeof(datos),1,archivo);
}

fclose(archivo);

*/

FILE * archivo = fopen("ventas.dat","rb");

datos registro;

fread(&registro,sizeof(datos),1,archivo);
int numeroClienteAnterior;
int clienteMasDineroGastado;
int maxDineroGastado = 0;
int maxDinero = -1;
int clienteMenosCantArticulos;
int minCantidadArticulos = 0;
int minCantidad = 99999999;
int DineroGastadoXCliente;
char articuloMasCompradoXCliente[50];
int maxCantidad;
int maxCantidadCompradaXCliente;


while (!feof(archivo)){

    numeroClienteAnterior = registro.numeroCliente;
    DineroGastadoXCliente = 0;
    maxCantidadCompradaXCliente = 0;
    maxCantidad = 0;

    while (!feof(archivo) && numeroClienteAnterior == registro.numeroCliente){

    maxDineroGastado = maxDineroGastado + (registro.cantidadComprada * registro.precioUnitario);
    minCantidadArticulos = minCantidadArticulos + registro.cantidadComprada;
    DineroGastadoXCliente = DineroGastadoXCliente + (registro.cantidadComprada * registro.precioUnitario);
    maxCantidadCompradaXCliente = maxCantidadCompradaXCliente + registro.cantidadComprada;

    if (maxCantidadCompradaXCliente > maxCantidad){
        maxCantidad = maxCantidadCompradaXCliente;
        strcpy(articuloMasCompradoXCliente,registro.articuloComprado);
    }

    fread(&registro,sizeof(datos),1,archivo);
    }

    cout << "El cliente " << numeroClienteAnterior << " gasto: " << DineroGastadoXCliente << endl;
    cout << "El articulo mas comprado por el cliente " << " es: " << articuloMasCompradoXCliente << endl;

    if (maxDineroGastado > maxDinero){

        maxDinero = maxDineroGastado;
        clienteMasDineroGastado = numeroClienteAnterior;
    }

    if (minCantidadArticulos < minCantidad){

        minCantidad = minCantidadArticulos;
        clienteMenosCantArticulos = numeroClienteAnterior;
    }



}

cout << "El cliente que mas dinero gasto fue: " << clienteMasDineroGastado << " con " << maxDinero << endl;
cout << "El cliente que menos cantidad compro fue: " << clienteMenosCantArticulos << " con " << minCantidad << endl;

fclose(archivo);




    return 0;
}





