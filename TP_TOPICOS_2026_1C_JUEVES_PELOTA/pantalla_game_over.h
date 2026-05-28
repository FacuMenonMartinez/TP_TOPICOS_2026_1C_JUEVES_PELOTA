#ifndef PANTALLA_GAME_OVER_H_INCLUDED
#define PANTALLA_GAME_OVER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "dibujos.h"
#include "puntaje.h"
#include "caracteres.h"
#include "paletas.h"
#include "jugador.h"
#include "GBT/gbt.h"

/// Pantalla de Game Over
    //Recibe un array que contiene las estructuras de los jugadores
    //Muestra en pantalla ciertos mensajes y el ranking ordenado por puntaje
    //En caso de salir del juego retorna un 0
    //En caso de reiniciar retorna un 1
uint8_t mostrar_Pantalla_Game_Over (t_Jugador []);


#endif // PANTALLA_GAME_OVER_H_INCLUDED
