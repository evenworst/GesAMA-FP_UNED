#pragma once

#include "CalendarioGesAMA.h"




// Variables y constantes

const int maxmaquinas = 10;
const int maxfincas = 20;
const int maxalquileres = 50;

const float navelat = 0.0; // Se parte de coordenadas 0 en la nave
const float navelon = 0.0;


// Tipos definidos

typedef char TipoCadenaTexto[21];


/*===================================================
        DATOS ESTRUCTURADOS
  =================================================*/

// Estructura maquina

typedef struct TipoMaquina {

  int id;
  TipoCadenaTexto nombre_maquina;
  char cultivo_maquina;
  int capacidad_maquina;
  float latitud_maquina;
  float longitud_maquina;

};



// Estructura finca

typedef struct TipoFinca {

  int idfinca;
  TipoCadenaTexto nombre_finca;
  char cultivo_finca;
  int capacidad_finca;
  float latitud_finca;
  float longitud_finca;

};



// Estructura Alquiler

typedef struct TipoAlquiler {

  int idalquiler;
  RegTipoFecha fechaalquiler;
  int idfinca;
  int idmaquina;
  RegTipoFecha fechafinalq;
  RegTipoFecha fechatraslado;


};





/*===================================================
              TADs
  =================================================*/

// Gestion Inventario maquinas

typedef struct GestionMaquinaria {

    void InsertarMaquina(int id, TipoCadenaTexto nombre_maquina, char cultivo_maquina, int capacidad_maquina, float latitud_maquina, float longitud_maquina); // Metodo para insertar un elemento en el vector maquinas
    void ListarMaquinas (); // Metodo para listar maquinas
    void Init (); // Inicializa vectores y variables
    void Borrar (int id); // Metodo para borrar un elemento del vector maquinas


    int num_maquinas; // Variable para mantener el conteo de las maquinas creadas
    TipoMaquina VectorMaquinas[maxmaquinas]; // Vector que contiene las maquinas

};


// Gestion propiedades fincas

typedef struct GestionFincas {

    void InsertarFinca(int idfinca, TipoCadenaTexto nombre_finca, char cultivo_finca, int capacidad_finca, float latitud_finca, float longitud_finca); // Metodo para insertar un elemento en el vector fincas
    void ListarFincas (); // Metodo para listar fincas
    void Init (); // Inicializa vectores y variables
    void Borrar (int id); // Metodo para borrar un elemento del vector fincas


    int num_fincas; // Variable para mantener el conteo de las fincas creadas
    TipoFinca VectorFincas[maxfincas]; // Vector que contiene las fincas

};


// Gestion alquileres

typedef struct GestionAlquiler {

      void Init (); // Inicializa el vector de alquileres
      void InsertarAlquiler( RegTipoFecha fecha, int idfinca, int idmaquina, RegTipoFecha fechafinalq, RegTipoFecha fechatraslado); // Inserta datos en vector Alquileres
      int CalcularDistancia (TipoFinca fincaori, TipoFinca fincades); //Metodo para calcular la distancia entre fincas
      int CalcularCosecha (int capacidad_finca, int capacidad_maquina); //Metodo para calcular los dias necesarios para cosechas fincas


      void ListarAlquiler (); // Metodo para listar los alquileres
      int BuscarFinca (int id); // Metodo para buscar la ultima finca activa de una maquina
      int Traslados (RegTipoFecha fecha, int maquina); // Metodo para calcular los traslados en un mes

      void Cosechas ( RegTipoFecha fecha, int maquina); // Metodo para devolver el id de las fincas en cosecha en un mes

      int TotalDiasCosechaMes (RegTipoFecha fecha, int maquina);  // Metodo para calcular el total de dias ocupada una maquina en un mes

      void PlanMensual();

// TODO (alumno#1#): Implementar metodo Borrar alquileres


    int num_alquiler; // variable para llevar conteo de los alquileres
    TipoAlquiler VectorAlquileres[maxalquileres]; // Vector para almacenar los alquileres

    GestionFincas alquilerfincas;



};






















