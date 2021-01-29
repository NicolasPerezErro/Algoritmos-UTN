#include <iostream>

using namespace std;


// ARCHIVO
struct ingreso {
	int nroSocio;
	int nroSucursal;
	int estadia;
};


// LISTAS
struct infoSocio {
	int nroSocio;
	int cantVisitas;
	int estadiaTotal;
};

struct Socio {
	infoSocio info;
	Socio* sig;
};

struct infoSuc {
	int nroSucusal;
	int cantPersonasDistintas;
	int cantVisitas;
	Socio* listaSocios;
};

struct Sucursal {
	infoSuc info;
	Sucursal* sig;
};

Sucursal* buscaEInsertaSucursal(Sucursal* &p, infoSuc v, bool & enc);
Sucursal* buscarSucursal(Sucursal* p, infoSuc v);
Sucursal* agregarSucursal(Sucursal* &p, infoSuc x);

Socio* buscaEInsertaSocio(Socio* &p, infoSocio  v, bool & enc);
Socio* buscarSocio(Socio* p, infoSocio v);
Socio* agregarSocio(Socio* &p, infoSocio x);

int main()
{

 FILE * archIngreso = fopen("ingreso.dat","rb");
	ingreso reg;
	Sucursal * listaSucursales = NULL;
	Sucursal * sucursalBuscada;
	Socio * socioBuscado;
	bool encSuc;
	bool encSoc;
	infoSuc infoS;
	infoSocio infoSoc;

	fread(&reg,sizeof(ingreso),1, archIngreso);
	while(!feof(archIngreso)){

		infoS.nroSucusal = reg.nroSucursal;
		infoS.cantPersonasDistintas = 0;
		infoS.cantVisitas = 0;
		infoS.listaSocios = NULL;

		sucursalBuscada = buscaEInsertaSucursal(listaSucursales,infoS, encSuc);

		infoSoc.nroSocio = reg.nroSocio;
		infoSoc.cantVisitas = 1;
		infoSoc.estadiaTotal = reg.estadia;

		socioBuscado = buscaEInsertaSocio(sucursalBuscada->info.listaSocios,infoSoc, encSoc);

		if(encSoc){ // SI EL SOCIO ESTA, ENTONCES AUMENTO CANT DE VISITAS Y AUMENTO LA ESTADIA TOTAL
			socioBuscado->info.cantVisitas ++;
			socioBuscado->info.estadiaTotal += reg.estadia;
		} else {
			sucursalBuscada->info.cantPersonasDistintas++; // SI NO ESTA EL SOCIO QUIERE DECIR QUE ES UNA PAERSONA NUEVA, ENTONCES AUMENTO PERSONA DISTINTA
		}

		sucursalBuscada->info.cantVisitas ++;

		fread(&reg,sizeof(ingreso),1, archIngreso);
	}

	fclose(archIngreso);

	Sucursal * auxSuc = listaSucursales;
	int maxEstadia = 0;
	int maxSocio = 0;
	int maxSucursal = 0;

	cout << "Septiembre" << endl;
	while(auxSuc != NULL) {
		cout << "Nro de Suc: " << auxSuc->info.nroSucusal << " - " << "Cantidad de Visitas: " <<
		auxSuc->info.cantVisitas << " - " << "Cantidad de Personas Distintas: " << auxSuc->info.cantPersonasDistintas << endl;

		Socio * auxSoc = auxSuc->info.listaSocios;
		while(auxSoc != NULL){
			if(auxSoc->info.estadiaTotal > maxEstadia){
				maxEstadia = auxSoc->info.estadiaTotal;
				maxSocio = auxSoc->info.nroSocio;
				maxSucursal = auxSuc->info.nroSucusal;
			}
			auxSoc = auxSoc->sig;
		}

		auxSuc = auxSuc->sig;
	}

	cout << "El socio de mas estadia en septiembre fue: " << maxSocio << " con " <<
	maxEstadia << " minutos, en la sucursal " << maxSucursal << endl;


    return 0;
}




Socio* buscarSocio(Socio* p, infoSocio v){
	Socio* aux = p;
	while(aux!= NULL && aux->info.nroSocio != v.nroSocio){
		aux = aux->sig;
	}
	return aux;
}

Socio* agregarSocio(Socio* &p, infoSocio x){
	Socio* nuevo = new Socio();
	nuevo->info = x;
	nuevo->sig = NULL;
	if(p==NULL) { // la lista p esta vac�a
		p = nuevo;
	} else {
		Socio* aux = p;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

	return nuevo;
}

Socio* buscaEInsertaSocio(Socio* &p, infoSocio v, bool & enc) {
	Socio * nodoBuscado = buscarSocio(p,v);
	if(nodoBuscado != NULL) { // el nodo est� en la lista
		enc = true;
	} else { // el nodo no est�
		nodoBuscado = agregarSocio(p,v);
		enc = false;
	}

	return nodoBuscado;
}


Sucursal* buscarSucursal(Sucursal* p, infoSuc v){
	Sucursal* aux = p;
	while(aux!= NULL && aux->info.nroSucusal != v.nroSucusal){
		aux = aux->sig;
	}
	return aux;
}

Sucursal* agregarSucursal(Sucursal* &p, infoSuc x){
	Sucursal* nuevo = new Sucursal();
	nuevo->info = x;
	nuevo->sig = NULL;
	if(p==NULL) { // la lista p esta vac�a
		p = nuevo;
	} else {
		Sucursal* aux = p;
		while(aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}

	return nuevo;
}

Sucursal* buscaEInsertaSucursal(Sucursal* &p, infoSuc v, bool & enc) {
	Sucursal * nodoBuscado = buscarSucursal(p,v);
	if(nodoBuscado != NULL) { // el nodo est� en la lista
		enc = true;
	} else { // el nodo no est�
		nodoBuscado = agregarSucursal(p,v);
		enc = false;
	}

	return nodoBuscado;
}
