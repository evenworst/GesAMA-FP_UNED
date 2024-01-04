#pragma once

#include "TiposGesAMA4.h"



typedef struct TipoMenu {

    void MenuPrincipal();
    void MenuRegreso ();
    void MenuEditarMaquina ();
    void MenuListarMaquina ();
    void MenuEditarFinca ();
    void MenuListarFinca ();
    void MenuAlquiler ();
    void MenuListarAlquiler ();
    void MenuPlanMensual ();

    void MenuPrint ();  // se puede eliminar



    char opcion;

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
    TipoFecha fechaini;
    GestionAlquiler c;



};






