#ifndef PIEZAS_H_INCLUDED
#define PIEZAS_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "GBT/gbt.h"

#define MINO_LADO   4 //Unidad Px
#define MINO_BORDE  2 //Unidad Px
#define FONDO_LADO 2
#define FONDO_BORDE 1
#define PIEZA_LADO  4 //Unidad Mino
#define ROTACIONES  4
#define CANT_PIEZAS 7


//Posicion de la pieza en la grilla de juego
typedef struct{
uint8_t X;
uint8_t Y;
uint8_t Rot;
}pieza_Pos;

typedef enum{
    e_Pieza_T = 0,
    e_Pieza_J,
    e_Pieza_L,
    e_Pieza_O,
    e_Pieza_S,
    e_Pieza_Z,
    e_Pieza_I,
}e_Piezas;

typedef enum{
e_Pieza_0 = 0,
e_Pieza_90,
e_Pieza_180,
e_Pieza_270,
}e_Piezas_Rotacion;

typedef struct{
    uint8_t borde;
    uint8_t centro;
}t_Pieza_Color;


//Declaracion del cuadradito que formara las piezas
extern const bool pieza_Mino[MINO_LADO][MINO_LADO];

//Declaracion del tipo de dato que contendra el bitmap de la pieza
typedef bool pieza_Grilla[PIEZA_LADO][PIEZA_LADO];

//Declaracion de piezas
extern const pieza_Grilla piezas[CANT_PIEZAS][ROTACIONES];

//array que contiene la generacion de piezas
extern uint8_t piezas_Generadas[CANT_PIEZAS];

//Inicializar el array que contiene la generacion de las piezas aleatorias
void piezas_Inicializar();

//Devuelve la siguiente pieza a generar
uint8_t pieza_Siguiente();


#endif // PIEZAS_H_INCLUDED
