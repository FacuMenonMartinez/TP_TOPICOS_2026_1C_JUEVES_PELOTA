#ifndef PANTALLA_INICIO_H_INCLUDED
#define PANTALLA_INICIO_H_INCLUDED
#include <stdio.h>
#include <stdint.h>

#include "GBT/gbt.h"
#include "dibujos.h"
#include "caracteres.h"
#include "movimiento.h"
#include "jugador.h"

#define ALTO_LOGO 30
#define ANCHO_LOGO 75

uint8_t mostrar_Pantalla_Inicio ();
void dibujar_Logo (uint8_t [ALTO_LOGO][ANCHO_LOGO],uint16_t, uint16_t );


#endif // PANTALLA_INICIO_H_INCLUDED
