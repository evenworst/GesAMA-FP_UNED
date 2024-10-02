#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>




typedef char tipoCadena[30];  // Tipo definido para mostrar cadenas de texto de hasta 30 caracteres
typedef tipoCadena tipoMonths [12]; // Tipo definido para los meses del año como string
//tipoMonths mes_letra = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE" };


typedef enum TipoDia {Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo};
typedef enum TipoMes {Enero, Febrero, Marzo, Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre};



typedef struct RegTipoFecha {
  int dia;
  int mes;
//  TipoMes mes;
  int anno;
};




/*===================================================
              TAD
  =================================================*/


typedef struct CalendarioGesAMA  {

    RegTipoFecha FuncPedirFecha (bool select);      // Funcion para solicitar los datos de la hoja del calendario
    bool FuncCalcularBisiesto (int year);           // Funcion para determinar los anos bisiestos
    void ProcCabeceraDatos(int month, int year);    // Cabecera datos del Calendario ano y mes. Primera linea
    void ProcSeparadorLineaH ();                    // Procedimiento para imprimir la linea de separacion de la cabecera
    TipoDia FuncSumarDias ( TipoDia dia, int n);    //  Funcion para sumar dias de la semana ciclicamente
    TipoDia FuncDiadelaSemana( RegTipoFecha fecha); // Funcion para calcular el dia de la semana que corresponde a una fecha
    int FuncNumeroDias(RegTipoFecha fecha);         // Funcion para calcular el numero de dias que tiene un mes
    void  ProcImprimirDias();     // Procedimiento para imprimir los dias del mes

    /* Nuevos Metodos */

    bool FechaCorrecta ( RegTipoFecha fecha);       // Para comprobar que la fecha introducida es correcta  ELIMINAR NO USADA
    RegTipoFecha DiaTraslado ( RegTipoFecha fecha); // Para calcular la fecha del dia de traslado
    RegTipoFecha DiaFinalizacion (RegTipoFecha fecha, int duracion);  // Calcular la fecha de finalizacion de la cosecha
    bool FechaPosterior ( RegTipoFecha fecha1, RegTipoFecha fecha2);  // Funcion para saber si una fecha1 es posterior a fecha2


    RegTipoFecha fecha;



};
