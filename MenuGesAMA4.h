#pragma once

#include "TiposGesAMA4.h"
#include "CalendarioGesAMA.h"

typedef struct TipoMenu {

    void MenuStartScreen();
    void MenuPrincipal();
    void MenuRegreso ();
    void MenuEditarMaquina ();
    void MenuListarMaquina ();
    void MenuEditarFinca ();
    void MenuListarFinca ();
    void MenuAlquiler ();
    void MenuListarAlquiler ();
    void MenuPlanMensual ();
    void Calendario ();

    int CosechasMes ();
    int TotalDiasCosecha ();
    int TiempoEsperas ();
    bool MaquinaDisponible (RegTipoFecha fechafin, RegTipoFecha fechatraslado);


    void MenuPrint ();  // se puede eliminar

    char opcion;
    char opciondemo;
    bool demo;

 // Variables TipoMaquina
    int id;
    TipoCadenaTexto nombre_maquina;
    char cultivo_maquina;
    int capacidad_maquina;
    float latitud_maquina;
    float longitud_maquina;

    GestionMaquinaria a;

 // Variables TipoFinca
    int idfinca;
    TipoCadenaTexto nombre_finca;
    char cultivo_finca;
    int capacidad_finca;
    float latitud_finca;
    float longitud_finca;

    GestionFincas b;


 // Variables TipoAlquiler
    char confirma;
    bool select;
    RegTipoFecha fechaini;
    RegTipoFecha fechafin;
    RegTipoFecha fecha;
    bool disponible;

    GestionAlquiler c;


 // Variables Calendario

    CalendarioGesAMA q;




};






