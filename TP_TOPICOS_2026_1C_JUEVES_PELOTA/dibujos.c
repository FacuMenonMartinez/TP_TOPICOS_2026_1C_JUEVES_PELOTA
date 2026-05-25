#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "dibujos.h"
#include "GBT/gbt.h"
#include "piezas.h"
#include "movimiento.h"
#include "caracteres.h"

void calcular_Posicion(uint16_t grilla_X,uint16_t grilla_Y, uint16_t  *coord_X, uint16_t  *coord_Y){
    //Calcular coordenada X
    *coord_X = grilla_Origen_X + (grilla_X * (MINO_LADO + MINO_BORDE));
    //Calcular coordenada Y
    *coord_Y = grilla_Origen_Y + (grilla_Y * (MINO_LADO + MINO_BORDE));
}

void dibujar_mino(uint16_t coord_X, uint16_t coord_Y, uint8_t color_Centro, uint8_t color_Borde){

    uint8_t color;
    uint16_t oX = 0 ,oY = 0;
    //Calcular posicion en pixeles de donde se va a dibujar
    calcular_Posicion(coord_X, coord_Y, &oX, &oY);

    for(uint16_t y = 0; y < MINO_LADO; y++){
        for(uint16_t x = 0; x < MINO_LADO; x++){
            color = pieza_Mino[y][x]? color_Borde : color_Centro;
             gbt_dibujar_pixel(oX+x,oY+y,color);
        }
    }
}

void dibujar_Pieza(e_Piezas pieza, pieza_Pos *posicion, uint8_t color_Centro,uint8_t color_Borde){
    for(uint16_t i = 0; i<PIEZA_LADO; i++){
        for(uint16_t j = 0; j<PIEZA_LADO; j++){
            if (piezas[pieza][posicion->Rot][j][i] == true){
                dibujar_mino(posicion->X+i, posicion->Y+j, color_Centro,color_Borde);
            }
        }
    }
}

void dibujar_Grilla_Juego(){
    for(uint8_t y = 0; y<GRILLA_FIL; y++){
        for(uint8_t x = 0; x<GRILLA_COL; x++){
            if(grilla_Juego[y][x]){
                //que hago con los colores?
                dibujar_mino(x, y, 7, 4);
            }
        }
    }
}

//Funcion que dibuja los caracteres en forma de palabra
void dibujar_Palabra_F1(uint8_t palabra[], uint8_t tam, uint16_t pos_X, uint16_t pos_Y, uint8_t escala, uint8_t luz, uint8_t sombra, uint8_t base){
            for(uint8_t i=0; i<tam; i++){
                dibujar_Caracter_F1(palabra[i], pos_X + i*12*escala ,+ pos_Y,escala,sombra, luz, base);
            }
}

void dibujar_Palabra_F2(uint8_t palabra[], uint8_t tam, uint16_t pos_X, uint16_t pos_Y, uint8_t escala, uint8_t color){
            for(uint8_t i=0; i<tam; i++){
                dibujar_Caracter_F2(palabra[i], pos_X + i*7*escala ,+ pos_Y,escala,color);
            }
}

