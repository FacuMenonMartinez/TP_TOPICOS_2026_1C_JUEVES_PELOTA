#ifndef RECURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

#include "dibujos.h"

#define VENTANA_ANCHO 320
#define VENTANA_ALTO 200
#define ESCALA_VENTANA 3
//VGA: 640x480 CGA: 320x200

#define GRILLA_FIL 24
#define GRILLA_COL 10

extern uint16_t grilla_Origen_X, grilla_Origen_Y;

//Matriz de posiciones ocupadas en el juego
extern bool grilla_Juego[GRILLA_FIL][GRILLA_COL];


//Funcion para actualizar matriz de posiciones
/*
Recibe como parametros la grilla del juego que hay que actualizar
la pieza que se va a dibujar (bitmap)
y la posicion de la pieza que se va a dibuajar (x,y,rotacion)
*/
void actualizar_Grilla(bool grilla[][GRILLA_COL], pieza_Grilla pieza[], pieza_Pos posicion);



#endif // RECURSOS_H_INCLUDED
