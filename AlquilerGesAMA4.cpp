#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "TiposGesAMA4.h"
#include "MenuGesAMA4.h"




/*===================================================
    Metodo para inicializar Vector Alquileres
  =================================================*/

void GestionAlquiler::Init(){

    num_alquiler = 0; // inicio contador alquileres. MUY importante

// Se inicia el vector con datos null
  for (int i = 0; i < maxalquileres; i++){
    VectorAlquileres[i].idalquiler = -1;
    VectorAlquileres[i].idfinca = 0;
    VectorAlquileres[i].idmaquina = 0;
    VectorAlquileres[i].fechaalquiler.day = 1;
    VectorAlquileres[i].fechaalquiler.month = 1;
    VectorAlquileres[i].fechaalquiler.year = 1900;

  }

}



/*===================================================
    Metodo para calcular distancia entre fincas
  =================================================*/


int GestionAlquiler::CalcularDistancia (TipoFinca fincaori, TipoFinca fincades){

// TODO (alumno#8#): Comprobar que hace el calculo correcto en especial al restar en negativo

    const int k = 110; // Constante de cantidad de km por grado de latitud o longitud
    const int y = 2;  // constante para elevar al cuadrado y calcular distancia
    float latori, lonori, latdes, londes, lat, lon;
    float navelat = 0.0; // Se parte de coordenadas 0 en la nave
    float navelon = 0.0;
    float distance;

    latdes = fincades.latitud_finca;
    londes = fincades.longitud_finca;

    if (fincaori.idfinca == 0){
        latori = navelat;
        lonori = navelon;
    } else {
        latori = fincaori.latitud_finca;
        lonori = fincaori.longitud_finca;
    }

    lat = latori - latdes;
    lon = lonori - londes;

    distance = pow(lat,y)+pow(lon,y);

    distance = sqrt(distance);
    distance = distance * k;

//printf("  - Distancia entre fincas: %.0f km en linea recta \n", distance);
 return distance;

}



/*===================================================
    Metodo para insertar / editar alquiler
  =================================================*/


void GestionAlquiler::InsertarAlquiler (TipoFecha fecha, int idfinca, int idmaquina){


    VectorAlquileres[num_alquiler].idalquiler = num_alquiler;
    VectorAlquileres[num_alquiler].fechaalquiler = fecha;
    VectorAlquileres[num_alquiler].idfinca = idfinca;
    VectorAlquileres[num_alquiler].idmaquina = idmaquina;
    num_alquiler++;

    printf("-- Alquiler Insertado -- \n");

}


/*===================================================
    Metodo para listar alquileres
  =================================================*/


void GestionAlquiler::ListarAlquiler (){

      printf("\n");
      printf("IdAlquiler \t Fecha \t\t MaquinaID \t FincaID \t NumAlquiler    \n");

        for (int i=0; i < maxalquileres; i++){
          if ( VectorAlquileres[i].idalquiler >= 0) {
              printf(" %-2d \t\t %d/%d/%d \t %-9d \t %-5d \t %d \n", i, VectorAlquileres[i].fechaalquiler, VectorAlquileres[i].idmaquina, VectorAlquileres[i].idfinca, num_alquiler);
          }
        }
      printf("\n");


}



/*===================================================
   Metodo para buscar la finca en donde esta la maquina
  =================================================*/

int GestionAlquiler::BuscarFinca (int id){

      int lastfinca = 0;
      bool match = false;


      for (int i = 0; i <= num_alquiler; i++){
          if (id == VectorAlquileres[i].idmaquina){
              lastfinca = VectorAlquileres[i].idfinca;
              match = true;
          }
      }

  return lastfinca;

}




/*===================================================
   Metodo para
  =================================================*/

void GestionAlquiler::TiempoTras (TipoFecha fecha){

    int dia, mes, anho;
    dia = fecha.day;
    mes = fecha.month;
    anho = fecha.year;


    if (fecha.month == 1 && fecha.day == 1){
          anho = fecha.year - 1;
          mes = 12;
    }

    if (fecha.day == 1 && (fecha.month != 12 || fecha.month != 10 || fecha.month != 7 || fecha.month != 5 || fecha.month != 3)){
          dia = 30;
          mes = fecha.month - 1;
    } else {
          dia = 31;
          mes = fecha.month - 1;

    }

//  printf(" Dia traslado calculado: %d/%d/%d \n", dia, mes, anho);

}





































