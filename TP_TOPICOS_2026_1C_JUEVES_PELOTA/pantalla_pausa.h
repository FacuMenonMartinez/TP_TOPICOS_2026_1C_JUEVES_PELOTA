#ifndef PANTALLA_PAUSA_H_INCLUDED
#define PANTALLA_PAUSA_H_INCLUDED

#include <stdio.h>
#include <stdint.h>

#include "GBT/gbt.h"
#include "dibujos.h"
#include "caracteres.h"
#include "movimiento.h"
#include "jugador.h"
#include "paletas.h"

/// Detiene el flujo del juego al presionar una tecla
    // En caso de volver a presionar la tecla el juego se reanuda
    // En caso de presionar escape el juego termina

uint8_t mostrar_Pantalla_Pausa ();

#endif // PANTALLA_PAUSA_H_INCLUDED
