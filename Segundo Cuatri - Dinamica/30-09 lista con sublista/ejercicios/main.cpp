#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
/*
struct Nodo{
	int info;
	Nodo* sig;
};

void agregarNodo(Nodo* &p, int x);
void mostrar (Nodo* p);
void liberar(Nodo* &p);
Nodo* buscar(Nodo* p, int v);
void eliminar(Nodo*&p, int v);
int eliminarPrimerNodo(Nodo*&p);
Nodo* insertarOrdenado(Nodo*&p, int v);
*/

//30-09

struct Nota {
	int nota;
	Nota* sig;
};

struct infoestudiante {
	int id;
	Nota* notas[4]; // lista de arreglos
};

struct Estudiante {
	infoestudiante infoEst;
	Estudiante* sigEst;
};

struct infocurso {
	int id;
	int promocionados;
	int regularizados;
	int recursantes;
	Estudiante* listaEstudiantes; // lista de estudiantes
};

struct Curso{ // es una lista que apunta a datos (infoCur) (Es el primero nodo de una lista enlazada de cursos)
	infocurso infoCur;
	Curso* sigCur; // el siguiente va en la lista y no en infoCurso
};

// ----------------------------- Para grabar el archivo
struct novedad {
	int idCurso;
	int idEstudiante;
	int nroEvaluacion;
	int nota;
};

void procesarNovedades(FILE* novedades, Curso* &listaCursos);
void agregarNota(Curso* &listaCursos, int idCurso, int idEstudiante, int nroEvaluacion, int nota);
Curso* buscaEInsertaCurso(Curso* &p, infocurso v, bool & enc);
Curso* buscarCurso(Curso* p, infocurso v);
Curso* agregarCurso(Curso* &p, infocurso x);
Estudiante* buscaEInsertaEstudiante(Estudiante* &p, infoestudiante v, bool & enc);
Estudiante* buscarEstudiante(Estudiante* p, infoestudiante v);
Estudiante* agregarEstudiante(Estudiante* &p, infoestudiante x);
void agregarNota(Nota* &p, int x);
int getEstado(int notas[], int len);
void calcularEstadisticas(Curso* listaCursos);


int main()
{

//Desarrollo del Final
	Curso* listaCursos = NULL;
	FILE * novedades = fopen("novedades.dat","rb");

	procesarNovedades(novedades, listaCursos);

	//Nos sirve para chequear que la estructura est� bien cargada
	/*Curso* auxCurso = listaCursos;

	while(auxCurso != NULL){
		cout << "Curso nro " << auxCurso->infoCur.id << endl;
		Estudiante* auxEst = auxCurso->infoCur.listaEstudiantes;
		while(auxEst != NULL){
			cout << "Estudiante nro " << auxEst->infoEst.id << endl;

			cout << "Notas de la 1era Evaluacion" << endl;
			Nota* aux1erEvaluacion = auxEst->infoEst.notas[0];
			while(aux1erEvaluacion != NULL) {
				cout << aux1erEvaluacion->nota << endl;
				aux1erEvaluacion = aux1erEvaluacion->sig;
			}

		 	cout << "Notas de la 2da Evaluacion" << endl;
			Nota* aux2daEvaluacion = auxEst->infoEst.notas[1];
			while(aux2daEvaluacion != NULL) {
				cout << aux2daEvaluacion->nota << endl;
				aux2daEvaluacion = aux2daEvaluacion->sig;
			}

			cout << "Notas de la 3era Evaluacion" << endl;
			Nota* aux3eraEvaluacion = auxEst->infoEst.notas[2];
			while(aux3eraEvaluacion != NULL) {
				cout << aux3eraEvaluacion->nota << endl;
				aux3eraEvaluacion = aux3eraEvaluacion->sig;
			}

			cout << "Notas de la 4ta Evaluacion" << endl;
			Nota* aux4taEvaluacion = auxEst->infoEst.notas[3];
			while(aux4taEvaluacion != NULL) {
				cout << aux4taEvaluacion->nota << endl;
				aux4taEvaluacion = aux4taEvaluacion->sig;
			}

			auxEst = auxEst->sigEst;
		}
		auxCurso = auxCurso->sigCur;
	}
	*/

	calcularEstadisticas(listaCursos);

	//Quiero imprimir las estadisticas por curso
	Curso* auxCurso = listaCursos;
	while(auxCurso!= NULL){
		cout << "Curso nro " << auxCurso->infoCur.id << endl;
		cout << "Promocionados " << auxCurso->infoCur.promocionados << endl;
		cout << "Regularizados " << auxCurso->infoCur.regularizados << endl;
		cout << "Recursantes " << auxCurso->infoCur.recursantes << endl;
		cout << "--------------------" << endl;
		auxCurso = auxCurso->sigCur;
	}


	fclose(novedades);

    return 0;
}
// TODAS LAS NOTAS ESTAN EN UN ARCHIVO ENTONCES NOSOTROS LO QUE HACEMOS ES PASARLAS A LAS LISTA DE CURSOS
void procesarNovedades(FILE* novedades, Curso* &listaCursos){
	 novedad reg;
	 fread(&reg, sizeof(novedad),1,novedades);

	 while(!feof(novedades)){
	 	 agregarNota(listaCursos, reg.idCurso, reg.idEstudiante, reg.nroEvaluacion, reg.nota);
		 fread(&reg, sizeof(novedad),1,novedades);
	 }
}

void agregarNota(Curso* &listaCursos, int idCurso, int idEstudiante, int nroEvaluacion, int nota) {
	  bool enc;
    // PRIMERO LO QUE HACE ES PASAR LA INFORMACION A LA ESTRUCTURA DONDE ESTA LA INFORMACION DEL CURSO (INFOCUR)
    // FIJATE QUE ACCEDE DIRECTO AHI Y NO A TRAVES DE LA LISTA DE CURSOS
	  infocurso datosCur;

	  datosCur.id = idCurso;
	  datosCur.promocionados = 0; // ESTAN INICIALIZADOS EN 0 PORQUE SI NO ESTA EL CURSO LO AGREGA, Y SI ESTA EL CURSO NO LO AGREGA
	  datosCur.recursantes = 0;
	  datosCur.regularizados = 0;
	  datosCur.listaEstudiantes = NULL;

	  Curso* cursoDeInteres = buscaEInsertaCurso(listaCursos,datosCur,enc); // BUSCA, SI ESTA NO HACE NADA Y SI NO ESTA LO AGREGA

	  infoestudiante datosEst;

	  datosEst.id = idEstudiante;
	  datosEst.notas[0] = NULL; // ESTAN INICIALIZADOS EN 0 PORQUE SI NO ESTA EL ESTUDIANTE LO AGREGA, Y SI ESTA EL ESTUDIANTE NO LO AGREGA
	  datosEst.notas[1] = NULL;
	  datosEst.notas[2] = NULL;
	  datosEst.notas[3] = NULL;

	  Estudiante* estudianteDeInteres = buscaEInsertaEstudiante(cursoDeInteres->infoCur.listaEstudiantes,datosEst,enc);

	  agregarNota(estudianteDeInteres->infoEst.notas[nroEvaluacion-1],nota); // AGREGA LA NOTA EN EL VECTOR DE LISTAS
                                                                             // -1 PORQUE NROEVALUACION EMPIEZA EN 1 Y NUESTRAS POSICIONES EMPIEZAN EN 0
}

void calcularEstadisticas(Curso* listaCursos){
	int ultimasNotas[4];
	Curso* auxCurso = listaCursos; // PUNTERO A LA LISTA DEL CURSO
	int len = 4;
	int estadoEstudiante;

	while(auxCurso != NULL){
		Estudiante* auxEst = auxCurso->infoCur.listaEstudiantes; // PUNTERO A LA LISTA ESTUDIANTES ACCEDIENDO DESDE EL PUNTERO DE CURSO
		while(auxEst != NULL){

			/*Nota* aux1erEvaluacion = auxEst->infoEst.notas[0];
			while(aux1erEvaluacion->sig != NULL) {
				aux1erEvaluacion = aux1erEvaluacion->sig;
			}
			ultimasNotas[0] = aux1erEvaluacion->nota;

			Nota* aux2daEvaluacion = auxEst->infoEst.notas[1];
			while(aux2daEvaluacion->sig != NULL) {
				aux2daEvaluacion = aux2daEvaluacion->sig;
			}
			ultimasNotas[1] = aux2daEvaluacion->nota;

			Nota* aux3eraEvaluacion = auxEst->infoEst.notas[2];
			while(aux3eraEvaluacion->sig != NULL) {
				aux3eraEvaluacion = aux3eraEvaluacion->sig;
			}
			ultimasNotas[2] = aux3eraEvaluacion->nota;

			Nota* aux4taEvaluacion = auxEst->infoEst.notas[3];
			while(aux4taEvaluacion->sig != NULL) {
				aux4taEvaluacion = aux4taEvaluacion->sig;
			}
			ultimasNotas[3] = aux4taEvaluacion->nota;
			*/

			//Otra forma m�s corta

			for(int i =0; i < len; i++){
				Nota* notaEvaluacion = auxEst->infoEst.notas[i];
				while(notaEvaluacion->sig != NULL) {                // RECORRO HASTA EL ULTIMO NODO Y ME LO QUEDO
					notaEvaluacion = notaEvaluacion->sig;
				}
				ultimasNotas[i] = notaEvaluacion->nota;
			}

			estadoEstudiante = getEstado(ultimasNotas,len);

			switch(estadoEstudiante){
				case 1:
					auxCurso->infoCur.promocionados++;
					break;
				case 2:
					auxCurso->infoCur.regularizados++;
					break;
				case 3:
					auxCurso->infoCur.recursantes++;
					break;
			}

			auxEst = auxEst->sigEst;
		}
		auxCurso = auxCurso->sigCur;
	}


}

//notas tiene la ultima nota de c/evaluacion
int getEstado(int notas[], int len){
	int estado;
	int promocion = 0;
	int recursa = 0;
	int regulariza = 0;

	for(int i = 0; i <len; i++){
		if(notas[i] < 6 ){
			recursa++;
		} else if( notas[i] >= 6 && notas[i] < 8){
			regulariza++;
		} else {
			promocion++;
		}
	}

	if(promocion == 4){
		estado = 1;
	} else if(recursa >= 1){
		estado = 3;
	} else {
		estado = 2;
	}

	return estado;
}


////////////////////////////////////////////////////////////////
void agregarNota(Nota* &p, int x) {
	Nota* nuevo = new Nota();
	nuevo->nota = x;
	nuevo->sig = NULL;
	if(p==NULL) { // la lista p esta vac�a
		p = nuevo;
	} else {
		Nota* aux = p;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

Estudiante* buscaEInsertaEstudiante(Estudiante* &p, infoestudiante v, bool & enc){
	Estudiante * nodoBuscado = buscarEstudiante(p,v);
	if(nodoBuscado != NULL) { // el nodo est� en la lista
		enc = true;
	} else { // el nodo no est�
		nodoBuscado = agregarEstudiante(p,v);
		enc = false;
	}

	return nodoBuscado;
}

Estudiante* buscarEstudiante(Estudiante* p, infoestudiante v){
	Estudiante* aux = p;
	while(aux!= NULL && aux->infoEst.id != v.id){
		aux = aux->sigEst;
	}
	return aux;
}

Estudiante* agregarEstudiante(Estudiante* &p, infoestudiante x){
	Estudiante* nuevo = new Estudiante();
	nuevo->infoEst = x;
	nuevo->sigEst = NULL;
	if(p==NULL) { // la lista p esta vac�a
		p = nuevo;
	} else {
		Estudiante* aux = p;
		while(aux->sigEst != NULL) {
			aux = aux->sigEst;
		}
		aux->sigEst = nuevo;
	}

	return nuevo;
}

Curso* buscaEInsertaCurso(Curso* &p, infocurso v, bool & enc){
	Curso * nodoBuscado = buscarCurso(p,v);
	if(nodoBuscado != NULL) { // el nodo est� en la lista
		enc = true;
	} else { // el nodo no est�
		nodoBuscado = agregarCurso(p,v);
		enc = false;
	}

	return nodoBuscado;
}

Curso* buscarCurso(Curso* p, infocurso v) {
	Curso* aux = p;
	while(aux!= NULL && aux->infoCur.id != v.id){
		aux = aux->sigCur;
	}
	return aux;
}

Curso* agregarCurso(Curso* &p, infocurso x){
	Curso* nuevo = new Curso();
	nuevo->infoCur = x;
	nuevo->sigCur = NULL;
	if(p==NULL) { // la lista p esta vac�a
		p = nuevo;
	} else {
		Curso* aux = p;
		while(aux->sigCur != NULL) {
			aux = aux->sigCur;
		}
		aux->sigCur = nuevo;
	}

	return nuevo;
}









/*
Nodo* insertarOrdenado(Nodo*&p, int v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	Nodo* ant = NULL;
	Nodo* aux = p;

	while(aux!=NULL && aux->info <= v) {
		ant = aux;
		aux = aux->sig;
	}

	if(ant == NULL){ //Estoy insertando al principio
		p= nuevo;
	} else {
		ant->sig = nuevo;
	}
	nuevo->sig = aux;

	return nuevo;
}

int eliminarPrimerNodo(Nodo*&p) {
	int retorno = p->info;
	Nodo* aux = p;
	p = p->sig;
	delete aux;
	return retorno;
}

void eliminar(Nodo*&p, int v) {
	Nodo* aux = p;
	Nodo* ant = NULL;
	while(aux!= NULL && aux->info != v){
		ant = aux;
		aux = aux->sig;
	}

	if(ant == NULL) { //Estamos eliminando el primer nodo
		p = aux->sig;
	} else {
		ant->sig = aux->sig;
	}

	delete aux;
}

Nodo* buscar(Nodo* p, int v) {
	Nodo* aux = p;                          // PUNTERO A LA DIRECCION DE MEMORIA DE LA LISTA
	while(aux!= NULL && aux->info != v){
		aux = aux->sig;                     // AVANZAMOS
	}
	return aux;                             // SI SALE DEL WHILE ES PORQUE LO ENCONTRO O ESTA VACIA. SI LO ENCUENTRA ME DEVUELVE AUX (DIRECC DE MEMORIA)
}

void liberar(Nodo*&p){
	Nodo* aux;
	while(p!=NULL) {
		aux = p;
		p=p->sig;           // AVANZO CON P
		delete aux;         // ELMINIO NODOS CON AUX PORQUE TIENE LA MISMA DIRECCION QUE P
	}
}

void mostrar (Nodo* p) {
	Nodo* aux = p;
	while(aux != NULL) {            // ES AUX Y NO AUX SIGUIENTE PORQUE PRIMERO PREGUNTA POR EL PRIMER NODO
		cout << aux->info << endl;  // MOSTRAR EL CONTENIDO DEL NODO
		aux = aux->sig;             // AVANZAR
	}
}

void agregarNodo(Nodo* &p, int x) { // LE PASO LA LISTA Y UN VALOR INT
	Nodo* nuevo = new Nodo();     // RESERVO UN ESPACIO PARA UNA VARIABLE DE TIPO NODO
	nuevo->info = x;              // LO QUE VA A TENER ADENTRO EL NODO
	nuevo->sig = NULL;            // EL SIGUIENTE DE NUEVO ES NULL SIEMPRE (ES EL ULTIMO)
	if(p==NULL) { // SI LA LISTA p ESTA VACIA
		p = nuevo; // ES DECIR QUE LE ASIGNO A LA LISTA UN NUEVO (NODO)
	} else {
		Nodo* aux = p;            // NODO AUXILIAR QUE LE ASIGNO EL VALOR DE LA LISTA
		while(aux->sig != NULL) {
			aux = aux->sig;         // ESO ES PARA AVANZAR
		}
		aux->sig = nuevo;           // ENGANCHAR EL NUEVO NODO
	}

}
*/
