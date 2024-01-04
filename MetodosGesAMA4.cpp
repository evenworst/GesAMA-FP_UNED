#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "TiposGesAMA4.h"



/*===================================================
    Metodo para iniciar vector y contador maquinas
  =================================================*/

void GestionMaquinaria::Init (){
  num_maquinas = 0;

// Se inicia el vector con datos null
  for (int i = 0; i < maxmaquinas; i++){
    VectorMaquinas[i].id = 0;
    strcpy(VectorMaquinas[i].nombre_maquina,"");
    VectorMaquinas[i].cultivo_maquina = '.';
    VectorMaquinas[i].capacidad_maquina = 0;
    VectorMaquinas[i].latitud_maquina = 0;
    VectorMaquinas[i].longitud_maquina = 0;
  }


// Bucle para insertar demo data
//    for (int j = 0; j < maxmaquinas; j = j+2){
//
//    VectorMaquinas[j].id = j;
//    strcpy(VectorMaquinas[j].nombre_maquina,"");
//    VectorMaquinas[j].cultivo_maquina = '.';
//    VectorMaquinas[j].capacidad_maquina = 0;
//    VectorMaquinas[j].latitud_maquina = 0;
//    VectorMaquinas[j].longitud_maquina = 0;
//
//
//
//    }


    VectorMaquinas[0].id = 1;
    strcpy(VectorMaquinas[0].nombre_maquina,"Insignia");
    VectorMaquinas[0].cultivo_maquina = 'G';
    VectorMaquinas[0].capacidad_maquina = 10;
    VectorMaquinas[0].latitud_maquina = 42.3;
    VectorMaquinas[0].longitud_maquina = 21.3;

    VectorMaquinas[2].id = 3;
    strcpy(VectorMaquinas[2].nombre_maquina,"Apolo");
    VectorMaquinas[2].cultivo_maquina = 'U';
    VectorMaquinas[2].capacidad_maquina = 7;
    VectorMaquinas[2].latitud_maquina = 12.8;
    VectorMaquinas[2].longitud_maquina = -1.4;

    VectorMaquinas[6].id = 7;
    strcpy(VectorMaquinas[6].nombre_maquina,"Alondra");
    VectorMaquinas[6].cultivo_maquina = 'A';
    VectorMaquinas[6].capacidad_maquina = 5;
    VectorMaquinas[6].latitud_maquina = 32.7;
    VectorMaquinas[6].longitud_maquina = -6.3;


}


/*===================================================
    Metodo para iniciar vector y contador fincas
  =================================================*/

void GestionFincas::Init (){
  num_fincas = 0;

// Se inicia el vector con datos null
  for (int i = 0; i < maxfincas; i++){
    VectorFincas[i].idfinca = 0;
    strcpy(VectorFincas[i].nombre_finca,"");
    VectorFincas[i].cultivo_finca = '.';
    VectorFincas[i].capacidad_finca = 0;
    VectorFincas[i].latitud_finca = 0;
    VectorFincas[i].longitud_finca = 0;
  }


// DATA DEMO
    VectorFincas[1].idfinca = 2;
    strcpy(VectorFincas[1].nombre_finca,"Bercial");
    VectorFincas[1].cultivo_finca = 'G';
    VectorFincas[1].capacidad_finca = 94;
    VectorFincas[1].latitud_finca = 38.231;
    VectorFincas[1].longitud_finca = -2.567;

    VectorFincas[4].idfinca = 5;
    strcpy(VectorFincas[4].nombre_finca,"Espartal");
    VectorFincas[4].cultivo_finca = 'G';
    VectorFincas[4].capacidad_finca = 75;
    VectorFincas[4].latitud_finca = 42.454;
    VectorFincas[4].longitud_finca = -4.059;

    VectorFincas[10].idfinca = 11;
    strcpy(VectorFincas[10].nombre_finca,"Gamonal");
    VectorFincas[10].cultivo_finca = 'U';
    VectorFincas[10].capacidad_finca = 58;
    VectorFincas[10].latitud_finca = 40.221;
    VectorFincas[10].longitud_finca = -3.234;

    VectorFincas[14].idfinca = 15;
    strcpy(VectorFincas[14].nombre_finca,"Zorzal");
    VectorFincas[14].cultivo_finca = 'A';
    VectorFincas[14].capacidad_finca = 106;
    VectorFincas[14].latitud_finca = 39.111;
    VectorFincas[14].longitud_finca = 0.675;

    VectorFincas[18].idfinca = 19;
    strcpy(VectorFincas[18].nombre_finca,"Sotillo");
    VectorFincas[18].cultivo_finca = 'G';
    VectorFincas[18].capacidad_finca = 132;
    VectorFincas[18].latitud_finca = 41.003;
    VectorFincas[18].longitud_finca = -1.345;
// FIN DATA DEMO


}



/*===================================================
    Metodo para borrar maquinas
  =================================================*/

void GestionMaquinaria::Borrar (int id){

// FIXME (alumno#5#): Comprobar que id maquina existe antes de borrar para evitar la variable num_maquinas en negativo al eliminar un id vacio
    if (num_maquinas > 0){

        VectorMaquinas[id-1].id = 0;
        strcpy(VectorMaquinas[id-1].nombre_maquina,"");
        VectorMaquinas[id-1].cultivo_maquina = '.';
        VectorMaquinas[id-1].capacidad_maquina = 0;
        VectorMaquinas[id-1].latitud_maquina = 0;
        VectorMaquinas[id-1].longitud_maquina = 0;

        num_maquinas--;

        printf(" -- Maquina %d eliminada! -- Remaining machines = %d\n", id, num_maquinas);  // Eliminar variable num_maquinas para no mostrar en version final
        printf("\n");

    } else {
      printf("  -- No hay maquinas para eliminar -- \n");
      printf("\n");
    }
}


/*===================================================
    Metodo para insertar / editar maquina
  =================================================*/

void GestionMaquinaria::InsertarMaquina(int id, TipoCadenaTexto nombre_maquina, char cultivo_maquina, int capacidad_maquina, float latitud_maquina, float longitud_maquina){

// TODO (alumno#1#): Comprobar si maquina id ya existe y no aumentar contador. Hacer IF en modo inverso e incluir comprobacion TipoCultivo IF
    bool edit = false;


    for (int i = 0; i < maxmaquinas; i++){
        if (VectorMaquinas[i].id == id) {
          edit = true;
        }
    }


      // Modo Edit
      if (edit) {

            VectorMaquinas[id-1].id = id;
            strcpy(VectorMaquinas[id-1].nombre_maquina, nombre_maquina);
            VectorMaquinas[id-1].cultivo_maquina = toupper(cultivo_maquina);
            VectorMaquinas[id-1].capacidad_maquina = capacidad_maquina;
            VectorMaquinas[id-1].latitud_maquina = latitud_maquina;
            VectorMaquinas[id-1].longitud_maquina = longitud_maquina;

            printf(" -- Maquina Editada -- \n\n");
            printf("Id \t\t      Nombre \t Tipo \t  Capacidad \t Latitud \t Longitud \t Contador \n"); // ELIMINAR CONTADOR
            printf("%2d \t %19s \t %4c \t  %9d \t %7.3f \t  %7.3f \t %d   \n\n", VectorMaquinas[id-1].id, VectorMaquinas[id-1].nombre_maquina, VectorMaquinas[id-1].cultivo_maquina, VectorMaquinas[id-1].capacidad_maquina,
                                                                                  VectorMaquinas[id-1].latitud_maquina, VectorMaquinas[id-1].longitud_maquina, num_maquinas);

      // Modo Insert
      } else if (num_maquinas < maxmaquinas){
            num_maquinas++;
//            printf("Vector vacio\n");  // ELIMINAR LINEA
            printf("  -- Maquina Guardada -- \n");

            VectorMaquinas[id-1].id = id;
            strcpy(VectorMaquinas[id-1].nombre_maquina, nombre_maquina);
            VectorMaquinas[id-1].cultivo_maquina = toupper(cultivo_maquina);
            VectorMaquinas[id-1].capacidad_maquina = capacidad_maquina;
            VectorMaquinas[id-1].latitud_maquina = latitud_maquina;
            VectorMaquinas[id-1].longitud_maquina = longitud_maquina;

            printf("Id \t\t      Nombre \t Tipo \t  Capacidad \t Latitud \t Longitud \t Contador \n");
            printf("%2d \t %19s \t %4c \t  %9d \t %7.3f \t  %7.3f \t %d   \n\n", VectorMaquinas[id-1].id, VectorMaquinas[id-1].nombre_maquina, VectorMaquinas[id-1].cultivo_maquina, VectorMaquinas[id-1].capacidad_maquina,
                                                                                  VectorMaquinas[id-1].latitud_maquina, VectorMaquinas[id-1].longitud_maquina, num_maquinas);


    } else {
      printf("No se pueden almacenar mas maquinas. Edite una maquina o elimine antes de introducir una nueva\n");
      printf("Datos Descartados \n\n");
    }

}


/*===================================================
        Metodo para listar maquina
  =================================================*/

void GestionMaquinaria::ListarMaquinas (){

    TipoCadenaTexto t; // variable para almacenar el tipo cultivo en texto
    char filtromaq; // variable para filtrar las maquinas segun tipo
//    int str;

    printf("\n");
    printf("Tipo de maquinas a listar (G-Grano, U-Uva, A-Aceituna, T-Todas)?");
    scanf("%c", &filtromaq);
    fflush(stdin);
    filtromaq = toupper(filtromaq);

// TODO (alumno#5#): Poner condicion para solo aceptar los caracteres validos

//      str strcmp = (&filtromaq,
//        while (filtromaq != 'G' || filtromaq != 'A' || filtromaq != 'U' || filtromaq != 'T'){
//            printf("Inserta un filtro valido (G-Grano, U-Uva, A-Aceituna, T-Todas)?");
//            scanf("%c", &filtromaq);
//            fflush(stdin);
//        }

//    printf("Funcion listar maquinas AQUI var num_maquinas = %d\n", num_maquinas);  // ELIMINAR
    printf("\n");

// TODO (alumno#1#): Tabular listado con funcion rellenando espacios en blanco

    printf("Id \t\t      Nombre \t       Tipo \t\t  Capacidad \n");

    for (int i=0; i < maxmaquinas; i++){

// TODO (alumno#1#): Pendiente de convertir a funcion para reutilizar.

/* Se traduce el tipo de cultivo a la palabra completa para listar */
      switch (VectorMaquinas[i].cultivo_maquina){
        case 'G':
              strcpy(t,"Grano");
              break;
        case 'U':
              strcpy(t,"Uva");
              break;
        case 'A':
              strcpy(t,"Aceituna");
              break;
        default:
              strcpy(t,"N/D");
      }

/* Condicion para filtrar el listado por el tipo seleccionado */

      switch (filtromaq){
        case 'G':
              if (VectorMaquinas[i].id != 0 && VectorMaquinas[i].cultivo_maquina == 'G') {
                printf ("%2d \t %19s \t %10s \t %4d hectareas/dia  \n", VectorMaquinas[i].id, VectorMaquinas[i].nombre_maquina, t, VectorMaquinas[i].capacidad_maquina);
              }
              break;
        case 'U':
              if (VectorMaquinas[i].id != 0 && VectorMaquinas[i].cultivo_maquina == 'U'){
                printf ("%2d \t %19s \t %10s \t %4d hectareas/dia  \n", VectorMaquinas[i].id, VectorMaquinas[i].nombre_maquina, t, VectorMaquinas[i].capacidad_maquina);
              }
              break;
        case 'A':
              if (VectorMaquinas[i].id != 0 && VectorMaquinas[i].cultivo_maquina == 'A'){
                printf ("%2d \t %19s \t %10s \t %4d hectareas/dia  \n", VectorMaquinas[i].id, VectorMaquinas[i].nombre_maquina, t, VectorMaquinas[i].capacidad_maquina);
              }
              break;
        case 'T':
              if (VectorMaquinas[i].id != 0){
                printf ("%2d \t %19s \t %10s \t %4d hectareas/dia  \n", VectorMaquinas[i].id, VectorMaquinas[i].nombre_maquina, t, VectorMaquinas[i].capacidad_maquina);
              }
              break;
        default:
// TODO (alumno#1#): Verificar funcionamiento case default
              printf("Tipo de maquinas a listar(G-Grano, U-Uva, A-Aceituna, T-Todas)?");
              scanf("%c", &filtromaq);
              fflush(stdin);
              filtromaq = toupper(filtromaq);

      }

    }

  printf("\n");

}



/*===================================================
    Metodo para borrar fincas
  =================================================*/

void GestionFincas::Borrar (int idfinca){

// FIXME (alumno#5#): Comprobar que id finca existe antes de borrar para evitar la variable num_maquinas en negativo al eliminar un id vacio
    if (num_fincas > 0){

        VectorFincas[idfinca-1].idfinca = 0;
        strcpy(VectorFincas[idfinca-1].nombre_finca,"");
        VectorFincas[idfinca-1].cultivo_finca = '.';
        VectorFincas[idfinca-1].capacidad_finca = 0;
        VectorFincas[idfinca-1].latitud_finca = 0;
        VectorFincas[idfinca-1].longitud_finca = 0;

        num_fincas--;

        printf(" -- Finca %d eliminada! -- %d\n", idfinca, num_fincas);  // Eliminar variable num_Fincas para no mostrar en version final
        printf("\n");

    } else {
      printf("  -- No hay fincas para eliminar -- \n");
      printf("\n");
    }
}



/*===================================================
    Metodo para insertar / editar finca
  =================================================*/

void GestionFincas::InsertarFinca (int idfinca, TipoCadenaTexto nombre_finca, char cultivo_finca, int capacidad_finca, float latitud_finca, float longitud_finca){

// TODO (alumno#1#): Comprobar si maquina id ya existe y no aumentar contador. Hacer IF en modo inverso e incluir comprobacion TipoCultivo IF
    bool edit = false;


    for (int i = 0; i < maxfincas; i++){
        if (VectorFincas[i].idfinca == idfinca) {
          edit = true;
        }
    }


      // Modo Edit
      if (edit) {

            VectorFincas[idfinca-1].idfinca = idfinca;
            strcpy(VectorFincas[idfinca-1].nombre_finca, nombre_finca);
            VectorFincas[idfinca-1].cultivo_finca = toupper(cultivo_finca);
            VectorFincas[idfinca-1].capacidad_finca = capacidad_finca;
            VectorFincas[idfinca-1].latitud_finca = latitud_finca;
            VectorFincas[idfinca-1].longitud_finca = longitud_finca;

            printf(" -- Finca Editada -- \n\n");
            printf("Id \t\t      Nombre \t Tipo \t  Capacidad \t Latitud \t Longitud \t Contador \n"); // ELIMINAR CONTADOR
            printf("%2d \t %19s \t %4c \t  %9d \t %7.3f \t  %7.3f \t %d   \n\n", VectorFincas[idfinca-1].idfinca, VectorFincas[idfinca-1].nombre_finca, VectorFincas[idfinca-1].cultivo_finca, VectorFincas[idfinca-1].capacidad_finca,
                                                                                  VectorFincas[idfinca-1].latitud_finca, VectorFincas[idfinca-1].longitud_finca, num_fincas);

      // Modo Insert
      } else if (num_fincas < maxfincas){
            num_fincas++;
//            printf("Vector vacio\n");  // ELIMINAR LINEA
            printf("  -- Finca Guardada -- \n");

            VectorFincas[idfinca-1].idfinca = idfinca;
            strcpy(VectorFincas[idfinca-1].nombre_finca, nombre_finca);
            VectorFincas[idfinca-1].cultivo_finca = toupper(cultivo_finca);
            VectorFincas[idfinca-1].capacidad_finca = capacidad_finca;
            VectorFincas[idfinca-1].latitud_finca = latitud_finca;
            VectorFincas[idfinca-1].longitud_finca = longitud_finca;

            printf("Id \t\t      Nombre \t Tipo \t  Capacidad \t Latitud \t Longitud \t Contador \n");
            printf("%2d \t %19s \t %4c \t  %9d \t %7.3f \t  %7.3f \t %d   \n\n", VectorFincas[idfinca-1].idfinca, VectorFincas[idfinca-1].nombre_finca, VectorFincas[idfinca-1].cultivo_finca, VectorFincas[idfinca-1].capacidad_finca,
                                                                                  VectorFincas[idfinca-1].latitud_finca, VectorFincas[idfinca-1].longitud_finca, num_fincas);


    } else {
      printf("No se pueden almacenar mas Fincas. Edite una finca o elimine antes de introducir una nueva\n");
      printf("Datos Descartados! \n\n");
    }

}



/*===================================================
        Metodo para listar fincas
  =================================================*/

void GestionFincas::ListarFincas (){

    TipoCadenaTexto t; // variable para almacenar el tipo cultivo en texto
    char filtrofinc; // variable para filtrar las fincas segun tipo
//    int str;

    printf("\n");
    printf("Estado de fincas a listar (G-Grano, U-Uva, A-Aceituna, T-Todas)?");
    scanf("%c", &filtrofinc);
    fflush(stdin);
    filtrofinc = toupper(filtrofinc);

// TODO (alumno#5#): Poner condicion para solo aceptar los caracteres validos

//      str strcmp = (&filtromaq,
//        while (filtromaq != 'G' || filtromaq != 'A' || filtromaq != 'U' || filtromaq != 'T'){
//            printf("Inserta un filtro valido (G-Grano, U-Uva, A-Aceituna, T-Todas)?");
//            scanf("%c", &filtromaq);
//            fflush(stdin);
//        }

//    printf("Funcion listar maquinas AQUI var num_maquinas = %d\n", num_maquinas);  // ELIMINAR

    printf("\n");

// TODO (alumno#1#): Tabular listado con funcion rellenando espacios en blanco

    printf("Id \t\t      Nombre \t       Tipo \t\t  Tamano \t   Latitud \t    Longitud \t \n");

    for (int i=0; i<maxfincas; i++){

// TODO (alumno#1#): Pendiente de convertir a funcion para reutilizar.

/* Se traduce el tipo de cultivo a la palabra completa para listar */
      switch (VectorFincas[i].cultivo_finca){
        case 'G':
              strcpy(t,"Grano");
              break;
        case 'U':
              strcpy(t,"Uva");
              break;
        case 'A':
              strcpy(t,"Aceituna");
              break;
        default:
              strcpy(t,"N/D");
      }

/* Condicion para filtrar el listado por el tipo seleccionado */

      switch (filtrofinc){
        case 'G':
              if (VectorFincas[i].idfinca != 0 && VectorFincas[i].cultivo_finca == 'G') {
                printf ("%2d \t %19s \t %10s \t %4d hectareas \t  %5.3f \t  %5.3f  \n", VectorFincas[i].idfinca, VectorFincas[i].nombre_finca, t, VectorFincas[i].capacidad_finca, VectorFincas[i].latitud_finca, VectorFincas[i].longitud_finca);
              }
              break;
        case 'U':
              if (VectorFincas[i].idfinca != 0 && VectorFincas[i].cultivo_finca == 'U'){
                printf ("%2d \t %19s \t %10s \t %4d hectareas \t  %5.3f \t  %5.3f  \n", VectorFincas[i].idfinca, VectorFincas[i].nombre_finca, t, VectorFincas[i].capacidad_finca, VectorFincas[i].latitud_finca, VectorFincas[i].longitud_finca);
              }
              break;
        case 'A':
              if (VectorFincas[i].idfinca != 0 && VectorFincas[i].cultivo_finca == 'A'){
                printf ("%2d \t %19s \t %10s \t %4d hectareas \t  %5.3f \t  %5.3f  \n", VectorFincas[i].idfinca, VectorFincas[i].nombre_finca, t, VectorFincas[i].capacidad_finca, VectorFincas[i].latitud_finca, VectorFincas[i].longitud_finca);
              }
              break;
        case 'T':
              if (VectorFincas[i].idfinca != 0){
                printf ("%2d \t %19s \t %10s \t %4d hectareas \t  %5.3f \t  %5.3f  \n", VectorFincas[i].idfinca, VectorFincas[i].nombre_finca, t, VectorFincas[i].capacidad_finca, VectorFincas[i].latitud_finca, VectorFincas[i].longitud_finca);
              }
              break;
        default:
// TODO (alumno#1#): Verificar funcionamiento case default
              printf("Tipo de maquinas a listar(G-Grano, U-Uva, A-Aceituna, T-Todas)?");
              scanf("%c", &filtrofinc);
              fflush(stdin);
              filtrofinc = toupper(filtrofinc);

      }

    }

  printf("\n");

}




