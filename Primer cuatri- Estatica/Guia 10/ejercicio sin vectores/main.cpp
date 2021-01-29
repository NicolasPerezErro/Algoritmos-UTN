#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct grabar{

int numeroArt;
char descripcion[50];
int cantidad;

};

struct copiar{

grabar grab;
char deposito[50];

};


int main()
{

grabar reg1; // 1) DEBO COMPARAR LO QUE HAY EN CADA ARCHIVO, SON 2 VARIABLES QUE POSEEN EL MISMO TIPO DE DATO
grabar reg2;
copiar regDeposito;
copiar regLeer;

FILE * archivo1 = fopen("deposito1.dat","rb");
FILE * archivo2 = fopen("deposito2.dat","rb");
FILE * archivo3 = fopen("stock.dat","wb+");

fread(&reg1,sizeof(grabar),1,archivo1);
fread(&reg2,sizeof(grabar),1,archivo2);



while (!feof(archivo1) && !feof(archivo2)){             // MISMO QUE (POSA < LENA && POSB < LENB)

    if (reg1.numeroArt < reg2.numeroArt){               // MISMO QUE (VEC[A].DATO.NUMEROART < VEC[B].DATO.NUMEROART)
        regDeposito.grab = reg1;                        // COMO EL SEGUNDO PUNTO ME PIDE QUE AÑADA UNA DESCRIPCION, TENGO QUE COPIAR LOS DATOS A REGDEPOSITO.GRAB
                                                        // PARA QUE LUEGO CUANDO GRABE TODO, SE PASE TODO + LA DESCRIPCION
        strcpy(regDeposito.deposito,"Deposito 1");
        fwrite(&regDeposito,sizeof(copiar),1,archivo3); // AL FINAL SE GUARDA EN EL ARCHIVO 3
        fread(&reg1,sizeof(grabar),1,archivo1);         // MISMO QUE POS++;
    } else {
        regDeposito.grab = reg2;
        strcpy(regDeposito.deposito,"Deposito 2");
        fwrite(&regDeposito,sizeof(copiar),1,archivo3);
        fread(&reg2,sizeof(grabar),1,archivo2);
        }
}

while (!feof(archivo1)){

    regDeposito.grab = reg1;
    strcpy(regDeposito.deposito,"Deposito 1");
    fwrite(&regDeposito,sizeof(copiar),1,archivo3);
    fread(&reg1,sizeof(grabar),1,archivo1);
}

while (!feof(archivo2)){

    regDeposito.grab = reg2;
    strcpy(regDeposito.deposito,"Deposito 2");
    fwrite(&regDeposito,sizeof(copiar),1,archivo3);
    fread(&reg2,sizeof(grabar),1,archivo2);
        }


fclose(archivo1);
fclose(archivo2);

rewind(archivo3);

fread(&regLeer,sizeof(copiar),1,archivo3);

while (!feof(archivo3)){

    cout << "Numero de articulo: " << regLeer.grab.numeroArt << endl;
    cout << "Descripcion: " << regLeer.grab.descripcion << endl;
    cout << "Cantidad: " << regLeer.grab.cantidad << endl;
    cout << "Descripcion: " << regLeer.deposito << endl;
    cout << "------------------" << endl;
    fread(&regLeer,sizeof(copiar),1,archivo3);
}

fclose(archivo3);



    return 0;
}




