#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "CalendarioGesAMA.h"
#include "MenuGesAMA4.h"



tipoMonths mes_letra = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE" };

    // Definimos e inicializamos variables
    TipoDia diainicio = Lunes;
    int month = 0;
    int year = 1601;
    tipoCadena texto = "LU  MA  MI  JU  VI | SA  DO";



// Funcion para solicitar los datos de la hoja del calendario
RegTipoFecha CalendarioGesAMA::FuncPedirFecha(bool select){

// ARREGLADO --- TODO (alumno#1#): Puedo pasar por parametro una var bool para controlar si se pide el dia o no
// ARREGLADO --- FIXME (alumno#1#): Con esta comprobacion del dia se podria introducir una fecha incorrecta como por ejemplo 30/02/xxxx. Pagina 388 del libro

    int correct;
    bool validar = false;

    fecha.dia = 0;
    fecha.mes = Enero;
    fecha.anno = 1900;


    do {
    switch (select){
      case true:

          printf("  - Fecha comienzo cosecha: Dia? ");
          scanf("%d", &fecha.dia);
          fflush(stdin);

          printf("  - Fecha comienzo cosecha: Mes? ");
          scanf("%d", &fecha.mes);
          fflush(stdin);

          printf("  - Fecha comienzo cosecha: Anho? ");
          scanf("%d", &fecha.anno);
          fflush(stdin);

          correct = FuncNumeroDias (fecha);

          if ( fecha.dia > correct ) {

              printf( " Fecha introducida invalida \n");
              validar = false;

          } else {
            validar = true;
          }

        break;

    default:
        fecha.dia = 0;

        printf(" Seleccion mes? ");
        scanf("%d", &fecha.mes);
        fflush(stdin);

        printf(" Seleccion anho? ");
        scanf("%d", &fecha.anno);
        fflush(stdin);

        correct = FuncNumeroDias (fecha);

        if ( fecha.dia > correct ) {

            printf( " Fecha introducida invalida \n");
            validar = false;

        } else {
            validar = true;
        }
      }
    } while (!validar);


  return fecha;

}



// Funcion para determinar los anos bisiestos
bool CalendarioGesAMA::FuncCalcularBisiesto (int year){

  int bisiesto;

  if ( year %4 == 0  && !(year %100 == 0 && year %400 != 0) ) {
    bisiesto = 1;
  } else {
    bisiesto = 0;
  }

  return bisiesto;

}



// Cabecera datos del Calendario ano y mes. Primera linea
void CalendarioGesAMA::ProcCabeceraDatos(int month, int year){
   char blanco = ' ';
   int linea = 21;
   int len;
   len = strlen(mes_letra[month-1]);

  printf("               "); // Tabular el calendario
  printf("%s", mes_letra[month-1]);

      for (int i = 0; i<=linea-len; i++){ // bucle para alinear la cabecera del mes y año a la hoja del calendario
        printf("%c", blanco);
        }

  printf("%d", year);
  printf("\n");
  printf("               "); // Tabular el calendario
  printf("LU  MA  MI  JU  VI  SA  DO");
  printf("\n");
}


// Procedimiento para imprimir la linea de separacion de la cabecera
void CalendarioGesAMA::ProcSeparadorLineaH (){

  int size= 27;
  printf("               "); // Tabular el calendario
  for (int i = 1; i <= size; i++){
    printf("-");
  }

  printf("\n");

}



/*===================================================
  Funcion para sumar dias de la semana ciclicamente
  =================================================*/

TipoDia CalendarioGesAMA::FuncSumarDias ( TipoDia dia, int n){
    const int DiasSemana = 7;
    int aux;

    aux = (int(dia) + n ) % DiasSemana;
    return TipoDia(aux);
}



/*===================================================
  Funcion para calcular el dia de la semana que
  corresponde a una fecha
  =================================================*/

TipoDia CalendarioGesAMA::FuncDiadelaSemana( RegTipoFecha fecha) {
  const int anoinicial = 1601;
  TipoDia diainicial = Lunes;

  bool bisiesto;
  int IncreBisis = 0;
  int IncreAnnos = 0;
  int IncreDias = 0;
  TipoMes M = TipoMes(fecha.mes-1);
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




/*===================================================
  Funcion para calcular el numero de dias que
  tiene un mes
  =================================================*/

int CalendarioGesAMA::FuncNumeroDias(RegTipoFecha fecha){
  TipoMes M = TipoMes(fecha.mes - 1);


    switch ( M ){
      case Enero:
      case Marzo:
      case Mayo:
      case Julio:
      case Agosto:
      case Octubre:
      case Diciembre:
        return (31);
      break;

      case  Febrero:
        if (FuncCalcularBisiesto(fecha.anno)){
          return (29);}
        else {
          return (28);
          }
        break;

      case Abril:
      case Junio:
      case Septiembre:
      case Noviembre:
        return (30);
        break;

      default:
        return (-1); // OJO!!!! se cambia valor a -1 para validar la funcion pedirfecha. comprobar posible comportamiento inexperado en calendario

    }
  }



/*===================================================
  Procedimiento para imprimir los dias del mes
  =================================================*/

// Funcion no usada. Viene de PEC3. Se crea una nueva a partir de esta para el programa GesAMA

void  CalendarioGesAMA::ProcImprimirDias(){

  char marcador = '.';
  char separador = '|'; // no usada
  int indice = 0; // Var que imprime los numeros de dia en el calendario



                  // imprimir blancos segun dia de la semana que empieza el mes
                    for (int j = 0; j < FuncDiadelaSemana(fecha); j++){  // FuncDiaSemana devuelve el dia de la semana para empezar a numerar los dias

          // NO SON NECESARIOS LOS SEPARADORES
          //           if (j % 7 == 5){
          //            printf("%c ", separador);
          //           }

                        if (j % 7 == 4){
                          printf(" %c  ", marcador); // Condicional para imprimir solo un espacio antes de la barra separadora

                        } else {
                          printf(" %c  ", marcador);
                        }

                      indice++;

                    }

        // imprimir separadores segun dia de la semana que empieza el mes
                    for (int i = 1; i <= FuncNumeroDias(fecha); i++){  // FuncNumeroDias devuelve el numero total de dias del mes que se le pasa a la funcion


                      if (indice % 7 == 0 && i != 1 ) {
                        printf("\n");

                      }
          // NO SON NECESARIOS LOS SEPARADORES
          //            else if (indice % 7 == 5){
          //
          //               printf("%c ", separador);
          //            }

                          if (indice % 7 == 4) { // Condicional para imprimir solo un espacio antes de la barra separadora

                            printf("%2.2d  ", i);
                          }   // AQUI EMPIEZA LA IMPRESION DE LOS DIAS DEL CALENDARIO

                          else {
                            printf("%2.2d  ", i);
                          }

                      indice++;

                    }

              while (indice %7 != 0){
      // NO SON NECESARIOS LOS SEPARADORES
      //         if (indice %7 == 5){
      //          printf("%c ", separador);}

                    if (indice % 7 == 4){
                      printf(" %c  ", marcador); // Condicional para imprimir solo un espacio antes de la barra separadora

                    } else {
                      printf(" %c  ", marcador);
                    }

                  indice++;
              }


    printf("\n\n");
}







/* *************         NUEVOS METODOS         ***************** */




/*===================================================
  Funcion para sumar dias de la semana ciclicamente
  =================================================*/

RegTipoFecha CalendarioGesAMA::DiaTraslado ( RegTipoFecha fecha){
      int n = 30;

    switch (fecha.mes){
      case 5:
      case 7:
      case 10:
      case 12:
        n = 30;
        break;
      case 3:
        if (FuncCalcularBisiesto(fecha.anno)){
          n = 29;
        } else {
          n = 28;
        }
        break;
      default:
        n = 31;
    }


    if (fecha.dia == 1) {
      fecha.dia = n;
          if (fecha.mes == 1) {
            fecha.mes = 12;
            fecha.anno = fecha.anno - 1;
          }else {
            fecha.mes = fecha.mes - 1;
          }
    } else {
      fecha.dia = fecha.dia - 1 ;
    }


return fecha;


}



/*===================================================
  Funcion para calcular el fin de la cosecha
  =================================================*/

RegTipoFecha CalendarioGesAMA::DiaFinalizacion (RegTipoFecha fecha, int duracion){

    RegTipoFecha fincosecha;
    int day, month, year;
    int diasmes;

    day = fecha.dia;
    month = fecha.mes;
    year = fecha.anno;

    diasmes = FuncNumeroDias(fecha);


    for (int i = 1; i < duracion; i++) {

        day++;


        if (day == diasmes){
          day = 0;
            if ( month == 12) {
              month = 1;
              year++;
            } else {
              month++;
            }
        }

    }

    fincosecha.dia = day;
    fincosecha.mes = month;
    fincosecha.anno = year;

    return fincosecha;

}



/*===================================================
  Funcion para calcular si fecha1 es posterior a fecha2
  =================================================*/


bool CalendarioGesAMA::FechaPosterior ( RegTipoFecha fecha1, RegTipoFecha fecha2){

    bool mayor = false;
    int day1, month1, year1;
    int day2, month2, year2;

    day1 = fecha1.dia;
    month1 = fecha1.mes;
    year1 = fecha1.anno;

    day2 = fecha2.dia;
    month2 = fecha2.mes;
    year2 = fecha2.anno;


    if (year1 >year2){

      mayor = true;
      return mayor;

    } else if (year1 == year2) {

        if (month1 > month2){

          mayor = true;
          return mayor;

        } else if (month1 == month2) {

            if (day1 > day2) {

              mayor = true;
              return mayor;
            }
        }
    }

    return mayor;


}























