#ifndef PIEZAS_H_INCLUDED
#define PIEZAS_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>

#define MINO_LADO 8
#define MINO_BORDE 3
#define PIEZA_LADO 4
#define ROTACIONES 4

typedef enum{
GRADOS_0 = 0,
GRADOS_90,
GRADOS_180,
GRADOS_270,
}pieza_Rotacion;

//Posicion de la pieza en la grilla de juego
typedef struct{
uint8_t X;
uint8_t Y;
uint8_t Rot;
}pieza_Pos;

//Declaracion del cuadradito que formara las piezas
extern const bool pieza_Mino[MINO_LADO][MINO_LADO];

//Declaracion del tipo de dato que contendra el bitmap de la pieza
typedef uint8_t pieza_Grilla[PIEZA_LADO][PIEZA_LADO];

//Declaracion de piezas
extern const pieza_Grilla   pieza_T[ROTACIONES],
                            pieza_J[ROTACIONES],
                            pieza_L[ROTACIONES],
                            pieza_O[ROTACIONES],
                            pieza_S[ROTACIONES],
                            pieza_Z[ROTACIONES],
                            pieza_I[ROTACIONES];

#endif // PIEZAS_H_INCLUDED
