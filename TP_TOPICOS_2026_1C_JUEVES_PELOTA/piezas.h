#ifndef PIEZAS_H_INCLUDED
#define PIEZAS_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "GBT/gbt.h"

#define MINO_LADO   4 //Unidad Px
#define MINO_BORDE  2 //Unidad Px
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

//Declaracion del cuadradito que formara las piezas
extern const bool pieza_Mino[MINO_LADO][MINO_LADO];

//Declaracion del tipo de dato que contendra el bitmap de la pieza
typedef bool pieza_Grilla[PIEZA_LADO][PIEZA_LADO];

//Declaracion de piezas
/*
extern const pieza_Grilla   pieza_T[ROTACIONES],
                            pieza_J[ROTACIONES],
                            pieza_L[ROTACIONES],
                            pieza_O[ROTACIONES],
                            pieza_S[ROTACIONES],
                            pieza_Z[ROTACIONES],
                            pieza_I[ROTACIONES];
*/
//Re declaracion de las piezas para poder llamarlas con un indice y utilizar la funcion de nro aleatorio para generarla
extern const pieza_Grilla piezas[CANT_PIEZAS][ROTACIONES];

void pieza_Girar(pieza_Pos *pieza, eGBT_Tecla *tecla);

void pieza_Desplazar(eGBT_Tecla *izq, eGBT_Tecla *der, pieza_Pos *pieza);

#endif // PIEZAS_H_INCLUDED
