/**************************************
* NOMBRE: #   #
* PRIMER APELLIDO:  #   #
* SEGUNDO APELLIDO: #   #
* DNI: #   #
* EMAIL: #@alumno.uned.es#
***************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



typedef char tipoCadena[30];  // Tipo definido para mostrar cadenas de texto
typedef tipoCadena tipoMonths [12]; // Tipo definido para los meses del año como string
tipoMonths mes_letra = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE" };

typedef enum TipoDia {Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo};
typedef enum TipoMes {Enero, Febrero, Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre};



typedef struct RegTipoFecha {
  int dia;
  TipoMes mes;
  int anno;
};




// Funcion para solicitar los datos de la hoja del calendario
int FuncPedirDatos(int &month, int &year){

  printf("¿Mes (1..12)?");
  scanf("%d", &month);
  printf("¿Ano (1601..3000)?");
  scanf("%d", &year);

  // salida para prueba. Eliminar en version produccion
  printf("\n");
  printf("FuncPedirDatos MOSTRAR HOJA: Mes %d - Ao %d \n\n", month, year);

  return year;

}



// Funcion para determinar los anos bisiestos
bool FuncCalcularBisiesto (int year){

  int bisiesto;

  if ( year %4 == 0  && !(year %100 == 0 && year %400 != 0) ) {
    bisiesto = 1;
   // printf("El ano %d es bisiesto \n", year);

  } else {
    bisiesto = 0;
   // printf("Este ano %d NO es bisiesto \n", year);

  }

  return bisiesto;


}


// Cabecera datos del Calendario ano y mes. Primera linea
void ProcCabeceraDatos(int month, int year){
   char blanco = ' ';
   int linea = 24;
   int len;
   len = strlen(mes_letra[month-1]);

  printf("%s", mes_letra[month-1]);

      for (int i = 0; i<=linea-len; i++){ // bucle para alinear la cabecera del mes y año a la hoja del calendario
        printf("%c", blanco);
        }

  printf("%d", year);
  printf("\n");

}


// Procedimiento para imprimir la linea de separacion de la cabecera
void ProcSeparadorLineaH (){

  int size= 29;

  for (int i = 1; i <= size; i++){
    printf("=");
  }

  printf("\n");

}



/*===================================================
  Funcion para sumar dias de la semana ciclicamente
  =================================================*/

TipoDia FuncSumarDias ( TipoDia dia, int n){
    const int DiasSemana = 7;
    int aux;

    aux = (int(dia) + n ) % DiasSemana;
    return TipoDia(aux);
}


/*===================================================
  Funcion para calcular el dia de la semana que
  corresponde a una fecha
  =================================================*/

TipoDia FuncDiadelaSemana( RegTipoFecha fecha) {
  const int anoinicial = 1601;
  TipoDia diainicial = Lunes;

  bool bisiesto;
  int IncreBisis = 0;
  int IncreAnnos = 0;
  int IncreDias = 0;
  TipoMes M = fecha.mes;
  int A = fecha.anno;

  if ( M == Enero ){
    IncreDias = 0;

  } else if( M == Febrero ){
    IncreDias = 3;

  } else if ( M == Marzo ){
    IncreDias = 3;

  } else if ( M == Abril){
    IncreDias = 6;

  } else if ( M == Mayo ){
    IncreDias = 1;

  } else if ( M == Junio ){
    IncreDias = 4;

  } else if ( M == Julio ){
    IncreDias = 6;

  } else if ( M == Agosto ){
    IncreDias = 2;

  } else if ( M == Septiembre ){
    IncreDias = 5;

  } else if ( M == Octubre ){
    IncreDias = 0;

  } else if ( M == Noviembre ){
    IncreDias = 3;

  } else {
    IncreDias = 5;
    }

// Calculamos los años bisiestos desde la fecha inicial

  for (int i = anoinicial; i <= fecha.anno; i++){
    if ( FuncCalcularBisiesto(i)){
      IncreBisis++;
    }
  }

  if (FuncCalcularBisiesto(fecha.anno) && (M <= Febrero)){
      IncreDias --;
  }


  IncreAnnos = A - anoinicial; // Anos transcurridos desde anoincial 1601
  IncreDias = IncreDias + fecha.dia + IncreAnnos + IncreBisis;


  return FuncSumarDias (diainicial, IncreDias);

}





// ----------------------   PROGRAMA PINCIPAL   -----------------  //


int main () {

    // Definimos e inicializamos variables
    TipoDia diainicio = Lunes;
    int month = 0;
    int year = 1601;
    tipoCadena texto = "LU  MA  MI  JU  VI  |  SA  DO";
    RegTipoFecha fecha;
    int primerdia;


  // Pedimos datos al usuario

  FuncPedirDatos(month, year);
  FuncCalcularBisiesto(year); // Llamdada a funcion para comprobar el funcionamiento correcto de la misma. ELIMINAR

  printf("\n"); // Salto de linea para clarida de lectura Eliminar si es necesario

    // Actualizamos la variable de tipo fecha con los datos introducidos
    fecha.dia = 0;
    fecha.mes = TipoMes(month-1);
    fecha.anno = year;



  // INICIO CABECERA DEL CALENDARIO
    ProcCabeceraDatos(month, year);
    ProcSeparadorLineaH();
    printf("%s", texto);
    printf("\n");
    ProcSeparadorLineaH();
  // FIN CABECERA DEL CALENDARIO

  printf("\n"); // Salto de linea para clarida de lectura Eliminar si es necesario

  primerdia = FuncDiadelaSemana(fecha);


  //  Calcular dia de la semana inicial

  printf("\n"); // Salto de linea para clarida de lectura Eliminar si es necesario

  printf("El dia de inicio del mes en variable fecha es: %d \n", primerdia);
  printf("variable fecha.dia es: %d \n", fecha.dia);
  printf("variable fecha.mes es: %d \n", fecha.mes);
  printf("variable fecha.anno es: %d \n", fecha.anno);


  printf("\n"); // Salto de linea para clarida de lectura Eliminar si es necesario
  printf("\n"); // Salto de linea para clarida de lectura Eliminar si es necesario
  printf("\n"); // Salto de linea para clarida de lectura Eliminar si es necesario



  printf("\n");
  printf("\n");



}














