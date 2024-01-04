#pragma once



// Variables y constantes

const int maxmaquinas = 10;
const int maxfincas = 20;
const int maxalquileres = 30;



// Tipos definidos

typedef char TipoCadenaTexto[21];
//typedef enum TipoCultivo {Grano, Uva, Aceituna, Borrar};


/*===================================================
        DATOS ESTRUCTURADOS
  =================================================*/


typedef struct TipoFecha{

  int day;
  int month;
  int year;
};



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
  TipoFecha fechaalquiler;
  int idfinca;
  int idmaquina;


};





/*===================================================
              TADs
  =================================================*/

// Gestion Inventario maquinas

typedef struct GestionMaquinaria {

    void InsertarMaquina(int id, TipoCadenaTexto nombre_maquina, char cultivo_maquina, int capacidad_maquina, float latitud_maquina, float longitud_maquina);
    void ListarMaquinas ();
    void Init (); // Inicializa vectores y variables
    void Borrar (int id); // Metodo para borrar un elemento del vector maquinas


    int num_maquinas; // Variable para mantener el conteo de las maquinas creadas
    TipoMaquina VectorMaquinas[maxmaquinas]; // Vector que contiene las maquinas

};


// Gestion propiedades fincas

typedef struct GestionFincas {

    void InsertarFinca(int idfinca, TipoCadenaTexto nombre_finca, char cultivo_finca, int capacidad_finca, float latitud_finca, float longitud_finca);
    void ListarFincas ();
    void Init (); // Inicializa vectores y variables
    void Borrar (int id); // Metodo para borrar un elemento del vector fincas


    int num_fincas; // Variable para mantener el conteo de las fincas creadas
    TipoFinca VectorFincas[maxfincas]; // Vector que contiene las fincas

};


// Gestion alquileres

typedef struct GestionAlquiler {

      void Init (); // Inicializa el vector de alquileres
      void InsertarAlquiler( TipoFecha fecha, int idfinca, int idmaquina); // Inserta datos en vector Alquileres
      int CalcularDistancia (TipoFinca fincaori, TipoFinca fincades); //Metodo para calcular la distancia entre fincas

      void ListarAlquiler (); // Metodo para listar los alquileres
      int BuscarFinca (int id); // Metodo para buscar la ultima finca activa de una maquina

      void TiempoTras (TipoFecha fecha);

      void PlanMensual();

// TODO (alumno#1#): Implementar metodo Borrar alquileres


    int num_alquiler; // variable para llevar conteo de los alquileres
    TipoAlquiler VectorAlquileres[maxalquileres]; // Vector para almacenar los alquileres

};






















