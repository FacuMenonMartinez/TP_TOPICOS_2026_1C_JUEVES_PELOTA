#include "movimiento.h"

uint16_t grilla_Origen_X =  (VENTANA_ANCHO/2)-((GRILLA_COL * (MINO_LADO + (MINO_BORDE *2)))/2);
uint16_t grilla_Origen_Y  =  20;

bool grilla_Juego[GRILLA_FIL][GRILLA_COL] = {{0}};

bool posicion_Valida(e_Piezas epieza, pieza_Pos *pieza_PosNueva){
    //Coordenadas de la pieza respecto de la grilla!
    uint8_t coord_X = 0, coord_Y = 0;

    for(uint8_t y = 0; y<PIEZA_LADO; y++){
        for(uint8_t x = 0; x<PIEZA_LADO; x++){

            coord_X  = pieza_PosNueva->X + x;
            coord_Y  = pieza_PosNueva->Y + y;

            if (piezas[epieza][pieza_PosNueva->Rot][y][x]){   //Solo valido las posiciones en las que hay un 1 en el bitmap de la pieza ; piezas es la variable definida en piezas.h
                //Validar si no puede bajar mas porque llego al final
                if(coord_Y >= GRILLA_FIL){
                    return false;
                }
                //Valida que no se vaya de costado
                if(coord_X >= GRILLA_COL){
                    return false;
                }
                //Si hay algun uno en la grilla para esta posicion de la pieza significa que se la pone si se mueve
                if(grilla_Juego[coord_Y][coord_X]){
                    return false;
                }
            }
        }
    }
    return true;    //Si no fue false significa que es true
}

void movimiento_Der(pieza_Pos *pieza_Pos){
        if (pieza_Pos->X <GRILLA_COL){
            pieza_Pos->X ++;
        }
}

void movimiento_Izq(pieza_Pos *pieza_Pos){
        if(pieza_Pos->X > 0){
            pieza_Pos->X --;
        }
}

void movimiento_Giro_H(pieza_Pos *pieza_Pos){
    pieza_Pos->Rot++;
    if(pieza_Pos->Rot > 3){
        pieza_Pos->Rot = 0;
    }
}

void movimiento_Giro_AH(pieza_Pos *pieza_Pos){
        if (pieza_Pos->Rot == 0){
            pieza_Pos->Rot = 3;
        }
        else{
            pieza_Pos->Rot--;
        }
}

void movimiento_Grav(pieza_Pos *pieza_Pos){
    pieza_Pos->Y++;
}

void actualizar_Grilla(e_Piezas epieza, pieza_Pos *pieza_Pos){

    for(uint8_t y = 0; y<PIEZA_LADO; y++){
        for(uint8_t x = 0; x<PIEZA_LADO; x++){
            if (piezas[epieza][pieza_Pos->Rot][y][x]){
                    grilla_Juego[pieza_Pos->Y + y][pieza_Pos->X + x] = 1;
            }
        }
    }
}






