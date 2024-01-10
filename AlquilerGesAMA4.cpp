#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "TiposGesAMA4.h"
#include "MenuGesAMA4.h"
#include "CalendarioGesAMA.h"





/*===================================================
    Metodo para inicializar Vector Alquileres
  =================================================*/

void GestionAlquiler::Init(){

    num_alquiler = 10; // inicio contador alquileres. MUY importante  OJO!!!!! RESETEAR AL QUITAR DEMO DATA

// Se inicia el vector con datos null
  for (int i = 0; i < maxalquileres; i++){
    VectorAlquileres[i].idalquiler = 0;
    VectorAlquileres[i].idfinca = 0;
    VectorAlquileres[i].idmaquina = 0;
    VectorAlquileres[i].fechaalquiler.dia = 1;
    VectorAlquileres[i].fechaalquiler.mes = Enero;
    VectorAlquileres[i].fechaalquiler.anno = 1900;
        VectorAlquileres[i].fechafinalq.dia = 1;
    VectorAlquileres[i].fechafinalq.mes = Enero;
    VectorAlquileres[i].fechafinalq.anno = 1900;
    VectorAlquileres[i].fechatraslado.dia = 1;
    VectorAlquileres[i].fechatraslado.mes = Enero;
    VectorAlquileres[i].fechatraslado.anno = 1900;

  }


// DEMO DATA START
    VectorAlquileres[0].idalquiler = 1;
    VectorAlquileres[0].idfinca = 5;
    VectorAlquileres[0].idmaquina = 1;
    VectorAlquileres[0].fechaalquiler.dia = 1;
    VectorAlquileres[0].fechaalquiler.mes = 8;
    VectorAlquileres[0].fechaalquiler.anno = 2024;
        VectorAlquileres[0].fechafinalq.dia = 10;
    VectorAlquileres[0].fechafinalq.mes = 8;
    VectorAlquileres[0].fechafinalq.anno = 2024;
    VectorAlquileres[0].fechatraslado.dia = 31;
    VectorAlquileres[0].fechatraslado.mes = 7;
    VectorAlquileres[0].fechatraslado.anno = 2024;

    VectorAlquileres[1].idalquiler = 2;
    VectorAlquileres[1].idfinca = 15;
    VectorAlquileres[1].idmaquina = 3;
    VectorAlquileres[1].fechaalquiler.dia = 6;
    VectorAlquileres[1].fechaalquiler.mes = 8;
    VectorAlquileres[1].fechaalquiler.anno = 2024;
        VectorAlquileres[1].fechafinalq.dia = 25;
    VectorAlquileres[1].fechafinalq.mes = 8;
    VectorAlquileres[1].fechafinalq.anno = 2024;
    VectorAlquileres[1].fechatraslado.dia = 5;
    VectorAlquileres[1].fechatraslado.mes = 8;
    VectorAlquileres[1].fechatraslado.anno = 2024;

    VectorAlquileres[2].idalquiler = 3;
    VectorAlquileres[2].idfinca = 15;
    VectorAlquileres[2].idmaquina = 7;
    VectorAlquileres[2].fechaalquiler.dia = 8;
    VectorAlquileres[2].fechaalquiler.mes = 8;
    VectorAlquileres[2].fechaalquiler.anno = 2024;
        VectorAlquileres[2].fechafinalq.dia = 15;
    VectorAlquileres[2].fechafinalq.mes = 8;
    VectorAlquileres[2].fechafinalq.anno = 2024;
    VectorAlquileres[2].fechatraslado.dia = 7;
    VectorAlquileres[2].fechatraslado.mes = 8;
    VectorAlquileres[2].fechatraslado.anno = 2024;

    VectorAlquileres[3].idalquiler = 4;
    VectorAlquileres[3].idfinca = 19;
    VectorAlquileres[3].idmaquina = 1;
    VectorAlquileres[3].fechaalquiler.dia = 15;
    VectorAlquileres[3].fechaalquiler.mes = 11;
    VectorAlquileres[3].fechaalquiler.anno = 2024;
        VectorAlquileres[3].fechafinalq.dia = 23;
    VectorAlquileres[3].fechafinalq.mes = 11;
    VectorAlquileres[3].fechafinalq.anno = 2024;
    VectorAlquileres[3].fechatraslado.dia = 14;
    VectorAlquileres[3].fechatraslado.mes = 11;
    VectorAlquileres[3].fechatraslado.anno = 2024;

    VectorAlquileres[4].idalquiler = 5;
    VectorAlquileres[4].idfinca = 19;
    VectorAlquileres[4].idmaquina = 3;
    VectorAlquileres[4].fechaalquiler.dia = 5;
    VectorAlquileres[4].fechaalquiler.mes = 11;
    VectorAlquileres[4].fechaalquiler.anno = 2024;
        VectorAlquileres[4].fechafinalq.dia = 13;
    VectorAlquileres[4].fechafinalq.mes = 11;
    VectorAlquileres[4].fechafinalq.anno = 2024;
    VectorAlquileres[4].fechatraslado.dia = 4;
    VectorAlquileres[4].fechatraslado.mes = 11;
    VectorAlquileres[4].fechatraslado.anno = 2024;

    VectorAlquileres[5].idalquiler = 6;
    VectorAlquileres[5].idfinca = 5;
    VectorAlquileres[5].idmaquina = 7;
    VectorAlquileres[5].fechaalquiler.dia = 10;
    VectorAlquileres[5].fechaalquiler.mes = 9;
    VectorAlquileres[5].fechaalquiler.anno = 2024;
        VectorAlquileres[5].fechafinalq.dia = 22;
    VectorAlquileres[5].fechafinalq.mes = 9;
    VectorAlquileres[5].fechafinalq.anno = 2024;
    VectorAlquileres[5].fechatraslado.dia = 9;
    VectorAlquileres[5].fechatraslado.mes = 9;
    VectorAlquileres[5].fechatraslado.anno = 2024;



    VectorAlquileres[6].idalquiler = 7;
    VectorAlquileres[6].idfinca = 2;
    VectorAlquileres[6].idmaquina = 7;
    VectorAlquileres[6].fechaalquiler.dia = 28;
    VectorAlquileres[6].fechaalquiler.mes = 9;
    VectorAlquileres[6].fechaalquiler.anno = 2024;
        VectorAlquileres[6].fechafinalq.dia = 2;
    VectorAlquileres[6].fechafinalq.mes = 10;
    VectorAlquileres[6].fechafinalq.anno = 2024;
    VectorAlquileres[6].fechatraslado.dia = 27;
    VectorAlquileres[6].fechatraslado.mes = 9;
    VectorAlquileres[6].fechatraslado.anno = 2024;

    VectorAlquileres[7].idalquiler = 8;
    VectorAlquileres[7].idfinca = 2;
    VectorAlquileres[7].idmaquina = 1;
    VectorAlquileres[7].fechaalquiler.dia = 11;
    VectorAlquileres[7].fechaalquiler.mes = 6;
    VectorAlquileres[7].fechaalquiler.anno = 2024;
        VectorAlquileres[7].fechafinalq.dia = 15;
    VectorAlquileres[7].fechafinalq.mes = 6;
    VectorAlquileres[7].fechafinalq.anno = 2024;
    VectorAlquileres[7].fechatraslado.dia = 10;
    VectorAlquileres[7].fechatraslado.mes = 6;
    VectorAlquileres[7].fechatraslado.anno = 2024;

    VectorAlquileres[8].idalquiler = 9;
    VectorAlquileres[8].idfinca = 2;
    VectorAlquileres[8].idmaquina = 1;
    VectorAlquileres[8].fechaalquiler.dia = 22;
    VectorAlquileres[8].fechaalquiler.mes = 5;
    VectorAlquileres[8].fechaalquiler.anno = 2024;
        VectorAlquileres[8].fechafinalq.dia = 26;
    VectorAlquileres[8].fechafinalq.mes = 5;
    VectorAlquileres[8].fechafinalq.anno = 2024;
    VectorAlquileres[8].fechatraslado.dia = 21;
    VectorAlquileres[8].fechatraslado.mes = 5;
    VectorAlquileres[8].fechatraslado.anno = 2024;

    VectorAlquileres[9].idalquiler = 10;
    VectorAlquileres[9].idfinca = 2;
    VectorAlquileres[9].idmaquina = 1;
    VectorAlquileres[9].fechaalquiler.dia = 2;
    VectorAlquileres[9].fechaalquiler.mes = 5;
    VectorAlquileres[9].fechaalquiler.anno = 2024;
        VectorAlquileres[9].fechafinalq.dia = 6;
    VectorAlquileres[9].fechafinalq.mes = 5;
    VectorAlquileres[9].fechafinalq.anno = 2024;
    VectorAlquileres[9].fechatraslado.dia = 1;
    VectorAlquileres[9].fechatraslado.mes = 5;
    VectorAlquileres[9].fechatraslado.anno = 2024;



// DEMO DATA END



}



/*===================================================
    Metodo para calcular distancia entre fincas
  =================================================*/


int GestionAlquiler::CalcularDistancia (TipoFinca fincaori, TipoFinca fincades){

// TODO (alumno#8#): Comprobar que hace el calculo correcto en especial al restar en negativo

    const int k = 110; // Constante de cantidad de km por grado de latitud o longitud
    const int y = 2;  // constante para elevar al cuadrado y calcular distancia
    float latori, lonori, latdes, londes, lat, lon;
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

 return distance;

}


/*===================================================
    Metodo para calcular duracion cosechas
  =================================================*/

int GestionAlquiler::CalcularCosecha (int capacidad_finca, int capacidad_maquina){

    int duracion = 0;
    int mod;

    duracion = capacidad_finca / capacidad_maquina;
    mod = capacidad_finca % capacidad_maquina;


      if (mod != 0){
        duracion = duracion + 1;
      }


    return duracion;

}




/*===================================================
    Metodo para insertar / editar alquiler
  =================================================*/


void GestionAlquiler::InsertarAlquiler (RegTipoFecha fecha, int idfinca, int idmaquina, RegTipoFecha fechafinalq, RegTipoFecha fechatraslado){


    VectorAlquileres[num_alquiler].idalquiler = num_alquiler+1;
    VectorAlquileres[num_alquiler].fechaalquiler = fecha;
    VectorAlquileres[num_alquiler].idfinca = idfinca;
    VectorAlquileres[num_alquiler].idmaquina = idmaquina;
    VectorAlquileres[num_alquiler].fechafinalq = fechafinalq;
    VectorAlquileres[num_alquiler].fechatraslado = fechatraslado;
    num_alquiler++;

    printf("-- Alquiler Insertado -- \n");

}


/*=======================================================
    Metodo para listar alquileres
  =======================================================*/


void GestionAlquiler::ListarAlquiler (){

    int idalquiler;
    int idmaq;
    int idfinca;

    RegTipoFecha fechaalq;
    RegTipoFecha fechafinalq;
    RegTipoFecha fechatraslado;


      printf("\n");
      printf("Pos \t IdAlquiler \t Fecha \t MaquinaID \t FincaID \t FechaFinAlq \t FechaTras  \t NumAlquiler    \n");

        for (int i=0; i < maxalquileres; i++){

          idalquiler = VectorAlquileres[i].idalquiler;
          idmaq = VectorAlquileres[i].idmaquina;
          idfinca = VectorAlquileres[i].idfinca;
          fechaalq = VectorAlquileres[i].fechaalquiler;
          fechafinalq = VectorAlquileres[i].fechafinalq;
          fechatraslado = VectorAlquileres[i].fechatraslado;


          if ( VectorAlquileres[i].idalquiler > 0) {
              printf(" %d \t %d \t\t %d/%d/%d \t %d \t %d \t\t %d/%d/%d \t %d/%d/%d \t %d \n", i, idalquiler, fechaalq, idmaq, idfinca, fechafinalq, fechatraslado, num_alquiler);
          }
        }
      printf("\n");


}



/*=======================================================
   Metodo para buscar la finca en donde esta la maquina
  =======================================================*/

int GestionAlquiler::BuscarFinca (int id){

      int lastfinca = 0;
      bool match = false;

// PARAR BUCLE CON FECHA POSTERIOR ???
      for (int i = 0; i <= num_alquiler; i++){
          if (id == VectorAlquileres[i].idmaquina){
              lastfinca = VectorAlquileres[i].idfinca;
              match = true;  // Posible eliminar no es necesaria
          }
      }

  return lastfinca;

}


/*===================================================
   Metodo para contar los dias traslado en un mes
  =================================================*/


int GestionAlquiler::Traslados (RegTipoFecha fecha, int maquina) {

    int tras;
    int month;
    int year;

    tras = 0;
    month = fecha.mes ;
    year = fecha.anno;


    for ( int i = 0; i <= num_alquiler; i++){

        if ( VectorAlquileres[i].idmaquina == maquina){
            if ( VectorAlquileres[i].fechaalquiler.mes == month && VectorAlquileres[i].fechaalquiler.anno == year && VectorAlquileres[i].fechaalquiler.dia != 1 ){
              tras ++;

            }
        }
    }

  return tras;

}












