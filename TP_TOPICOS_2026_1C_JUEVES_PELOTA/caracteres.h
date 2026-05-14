#ifndef CARACTERES_H_INCLUDED
#define CARACTERES_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "GBT/gbt.h"


#define FUENTE_PRIMERA_ANCHO 12
#define FUENTE_PRIMERA_ALTO 15
#define FUENTE_SEGUNDA_ANCHO 10
#define FUENTE_SEGUNDA_ALTO 8
#define CANTIDAD_CARACTERES 36

typedef enum
{
    c_0,
    c_1,
    c_2,
    c_3,
    c_4,
    c_5,
    c_6,
    c_7,
    c_8,
    c_9,
    c_A,
    c_B,
    c_C,
    c_D,
    c_E,
    c_F,
    c_G,
    c_H,
    c_I,
    c_J,
    c_K,
    c_L,
    c_M,
    c_N,
    c_O,
    c_P,
    c_Q,
    c_R,
    c_S,
    c_T,
    c_U,
    c_V,
    c_W,
    c_X,
    c_Y,
    c_Z,

} e_Caracter;

extern const uint8_t fuente_Primera[CANTIDAD_CARACTERES][FUENTE_PRIMERA_ALTO][FUENTE_PRIMERA_ANCHO];
extern const bool fuente_Segunda[CANTIDAD_CARACTERES][FUENTE_SEGUNDA_ALTO][FUENTE_SEGUNDA_ANCHO];

extern bool unidad_Minima_F1[2][2];
extern uint8_t unidad_Minima_F2[4][4];

void dibujar_Caracter_F1(e_Caracter ecaracter,uint16_t eje_X, uint16_t eje_Y, uint8_t escala, uint8_t sombra, uint8_t luz, uint8_t base);


#endif // CARACTERES_H_INCLUDED
