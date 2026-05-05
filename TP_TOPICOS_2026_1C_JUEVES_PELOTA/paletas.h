#ifndef PALETAS_H_INCLUDED
#define PALETAS_H_INCLUDED

#include "GBT/gbt.h"

#define CANT_COLORES 16
#define CANT_PALETAS 3


#define Tc  0   //c: Contorno
#define Tb  1   //b: Base
#define Ic  2
#define Ib  3
#define Jc  4
#define Jb  5
#define Lc  6
#define Lb  7
#define Zc  8
#define Zb  9
#define Sc  10
#define Sb  11
#define MARGEN  12
#define NEGRO   13
#define AUX     14
#define AUX_2   15

extern const tGBT_ColorRGB paleta_Vivos[CANT_COLORES], paleta_Nocturnos[CANT_COLORES], paleta_Metalicos[CANT_COLORES];

//Lista de paletas
typedef enum {
    PALETA_VIVOS = 0,
    PALETA_NOCTURNOS,
    PALETA_METALICOS,
} tipo_Paleta;

//Array de punteros a paletas
extern const tGBT_ColorRGB* paletas[CANT_PALETAS];

#endif // PALETAS_H_INCLUDED
