#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "MenuGesAMA4.h"



/*===================================================
  Metodo Menu Regreso
  =================================================*/


//void TipoMenu::MenuStartScreen() {
//
//      printf("\n\n"); // saltos de linea por estilo
//      printf("  ********    GesAMA: Gestion de Alquiler de Maquinas Agricolas    ********\n\n");
//      printf("  - Bienvenido al software de gestion de alquiler de maquinaria agricola GesAMA \n");
//      printf("  - para probar el software pulse D y se iniciara automaticamente con datos de demo \n");
//      printf("  - si desea un inicio sin datos pulse B \n");
//
//      printf(" Pulsar (D) Demo data / (B) Inicio sin datos");
//      scanf("%c", option);
//      fflush(stdin);
//
//      switch (toupper(option)){
//        case 'D':
//
//              break;
//        case 'B':
//
//              break;
//        default:
//
//
//
//}



/*===================================================
  Metodo Menu Regreso
  =================================================*/

void TipoMenu::MenuRegreso(){

  printf("Pulsa ENTER para regresar al menu principal");
  getchar();
  fflush(stdin);
  system("cls");

}


/*===================================================
  Metodo Menu Principal
  =================================================*/

void TipoMenu::MenuPrincipal (){

  system("cls");

  b.Init(); // incializo contador vector fincas
  c.Init(); // incializo contador vector alquiler

  demo = false;

if (demo == false){
      printf(" Pulsar (D) Demo data / (B) Inicio sin datos");
      scanf("%c", &opciondemo);
      fflush(stdin);

      a.Init(opciondemo); // inicializo contador vector maquinas

      demo = true;
}


  do {

      printf("\n\n"); // saltos de linea por estilo
      printf("  ********    GesAMA: Gestion de Alquiler de Maquinas Agricolas    ********\n\n");
      printf("  - Editar Maquina          (Pulsar M)\n");
      printf("  - Editar Finca            (Pulsar F)\n");
      printf("  - Listar Maquinas         (Pulsar L)\n");
      printf("  - Estado Fincas           (Pulsar E)\n");
      printf("  - Alquiler Maquina        (Pulsar A)\n");
      printf("  - Plan mensual Maquina    (Pulsar P)\n");
      printf("  - Salir                   (Pulsar S)\n");
      printf("\n");
      printf("  - Teclear una opcion      (M / F / L / E / A / P / S) ");
      scanf("%c", &opcion);
      fflush(stdin);



        switch (toupper(opcion)){

          case 'M':
            MenuEditarMaquina();
            fflush(stdin);
            MenuRegreso();
            break;
          case 'F':
            MenuEditarFinca();
            fflush(stdin);
            MenuRegreso();
            break;
          case 'L':
            MenuListarMaquina();
            fflush(stdin);
            MenuRegreso();
            break;
          case 'E':
            MenuListarFinca();
            fflush(stdin);
            MenuRegreso();
            break;
          case 'A':
            MenuAlquiler();
            fflush(stdin);
            MenuRegreso();
            break;
          case 'P':
            MenuPlanMensual(); // Incluir calendario mensual
            fflush(stdin);
//            MenuRegreso();
            break;

          case 'Z': // Menu oculto para listar alquileres en modo test
            MenuListarAlquiler();
            fflush(stdin);
            MenuRegreso();
            break;
//          case 'Q': // Menu oculto para listar calendario en modo test
//            Calendario();
//            fflush(stdin);
//            MenuRegreso();
//            break;

           case 'S':
            printf("\n");
            printf("  -- PROGRAMA FINALIZADO -- ");
            printf("\n");
            break;

          default:
            printf("\n");
            printf("  -- Introduce una opcion de menu valida -- \n");
            printf("\n");
            MenuRegreso();
        }
  } while (toupper(opcion) != 'S');



}


/*===================================================
  Metodos Menu Gestionar MAQUINAS
  =================================================*/

// TODO (alumno#3#): Cambiar nombre variable id para idmaquina

void TipoMenu::MenuEditarMaquina(){

  char confirma;

  printf("\n\n"); // saltos de linea por estilo
  printf("  ********    GesAMA Alquiler Maquinaria    ********\n\n");
  printf("  Editar Maquina:\n");
  printf("  - Identificador (numero entre 1 y 10)? ");
   scanf("%d", &id);
   // Condicion para controlar que se introduce un id valido
// FIXME (alumno#3#): Entra en bucle infinito si no se introduce un entero, por ejemplo si se tecla un nombre FIXED
    while (id < 1 || id > maxmaquinas) {
    printf("  - Inserta ID valido (numero entre 1 y 10)? ");
    scanf("%d", &id);
    fflush(stdin);
    }

  printf("  - Nombre (entre 1 y 20 caracteres)? ");
  scanf("%s", &nombre_maquina);
  fflush(stdin);

  printf("  - Tipo (G-Grano, U-Uva, A-Aceituna, B-Borrar)? ");
// NOTE (alumno#1#): Si el tipo introducido no es valido se muestra como N/D. Usuario debe editar maquina y corregir
   scanf("%c", &cultivo_maquina);
   fflush(stdin);
   cultivo_maquina = toupper(cultivo_maquina);

  printf("  - Capacidad (hectareas/dia)? ");
  scanf("%d", &capacidad_maquina);
  fflush(stdin);

  printf("  - Ubicacion inicial (Latitud)? ");
  scanf("%f", &latitud_maquina);
  fflush(stdin);

  printf("  - Ubicacion inicial (Longitud)? ");
  scanf("%f", &longitud_maquina);
  fflush(stdin);
  printf("\n");

  printf("IMPORTANTE: Esta opcion borra los datos anteriores.\n");
  printf("Son correctos los nuevos datos (S/N)? ");
  scanf("%c", &confirma);
  fflush(stdin);
  printf("\n");

// Segun la opcion escogida por el usuario se guardan los datos, se descartan o se elimina un registro

   switch (toupper(confirma)){
     case 'S':
            if (cultivo_maquina != 'B'){
                a.InsertarMaquina(id, nombre_maquina, cultivo_maquina, capacidad_maquina, latitud_maquina, longitud_maquina); // Inserta los datos leidos en el vector VectorMaquinas
            } else {
                a.Borrar(id);
            }
            break;

     case 'N':
            printf("Datos Descartados!\n");
            break;

     default:
            printf("Introduce una opcion de menu valida\n"); // Se devuelve al menu principal sin guardar
  }

}


void TipoMenu::MenuListarMaquina (){

  a.ListarMaquinas();

}


/*===================================================
  Metodos Menu Gestionar FINCAS
  =================================================*/


void TipoMenu::MenuEditarFinca(){

    char confirma;

  printf("\n\n"); // saltos de linea por estilo
  printf("  ********    GesAMA Alquiler Maquinaria    ********\n\n");
  printf("  Editar Finca:\n");
  printf("  - Identificador (numero entre 1 y 20)? ");
   scanf("%d", &idfinca);
   // Condicion para controlar que se intorduce un id valido
    while (idfinca < 1 || idfinca > maxfincas) {
    printf("  - Inserta ID valido (numero entre 1 y 20)? ");
    scanf("%d", &idfinca);
    }

  printf("  - Nombre (entre 1 y 20 caracteres)? ");
  scanf("%s", &nombre_finca);
  fflush(stdin);

  printf("  - Tipo (G-Grano, U-Uva, A-Aceituna, B-Borrar)? ");
// NOTE (alumno#1#): Si el tipo introducido no es valido se muestra como N/D. Usuario debe editar maquina y corregir
   scanf("%c", &cultivo_finca);
   fflush(stdin);
   cultivo_finca = toupper(cultivo_finca);

  printf("  - Tamano (hectareas)? ");
  scanf("%d", &capacidad_finca);
  fflush(stdin);

  printf("  - Ubicacion (Latitud)? ");
  scanf("%f", &latitud_finca);
  fflush(stdin);

  printf("  - Ubicacion (Longitud)? ");
  scanf("%f", &longitud_finca);
  fflush(stdin);
  printf("\n");

  printf("IMPORTANTE: Esta opcion borra los datos anteriores.\n");
  printf("Son correctos los nuevos datos (S/N)? ");
  scanf("%c", &confirma);
  fflush(stdin);
  printf("\n");

// Segun la opcion escogida por el usuario se guardan los datos, se descartan o se elimina un registro
  switch (toupper(confirma)){
     case 'S':
            if (cultivo_finca != 'B'){
                b.InsertarFinca(idfinca, nombre_finca, cultivo_finca, capacidad_finca, latitud_finca, longitud_finca); // Inserta los datos leidos en el vector VectorFincas
            } else {
                b.Borrar(idfinca);
            }
            break;

     case 'N':
            printf("Datos Descartados\n");
            break;

     default:
            printf("Introduce una opcion de menu valida\n"); // Se devuelve al menu principal sin guardar
  }


}


void TipoMenu::MenuListarFinca(){

    b.ListarFincas();

}



/*===================================================
  Metodos Menu ALQUILER MAQUINAS
  =================================================*/


void TipoMenu::MenuAlquiler (){


      float distancia;
//      char confirma;
      int lastfinca;
      int duracion;
//      RegTipoFecha fechafin;
//      RegTipoFecha fechaini;
      RegTipoFecha fechatraslado;
//    bool select;


      printf("\n");
      printf("  ********    GesAMA Alquiler Maquinaria    ********\n\n");
      printf("Alquiler Maquina: \n");
      printf("\n");

      select = true;
      fechaini = q.FuncPedirFecha(select);



                // Comprobamos que se introduce un id de finca valido
      printf("  - Identificador de finca (numero entre 1 y 20)? ");
      scanf("%d", &idfinca);
      fflush(stdin);

          while (idfinca != b.VectorFincas[idfinca-1].idfinca){
              printf("  - IDFINCA INVALIDO introduce finca (numero entre 1 y 20)? ");
              scanf("%d", &idfinca);
              fflush(stdin);
          }

                // Comprobamos que se introduce un id de maquina valido
      printf("  - Identificador de maquina (numero entre 1 y 10)? ");
      scanf("%d", &id);
      fflush(stdin);

// FIXME (alumno#1#): Programa crash si se introduce un valor alto de idmaquina
          while (id != a.VectorMaquinas[id-1].id){
              printf("  - IDMAQUINA INVALIDO introduce maquina (numero entre 1 y 10)? ");
              scanf("%d", &id);
              fflush(stdin);
          }

      printf("\n");

      printf("        Resumen Alquiler: \n");
      printf("\n");

      // mostrar estos datos en la salida

      printf("  - Maquina alquilada:\t %s (Id = %d) \n", a.VectorMaquinas[id-1].nombre_maquina, a.VectorMaquinas[id-1].id);
      printf("  - Finca a cosechar:\t %s (Id = %d) \n", b.VectorFincas[idfinca-1].nombre_finca, b.VectorFincas[idfinca-1].idfinca );

// NOTE (alumno#1#): Funcion para buscar en vector en que finca esta la maquina antes de traslado
// FIXME (alumno#3#): Corregir funcion busqueda ya que si se intercala un nuevo alquiler devuelve la finca del ultimo alquiler aunque sea posterior en fecha
      lastfinca = c.BuscarFinca(id);
      if ( lastfinca == 0) {
          printf("  - Traslado desde:\t Nave (Id = %d) \n", lastfinca );
      } else {
          printf("  - Traslado desde:\t finca %s (Id = %d) \n", b.VectorFincas[lastfinca-1].nombre_finca, lastfinca);
      }

// NOTE (alumno#1#): Se pasan datos de fincas para calcular la distancia de traslado de la maquina
// TODO (alumno#1#): Comprobar que realiza bien los calculos de distancia
      if ( lastfinca == 0) {
          distancia = c.CalcularDistancia (b.VectorFincas[lastfinca], b.VectorFincas[idfinca-1] );
      } else {
          distancia = c.CalcularDistancia (b.VectorFincas[lastfinca-1], b.VectorFincas[idfinca-1] );
      }
      printf("  - Distancia entre fincas:\t %0.f km en linea recta \n", distancia);

// NOTE (alumno#1#):  funcion para calcular la fecha de traslado
      fechatraslado = q.DiaTraslado(fechaini);
      printf("  - Tiempo de traslado:\t %d/%d/%d (1 dia) \n", fechatraslado );

      printf("  - Fecha comienzo:\t %d/%d/%d \n", fechaini);

// NOTE (alumno#1#): Funcion para calcular el numero de dias que la maquina esta ocupada y calcular la fecha fin
      duracion = c.CalcularCosecha( b.VectorFincas[idfinca-1].capacidad_finca, a.VectorMaquinas[id-1].capacidad_maquina);
      printf("  - Duracion cosecha:\t %d dias \n", duracion);

// NOTE (alumno#1#): Funcion que devuelve el dia de finalizacion de la cosecha
      fechafin = q.DiaFinalizacion (fechaini, duracion);
      printf("  - Fecha finalizacion:\t %d/%d/%d \n", fechafin);

      printf("\n");

// NOTE (alumno#1#): Funcion para comprobar que la maquina esta disponible en la fecha introducida
      disponible = MaquinaDisponible(fechafin, fechatraslado);
      if (disponible) {
          printf("Es correcta la operacion (S/N)? ");
          scanf("%c", &confirma);
          fflush(stdin);
          printf("\n");

          switch (toupper(confirma)){
            case 'S':
                c.InsertarAlquiler(fechaini, idfinca, id, fechafin, fechatraslado);
                break;
            case 'N':
                printf("-- Alquiler Descartado! -- \n");
                break;
            default:
              printf("Introduce una opcion valida S/N \n");
          }
      } else {
          printf("-- Alquiler Descartado! -- \n");
      }

}




void TipoMenu::MenuListarAlquiler (){

    c.ListarAlquiler ();

}



/*===================================================
  Metodos Menu CALENDARIO
  =================================================*/


void TipoMenu::MenuPlanMensual (){

    int traslados;

    select = false;

    printf("\n");
    printf(" Plan mensual Maquina: \n");

    printf(" Identificador Maquina? ");
    scanf("%d", &id);
    fflush(stdin);

// Pedimos que se introduzca la fecha
    fecha = q.FuncPedirFecha(select);
    printf("\n");

    printf("               "); // Tabular el calendario
    printf("  Plan Maquina: %s \n", a.VectorMaquinas[id-1].nombre_maquina);

    printf("\n");


// TODO (alumno#1#): IMPLEMENTAR EL CALENDARIO
      q.ProcCabeceraDatos(fecha.mes, fecha.anno);
      q.ProcSeparadorLineaH();

    printf("\n");

    Calendario();


    printf("\n");

    traslados = c.Traslados(fecha, a.VectorMaquinas[id-1].id);
    printf(" Tiempo de traslados (Tr): %d dias \n", traslados );

    printf(" Tiempo de esperas: %d dias \n", TiempoEsperas());

// Calculamos las cosechas del mes
    CosechasMes();

// Obtenemos los dias que la maquina esta ocupada en el mes
    printf(" Tiempo total de cosechas (C#): %d dias", TotalDiasCosecha());

    printf("\n");
    printf("\n");


    printf(" Mostrar otro mes (S/N)? ");
    scanf("%c", &confirma);
    fflush(stdin);
    printf("\n");

      switch (toupper(confirma)){
        case 'S':
            MenuPlanMensual();
            break;
        case 'N':
            MenuRegreso();
            break;
        default:
          printf(" Introduce una opcion valida S/N \n");
      }

}



/*===================================================
  Metodos Menu muestra las cosechas listada C# en el menu Plan mensual
  =================================================*/

// Devuelve un listado con las cosechas del mes
int TipoMenu::CosechasMes (){

    int cosecha;
    int month;
    int year;
    int idfinca;


    cosecha = 0;
    month = fecha.mes ;
    year = fecha.anno;

    for ( int i = 0; i <= c.num_alquiler; i++){

        if ( c.VectorAlquileres[i].idmaquina == id){
            if ( c.VectorAlquileres[i].fechaalquiler.mes == month && c.VectorAlquileres[i].fechaalquiler.anno == year){
              cosecha ++;
              idfinca = c.VectorAlquileres[i].idfinca;

              printf(" Cosecha C%d: finca %s \n", cosecha, b.VectorFincas[idfinca-1].nombre_finca);
            }
        }

    }

}



/*===================================================
  Metodos Menu TOTAL Dias Cosecha en el menu Plan mensual
  =================================================*/

// Devuelve el total de dias de cosecha en el mes introducido

int TipoMenu::TotalDiasCosecha () {

    int day;
    int month;
    int year;
    int diasmes;

    int diascosecha = 0;
    int duracion = 0 ;
    int ttldiascosecha = 0;

    int idfinca;
    int idmaquina;

    int capfinca;
    int capmaquina;


    month = fecha.mes ;
    year = fecha.anno;


      for ( int i = 0; i <= c.num_alquiler; i++){

          if ( c.VectorAlquileres[i].idmaquina == id){
              if ( c.VectorAlquileres[i].fechaalquiler.mes == month && c.VectorAlquileres[i].fechaalquiler.anno == year){

                  idfinca = c.VectorAlquileres[i].idfinca;
                  idmaquina = c.VectorAlquileres[i].idmaquina;
                  day = c.VectorAlquileres[i].fechaalquiler.dia;

                  capmaquina = a.VectorMaquinas[idmaquina-1].capacidad_maquina;
                  capfinca = b.VectorFincas[idfinca-1].capacidad_finca;


                  diasmes = q.FuncNumeroDias (c.VectorAlquileres[i].fechaalquiler);

                  duracion = c.CalcularCosecha ( capfinca, capmaquina);

                    if (day + duracion > diasmes){
                          diascosecha = diasmes - day +1;
                    } else {
                          diascosecha =  duracion ;
                    }

                  ttldiascosecha = ttldiascosecha + diascosecha;

              }
          }

      }

    return ttldiascosecha;

}



/*===================================================
  Metodos Menu TOTAL Dias Espera en el menu Plan mensual
  =================================================*/

// Devuelve el total de dias de espera en el mes introducido

int TipoMenu::TiempoEsperas (){

      int diasespera;
      int traslados;
      int diascosecha;
      int diasmes;

      diasmes = q.FuncNumeroDias(fecha);

      traslados = c.Traslados(fecha, a.VectorMaquinas[id-1].id);
      diascosecha = TotalDiasCosecha();

      diasespera = diasmes - traslados - diascosecha;


    return diasespera;


}



/*===================================================
  Metodos Menu MAQUINA DISPONIBLE
  =================================================*/

// Devuelve si la maquina esta disponible para la fecha introducida


bool TipoMenu::MaquinaDisponible (RegTipoFecha fechafin, RegTipoFecha fechatraslado ){


    bool posterior = true;
    bool previo = false;
    bool disponible = true;

    RegTipoFecha ftras;
    RegTipoFecha finalq;
    RegTipoFecha vftras;
    RegTipoFecha vffinalq;


    for ( int i = 0; i <= c.num_alquiler; i++){

        if ( c.VectorAlquileres[i].idmaquina == id){

          if (posterior != previo) {

            ftras = fechatraslado;
            finalq = fechafin;
            vftras = c.VectorAlquileres[i].fechatraslado;
            vffinalq = c.VectorAlquileres[i].fechafinalq;

            posterior = q.FechaPosterior (ftras, vffinalq );
            previo = q.FechaPosterior ( vftras, finalq);

            if (posterior == previo){
              disponible = false;
              printf("Maquina %s no esta disponible para la fecha y finca seleccionada \n", a.VectorMaquinas[id-1].nombre_maquina);

            }

           }

        }

    }

     return disponible;

}




/*===================================================
  Procedimiento para imprimir los dias del mes
  =================================================*/

void  TipoMenu::Calendario(){

  char marcador = '.';
  char separador = '|'; // no usada
  int indice = 0; // Var que imprime los numeros de dia en el calendario


  int tras;
  int maq;
  int monthtras;
  bool tr;
  bool cn = false;
  int coscalendar = 0;
  int mostrarc;
  int finalq;

//  bool previo = false;
//  int duracion;
//  int idfinca;
//  int idmaq;

                  // imprimir blancos segun dia de la semana que empieza el mes
                    printf("               "); // Tabular el calendario
                    for (int j = 0; j < q.FuncDiadelaSemana(fecha); j++){  // FuncDiaSemana devuelve el dia de la semana para empezar a numerar los dias

                        if (j % 7 == 4){
                          printf(" %c  ", marcador);

                        } else {
                          printf(" %c  ", marcador);
                        }

                      indice++;

                    }

                // imprimir separadores segun dia de la semana que empieza el mes
                    for (int i = 1; i <= q.FuncNumeroDias(fecha); i++){  // FuncNumeroDias devuelve el numero total de dias del mes que se le pasa a la funcion


                      if (indice % 7 == 0 && i != 1 ) {
                        printf("\n");
                        printf("               "); // Tabular el calendario
                      }

                      for (int k = 0; k < c.num_alquiler; k++){

  //                        idfinca = c.VectorAlquileres[k].idfinca;
  //                        idmaq = c.VectorAlquileres[k].idmaquina;
  //                        duracion = c.CalcularCosecha(b.VectorFincas[idfinca].capacidad_finca, a.VectorMaquinas[idmaq].capacidad_maquina);

                            tras = c.VectorAlquileres[k].fechatraslado.dia;
                            monthtras = c.VectorAlquileres[k].fechatraslado.mes;
                            maq = c.VectorAlquileres[k].idmaquina;
                            mostrarc = c.VectorAlquileres[k].fechaalquiler.dia;


          // Aqui vemos si hay traslado y corresponde con el dia del bucle y se setea la variable a true para mostrar
                          if ( tras == i && maq == a.VectorMaquinas[id-1].id && monthtras == fecha.mes ){
                              tr = true;
                          }



// INICIO IF PARA COMPROBAR EL ALQUILER A MOSTRAR EN EL CALENDARIO

                          if ( cn == false) {


//                                  if (
//                                    ( c.VectorAlquileres[k].fechaalquiler.mes == fecha.mes || c.VectorAlquileres[k].fechafinalq.mes == fecha.mes ) &&
//                                    ( c.VectorAlquileres[k].fechaalquiler.anno == fecha.anno || c.VectorAlquileres[k].fechafinalq.anno == fecha.anno) ) {
//                                      previo = true;
//                                    }




//( c.VectorAlquileres[k].fechaalquiler.mes == fecha.mes) && c.VectorAlquileres[k].fechaalquiler.anno == fecha.anno





                                  if ( ( mostrarc == i) && ( c.VectorAlquileres[k].fechaalquiler.mes == fecha.mes) && c.VectorAlquileres[k].fechaalquiler.anno == fecha.anno && maq == a.VectorMaquinas[id-1].id){

                                     if (c.VectorAlquileres[k].fechafinalq.mes > c.VectorAlquileres[k].fechaalquiler.mes ){
                                        finalq = q.FuncNumeroDias(fecha);
                                     } else {
                                        finalq = c.VectorAlquileres[k].fechafinalq.dia;
                                     }
                      // aqui se pone la variable al valor correspondiente para poner C1 o C2 o C3 etc.....
                                    coscalendar++;
                                    cn = true;
                                  }


                          }

// FIN IF PARA COMPROBAR EL ALQUILER A MOSTRAR EN EL CALENDARIO



                      }// fin for alquiler


                    if (tr == true) {
                      printf("Tr  ");
                      tr = false;

                    } else if (cn == true ){
                        printf("C%d  ", coscalendar);
                          if (i >= finalq){
                            cn = false;
                          }

                    } else {

                      printf("%2.2d  ", i);
                    }


                     indice++;

                    }


              while (indice %7 != 0){

                    if (indice % 7 == 4){
                      printf(" %c  ", marcador); // Condicional para imprimir solo un espacio antes de la barra separadora

                    } else {
                      printf(" %c  ", marcador);

                    }

                  indice++;
              }


    printf("\n\n");


}


