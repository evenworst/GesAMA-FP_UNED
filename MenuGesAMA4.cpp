#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "MenuGesAMA4.h"





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
  a.Init(); // inicializo contador vector maquinas
  b.Init(); // incializo contador vector fincas
  c.Init(); // incializo contador vector fincas

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
            MenuRegreso();
            break;
          case 'Z': // Menu oculto para listar alquileres en modo test
            MenuListarAlquiler();
            fflush(stdin);
            MenuRegreso();
            break;
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
  printf("  - Identificador (numero entre 1 y 10)?");
   scanf("%d", &id);
   // Condicion para controlar que se introduce un id valido
// FIXME (alumno#3#): Entra en bucle infinito si no se introduce un entero, por ejemplo si se tecla un nombre
    while (id < 1 || id > maxmaquinas) {
    printf("  - Inserta ID valido (numero entre 1 y 10)?");
    scanf("%d", &id);
    fflush(stdin);
    }
  printf("\n");

  printf("  - Nombre (entre 1 y 20 caracteres)?");
  scanf("%s", &nombre_maquina);
  fflush(stdin);
  printf("\n");

  printf("  - Tipo (G-Grano, U-Uva, A-Aceituna, B-Borrar)?");
// TODO (alumno#1#): Si el tipo introducido no es valido se muestra como N/D. Usuario debe editar maquina y corregir
   scanf("%c", &cultivo_maquina);
   fflush(stdin);
   cultivo_maquina = toupper(cultivo_maquina);
  printf("\n");

  printf("  - Capacidad (hectareas/dia)?");
  scanf("%d", &capacidad_maquina);
  fflush(stdin);
  printf("\n");

  printf("  - Ubicacion inicial (Latitud)?");
  scanf("%f", &latitud_maquina);
  fflush(stdin);
  printf("\n");

  printf("  - Ubicacion inicial (Longitud)?");
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
//                printf(" *** SE GUARDA LA MAQUINA DEL VECTOR *** \n");  // ELIMINAR LINEA
                a.InsertarMaquina(id, nombre_maquina, cultivo_maquina, capacidad_maquina, latitud_maquina, longitud_maquina); // Inserta los datos leidos en el vector VectorMaquinas
            } else {
//                printf(" *** SE BORRAR LA MAQUINA DEL VECTOR ***\n"); // ELIMINAR LINEA
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

//  printf("Aqui el menu print \n"); // ELIMINAR LINEA
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
  printf("  - Identificador (numero entre 1 y 20)?");
   scanf("%d", &idfinca);
   // Condicion para controlar que se intorduce un id valido
    while (idfinca < 1 || idfinca > maxfincas) {
    printf("  - Inserta ID valido (numero entre 1 y 20)?");
    scanf("%d", &idfinca);
    }
  printf("\n");

  printf("  - Nombre (entre 1 y 20 caracteres)?");
  scanf("%s", &nombre_finca);
  fflush(stdin);
  printf("\n");

  printf("  - Tipo (G-Grano, U-Uva, A-Aceituna, B-Borrar)?");
// TODO (alumno#1#): Si el tipo introducido no es valido se muestra como N/D. Usuario debe editar maquina y corregir
   scanf("%c", &cultivo_finca);
   fflush(stdin);
   cultivo_finca = toupper(cultivo_finca);
  printf("\n");

  printf("  - Tamano (hectareas)?");
  scanf("%d", &capacidad_finca);
  fflush(stdin);
  printf("\n");

  printf("  - Ubicacion (Latitud)?");
  scanf("%f", &latitud_finca);
  fflush(stdin);
  printf("\n");

  printf("  - Ubicacion (Longitud)?");
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
//                printf(" *** SE GUARDA LA MAQUINA DEL VECTOR *** \n");  // ELIMINAR LINEA
                b.InsertarFinca(idfinca, nombre_finca, cultivo_finca, capacidad_finca, latitud_finca, longitud_finca); // Inserta los datos leidos en el vector VectorFincas
            } else {
//                printf(" *** SE BORRAR LA MAQUINA DEL VECTOR ***\n"); // ELIMINAR LINEA
                b.Borrar(idfinca);
            }
            break;

     case 'N':
            printf("Datos Descartados\n");
            break;

     default:
            printf("Introduce una opcion de menu valida\n"); // Se devuelve al menu principal sin guardar
  }



  printf(" Aqui implementar el menu para editar y borrar fincas \n");


}


void TipoMenu::MenuListarFinca(){

    b.ListarFincas();

}



/*===================================================
  Metodos Menu ALQUILER MAQUINAS
  =================================================*/


void TipoMenu::MenuAlquiler (){


      float distancia;
      char confirma;
      int lastfinca;



      printf("\n");
      printf("  ********    GesAMA Alquiler Maquinaria    ********\n\n");
      printf("Alquiler Maquina: \n");
      printf("\n");

      // Solcitar estos datos de entrada
      printf("  - Fecha comienzo cosecha: Dia? ");
      scanf("%d", &fechaini.day);
      fflush(stdin);

      printf("  - Fecha comienzo cosecha: Mes? ");
      scanf("%d", &fechaini.month);
      fflush(stdin);

      printf("  - Fecha comienzo cosecha: Ano? ");
      scanf("%d", &fechaini.year);
      fflush(stdin);

      printf("  - Identificador de finca (numero entre 1 y 20)? ");
      scanf("%d", &idfinca);
      fflush(stdin);

      printf("  - Identificador de maquina (numero entre 1 y 10)? ");
      scanf("%d", &id);
      fflush(stdin);

      printf("\n");

      printf("        Resumen Alquiler: \n");
      printf("\n");

      // mostrar estos datos en la salida

      printf("  - Maquina alquilada:\t %s (Id = %d) \n", a.VectorMaquinas[id-1].nombre_maquina, a.VectorMaquinas[id-1].id);
      printf("  - Finca a cosechar:\t %s (Id = %d) \n", b.VectorFincas[idfinca-1].nombre_finca, b.VectorFincas[idfinca-1].idfinca );

// Funcion para buscar en vector en que finca esta la maquina antes de traslado
      lastfinca = c.BuscarFinca(id);
      if ( lastfinca == 0) {
          printf("  - Traslado desde:\t Nave (Id = %d) \n", lastfinca );
      } else {
          printf("  - Traslado desde:\t finca %s (Id = %d) \n", b.VectorFincas[lastfinca-1].nombre_finca, lastfinca);
      }

// NOTE (alumno#1#): Se pasan datos de fincas para calcular la distancia de traslado de la maquina
      if ( lastfinca == 0) {
          distancia = c.CalcularDistancia (b.VectorFincas[lastfinca], b.VectorFincas[idfinca-1] );
      } else {
          distancia = c.CalcularDistancia (b.VectorFincas[lastfinca-1], b.VectorFincas[idfinca-1] );
      }
      printf("  - Distancia entre fincas:\t %0.f km en linea recta \n", distancia);

// TODO (alumno#1#): Hacer funcion para calcular la fecha de traslado
      c.TiempoTras(fechaini);
      printf("  - Tiempo de traslado:\t dd/mm/yyyy (1 dia) \n");

      printf("  - Fecha comienzo:\t %d/%d/%d \n", fechaini);

// TODO (alumno#1#): Funcion para caluclar el numero de dias que la maquina esta ocupada y calcular la fecha fin
      printf("  - Duracion cosecha:\t 11 dias \n");
      printf("  - Fecha finalizacion:\t 19/7/2024 \n");

      printf("\n");

      printf("Es correcta la operacion (S/N)? ");
      scanf("%c", &confirma);
      fflush(stdin);
      printf("\n");

      switch (toupper(confirma)){
        case 'S':
            c.InsertarAlquiler(fechaini, idfinca, id);
            break;
        case 'N':
            printf("-- Alquiler Descartado! -- \n");
            break;
        default:
          printf("Introduce una opcion valida S/N \n");
      }


}




void TipoMenu::MenuListarAlquiler (){

    c.ListarAlquiler ();

}



/*===================================================
  Metodos Menu CALENDARIO
  =================================================*/


void TipoMenu::MenuPlanMensual (){

    printf("Plan mensual Maquina: \n");

    printf("Identificador Maquina? ");
    scanf("%d", &id);
    fflush(stdin);

    printf("Seleccion Mes? ");
    scanf("%d", &fechaini.month);
    fflush(stdin);

    printf("Seleccion Anho? ");
    scanf("%d", &fechaini.year);
    fflush(stdin);


    printf("\n Aqui el calendario \n");

    printf("\n");

    printf("Tiempo de traslados (Tr): XX dias \n");
    printf("Tiempo de esperas: XX dias \n");
    printf("Cosecha C1: finca nomfinca1 \n");
    printf("Cosecha C2: finca nomfinca2 \n");
    printf("Cosecha C3: finca nomfinca3 \n");
    printf("Tiempo total de cosechas (C#): XX dias");
    printf("\n");
    printf(" Mostrar otro mes (S/N)?\n");



}







