#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#define GRILLA_FIL 20
#define GRILLA_COL 10

#include "piezas.h"

typedef enum{
    ecolision = 0,
    epos_Valida,
    egame_Over,
}e_retorno_Validacion;

//Origines de la grilla de juego relativos a la resolucion de la pantalla
//extern uint16_t grilla_Origen_X, grilla_Origen_Y;

extern uint16_t VENTANA_ANCHO;
extern uint16_t VENTANA_ALTO;
extern uint16_t ESCALA_VENTANA;

//Matriz de posiciones ocupadas en el juego
extern bool grilla_Juego[GRILLA_FIL][GRILLA_COL];

/** \brief
 * Determina si la posicion a la que se quiere mover la pieza es valida o no es posible porque ya esta ocupada
 * \param que pieza es la que quiero validar segun el indice de esa lista
 * \param puntero a variable que contiene la posicion x, y y rotacion de la pieza que quiero validar
 * \return true: posicion valida, false: posicion invalida
 */

e_retorno_Validacion posicion_Valida(e_Piezas epieza, pieza_Pos *pieza_PosNueva);

/** \brief
 * Estas funciones se encargan de actualizar las coordenadas y el indice de giro de la pieza que se le pase por parametro
 *
 */

void movimiento_Der(pieza_Pos *pieza_Pos);

void movimiento_Izq(pieza_Pos *pieza_Pos);

void movimiento_Giro_H(pieza_Pos *pieza_Pos);

void movimiento_Giro_AH(pieza_Pos *pieza_Pos);

void movimiento_Grav(pieza_Pos *pieza_Pos);

void fijar_Pieza(e_Piezas epieza, pieza_Pos *pieza_Pos);

#endif // MOVIMIENTO_H_INCLUDED
