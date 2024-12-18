#define GET_Y    10000
/*define para guardar los primeros 2 digitos del id o los utlimos 4 digitos del id*/


struct tStudent{
  char *name; /* nombre del alumno */
  unsigned char *notas; /*vector dinamico de notas, donde la materia de codigo 10 estara en notas[0]*/
  char isOcuppied; /* flag de si esta ocupado o no*/

};
typedef struct tStudent *tCourse;


struct courseCDT{
  tCourse students; /* vector con alumnos, donde el legajo 25001 sera el students[0]*/
  size_t studentsDim; /*lugar reservado en el vector students*/
  size_t studentsCount; /* cantidad de alumnos anotados*/
  size_t year; /* ultimos dos digitos del anio*/
  size_t subjectsCount;  /*cantidad de materias*/
};
/*-----------------------------------------------------------------------------------------*/
courseADT newCourse(size_t year, size_t subjects){
  courseADT toReturn = malloc(sizeof(struct courseCDT));
  toReturn->students = NULL;
  toReturn->studentsDim = 0;
  toReturn->studentsCount = 0;
  toReturn->year = year % 100; /*guarda solo los ultimos dos digitos del anio*/
  toReturn->subjectsCount = subjects;
}
/*-----------------------------------------------------------------------------------------*/
int addStudent(courseADT course, size_t id, const char * name){

/*guarda los ultimos cuatro digitos del id*/
size_t legajo = id % GET_Y;

/*id invalido (o no pertenece al año, o es el YEAR0000)*/
  if(id/GET_Y != course->year || legajo == 0){
    return 0;
  }

  if(legajo > course->studentsDim){ /*significa que hay que agrandar el vector*/

      /*agrando el vector de alumnos*/
      course->students = realloc(course->students, sizeof(struct tStudent) * legajo);

      /*pongo todo en cero*/
      for(int i=course->studentsDim; i<legajo; i++){
          /*setea el name en NULL*/
          course->students[i].name = NULL;

          /*setea todas las notas de todos los nuevos posibles alumnos en cero*/
          course->students[i].notas = calloc(1, sizeof(unsigned char) * (course->subjectsCount));
          course->students[i].isOcuppied = 0;
      }

      /*Agrando la capacidad del vector de alumnos*/
      course->studentsDim = legajo;
  }
  /*Como el vector de alumnos tiene el suficiente espacio, me fijo si ya hay uno con ese legajo*/

  if(course->students[legajo-1].isOcuppied == 0){ /*significa que no hay alumno con ese id*/

   /* Para guardar una copia del nombre agrando el lugar donde va y despues lo copio
   * ya que en el programa de prueba se usa un char[] que se va cambiando
   */
   course->students[legajo-1].name = realloc(course->students[legajo-1].name, strlen(name)+1);
   strcpy(course->students[legajo-1].name, name);
   course->students[legajo-1].isOcuppied = 1;
   course->studentsCount++;
   return 1;
  }
/*como existe algun alumno con ese legajo, devuelvo cero*/
  return 0;

}
/*-----------------------------------------------------------------------------------------*/

char * studentName(const courseADT course, size_t id){
  size_t legajo = id % GET_Y; /*guarda los ultimos cuatro digitos*/

  if(id/GET_Y != course->year || legajo == 0 || legajo > course->studentsDim || course->students[legajo-1].isOcuppied == 0 ){

    /*significa que el id esta mal o que no existe ese id todavia*/
    return NULL;
  }
  char *toReturn = malloc(sizeof(char) * (strlen(students[legajo-1].name) + 1));
  strcpy(toReturn, students[legajo-1].name);
  return toReturn;
}
/*-----------------------------------------------------------------------------------------*/

size_t students(const courseADT course){
  return course->studentsCount;
}
/*-----------------------------------------------------------------------------------------*/

int setGrade(courseADT course, size_t id, size_t subject, unsigned char grade){
  int subjectN = subject / 10; /*guarda el numero de materia*/
  size_t legajo = id % GET_Y; /*guarda solo las ultimas 4 cifras*/
  if(id/GET_Y != course->year || legajo == 0 || legajo > course->studentsDim || course->students[legajo-1].isOcuppied == 0 ){

    /*significa que el id esta mal o que no existe ese id todavia*/
    return 0;
  }
  if(subjectN > course->subjectCount || subject % 10 != 0){

    /*significa que el codigo de materia esta mal*/
    return 0;
  }
  if(grade > 10){

    /*significa que la nota no es valida*/
      return 0;
  }
  /*el alumno y la materia existen y ademas la nota es valida*/
  course->students[legajo-1].notas[subjectN - 1] = grade;
  return 1;

}