void procesarNovedades(FILE* novedades, Curso* &listaCursos){

novedad reg;
fread(&reg,sizeof(novedad),1,novedades);

while (!feof(novedades)){




   fread(&reg,sizeof(novedad),1,novedades);
}

fclose(novedades);


    }


AgregarNota(Curso* lista, int curso, int estudiante, int parcial, int nota){

infocurso datosCur;

Curso* cursoBuscado = buscaEInsertaCurso(lista,datosCur,enc);



}
