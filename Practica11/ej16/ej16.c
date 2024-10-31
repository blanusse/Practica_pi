#include <stdlib.h>
#include <stdio.h>


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

// a)	La información de alumnos de los cursos activos (los del cuatrimestre) de una universidad,
// donde se sabe que todos los cursos tienen un cupo máximo de 50 alumnos.
// Los accesos más comunes serán por Nombre del curso, y para un curso por legajo de alumno
// (para buscar un alumno se indica nombre de curso y legajo).

struct tAlumno {
    char *nombre; //nombre
    char *apellido; //apellido
    int legajo; //legajo
    int promedio; //promedio
    struct tAlumno *nextAlumno; //puntero al alumno con el siguiente legajo
};

struct tCurso {
    struct tAlumno curso[50]; //vector con maximo de 50 alumnos
    size_t dimCurso; //cantidad de alumnos en el curso
    int (*compare)(int, int); //puntero a funcion para ordenar alumnos por legajo
    struct tCurso *nextCurso; //puntero al siguiente curso
};
typedef struct tCurso *tITBA;

struct alumnosCDT {
    tITBA facultad; //puntero a lista de cursos de la facultad
    size_t dimFacultad; //cantidad de cursos
    int (*compare)(char *, char *); //puntero a funcion para ordenar cursos alfabeticamente
};
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

// b)	Los horarios que cursa un alumno de una universidad, distinguiendo por materia

struct tHorario {
    char start[5]; //hora de inicio formato 00:00
    char end[5]; //hora de fin formato 00:00
    struct tHorario *nextDay; //puntero al siguiente dia con esta materia
};
typedef struct tHorario *tHorarioList;

struct tNodeMateria {
    char *materia; //nombre de la materia
    tHorarioList horarios; //lista con horarios de la materia
    struct tNodeMateria *nextMat; //puntero a la siguiente materia de la lista
};

typedef struct tNodeMateria *tList;

struct horariosCDT {
    tList materias; //puntero a lista de materias
    int (*compare)(char *, char*);// puntero a funcion para ordenar materias alfabeticamente
    size_t matCount; //cantidad de materias
};

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

// c)	Un restorán necesita saber, al cabo de un año, cuánto facturó día por día.

struct tDay {
    int dayN; //dia N del mes
    int money; //plata ganada ese dia
    struct tDay *nextDay; //puntero al siguiente dia
};
typedef struct tDay *tMonthDays;

struct tMonth {
    char *month; //nombre del mes
    tMonthDays day; //puntero a lista de dias del mes
    size_t monthDim; //cantidad de dias del mes
    struct tMonth *nextMonth;
};
typedef struct tMonth *tListFact;

struct facturaCDT {
    tListFact first; //puntero a lista de meses
};
//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------



// d)	Una computadora tiene conectado un termómetro, y cada vez que la temperatura supera un determinado umbral
// (por ejemplo 40 grados centígrados) debe registrar la hora en que superó ese umbral
// y la hora en que volvió a bajar (por ejemplo: si a las 8:10 pasó los 40 grados
// y a las 9:23 la temperatura descendió por debajo de los 40 grados, tendría que haber una entrada con los valores {8:10, 9:23})

struct tActive {
    char start[5]; //hora de inicio formato 00:00
    char end[5]; //hora de fin formato 00:00
    struct tActive *nextActive; //puntero a la siguiente activacion
};


struct termometroCDT {
    struct tActive *tActiveList; //lista de momentos de activacion
    size_t activeDim; //veces que se activo
};


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


// e)	Se quiere almacenar un diccionario de palabras en inglés ordenado en forma alfabética,
// de tal forma que se pueda acceder rápidamente a todas las palabras que comienzan con una letra determinada.
// Se espera que este diccionario ordenado tenga mucho "movimiento" de palabras (agregar y borrar palabras).
// Las palabras comienzan sí o sí con una letra del alfabeto inglés.

struct tWord {
    char *word; //palabra
    struct tWord *nextWord; //puntero a la siguiente palabra
};

typedef struct tWord *tWordList;

struct tLetter {
    char letter; //letra
    tWordList list; //lista de palabras con esta letra
    size_t letterDim; //cantidad de palabras con esta letra
    struct tLetter *nextLetter; //puntero a la siguiente letra
};

typedef struct tLetter *tDiccionary;

struct diccionarioCDT {
    tDiccionary diccionary; //puntero a lista tLetter
    size_t cantLetters; //cantidad de letras
    int (*compare)(char *, char *); //funcion para ver si una palabra va antes o despues
};


//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


// f)	Se desea almacenar información sobre el censo nacional, de forma tal que se puedan obtener las siguientes estadísticas
// i)	Total de población por provincia
// ii)	Total de población de cada departamento, donde se pueda listar por orden de Provincia / Departamento.
// Por ejemplo primero todos los departamentos de Buenos Aires, luego los de Catamarca, etc

struct tDepartamento {
    char *nombre; // nombre del departamento
    int poblacion; //poblacion del departamento
    struct tDepartamento *nextDept; //puntero al siguiente departamento
};
typedef struct tDepartamento *tListDep;


struct tProvincia {
    char *nombre; // nombre de la provincia
    int poblacion; //poblacion de la provincia
    tListDep departamento; //puntero a lista de departamentos
    size_t cantDept; //cantidad de departamentos
    struct tProvincia *nextProv; //puntero a siguiente provincia
};

typedef struct tProvincia *tPais;

struct poblacionCDT {
    tPais list; //puntero a lista de provincias
    size_t cantProv; //cantidad de provincias
};



//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------

// g)	Para hacer un seguimiento de los alumnos que ingresaron en un cuatrimestre, se desea mantener la información de los mismos
// (datos, materias que está cursando). El acceso a la información de un alumno será por legajo.
// Sólo se mantiene información de los alumnos que ingresaron en el cuatrimestre.
// El uso más frecuente será la consulta individual por número de legajo.

struct tMateria {
    char *nombre; //nombre de la materia
    struct tMateria *nextMateria; //puntero a la siguiente materia cursando
};

struct tAlumno2 {
    char *nombre; //nombre
    char *apellido; //apellido
    int legajo; //legajo
    int promedio; //promedio
    struct tAlumno *nextAlumno; //puntero al alumno con el siguiente legajo};
};

typedef struct tAlumno2 *tFacultad;

struct facultadCDT {
    tFacultad list; //lista de alumnos;
    size_t listDim; //cantidad de alumnos;
    int (*compare)(int, int);//puntero a funcion para ordenar alumnos por legajo
};

//-------------------------------------------------------//////\\\\\\-------------------------------------------------------------------


// h)	¿Cómo cambiaría el punto anterior si se quiere mantener un histórico de esta información?
// Esto es, poder seleccionar cuatrimestre y legajo. O resumir cómo les fue en su primer cuatrimestre a los
// ingresados en un cuatrimestre específico (% de recursantes, promedio de cursada, etc.)


