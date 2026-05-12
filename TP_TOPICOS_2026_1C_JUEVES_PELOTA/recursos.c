#include "piezas.h"
#include "recursos.h"


uint16_t grilla_Origen_X =  (VENTANA_ANCHO/2)-((GRILLA_COL * (MINO_LADO + (MINO_BORDE *2)))/2);
uint16_t grilla_Origen_Y  =  20;

bool grilla_Juego[GRILLA_FIL][GRILLA_COL] = {{0}};

void actualizar_Grilla(bool grilla[][GRILLA_COL], pieza_Grilla pieza[], pieza_Pos posicion){

    for(uint8_t y = 0; y<PIEZA_LADO; y++){
        for(uint8_t x = 0; x<PIEZA_LADO; x++){
            if (pieza[posicion.Rot][y][x]){
                    grilla[posicion.Y + y][posicion.X + x] = 1;
            }
        }
    }
}
