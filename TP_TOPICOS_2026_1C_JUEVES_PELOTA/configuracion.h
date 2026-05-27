#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "GBT/gbt.h"
#include "caracteres.h"
#include "dibujos.h"
#include "movimiento.h"

//El juego va a venir de por si con un archivo configuracion por defecto por lo que no se va a crear uno

typedef struct{
    bool paleta; //0=Paleta 1 1=Paleta 2
    bool resolucion; //0=CGA 1=VGA
    bool velocidad; //0=Facil 1=Dificil
}t_Configuracion;


uint8_t mostrar_Pantalla_Configuracion(bool , bool ,bool);

void actualizarArchConfig(bool * mat);

int modificarParametrosConfig(bool * mat);

bool leerConfiguracion(const char* nombre_archivo, t_Configuracion* config_leida);

void crearArchConfigInicial();
#endif // CONFIGURACION_H_INCLUDED

