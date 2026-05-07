#ifndef DIBUJOS_H_INCLUDED
#define DIBUJOS_H_INCLUDED

#include "piezas.h"

/*
Esta funcion recibe un nro entero que corresponde a un indice
dentro de una matriz de 10x20 que representa la grilla del juego
y devuelve la coordenada de esa grilla para pasarlas a la funcion
que dibuja la pieza

*/

void calcular_Posicion(uint8_t grilla_X,uint8_t grilla_Y, uint16_t  *coord_X, uint16_t  *coord_Y);

//Funcion para dibujar mino
void dibujar_mino(uint16_t oX, uint16_t oY, uint8_t color_Centro, uint8_t color_Borde);


//Funcion para dibujar pieza
void dibujar_Pieza(pieza_Grilla pieza[], pieza_Pos posicion, uint8_t color_Centro,uint8_t color_Borde);



#endif // DIBUJOS_H_INCLUDED
