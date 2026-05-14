#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "dibujos.h"
#include "GBT/gbt.h"
#include "piezas.h"
#include "recursos.h"
#include "caracteres.h"

void calcular_Posicion(uint8_t grilla_X,uint8_t grilla_Y, uint16_t  *coord_X, uint16_t  *coord_Y){
    //Calcular coordenada X
    *coord_X = grilla_Origen_X + (grilla_X * (MINO_LADO + (MINO_BORDE *2)));
    //Calcular coordenada Y
    *coord_Y = grilla_Origen_Y + (grilla_Y * (MINO_LADO + (MINO_BORDE *2)));
}

void dibujar_mino(uint16_t oX, uint16_t oY, uint8_t color_Centro, uint8_t color_Borde){

    uint8_t color;

    for(uint16_t y = 0; y < MINO_LADO; y++){
        for(uint16_t x = 0; x < MINO_LADO; x++){
            color = pieza_Mino[y][x]? color_Borde : color_Centro;
             gbt_dibujar_pixel(oX+x,oY+y,color);
        }
    }
}

/*
//version anterior donde le mandaba coordenadas en pixeles
void dibujar_Pieza(pieza_Grilla pieza[], uint16_t oX, uint16_t oY, uint8_t rotacion, uint8_t color_Centro,uint8_t color_Borde){
    for(uint16_t i = 0; i<PIEZA_LADO; i++){
        for(uint16_t j = 0; j<PIEZA_LADO; j++){
            if (pieza[rotacion][j][i] == true){
                dibujar_mino(oX + (i*(MINO_LADO+MINO_BORDE)), oY + (j* (MINO_LADO+MINO_BORDE)), color_Centro,color_Borde);
            }
        }
    }
}
*/
//Nueva version donde mando un struct que contiene indices de X e Y referidos a la grilla juego
void dibujar_Pieza(e_Piezas pieza, pieza_Pos posicion, uint8_t color_Centro,uint8_t color_Borde){
    uint16_t oX = 0 ,oY = 0;
    calcular_Posicion(posicion.X, posicion.Y, &oX, &oY);
    for(uint16_t i = 0; i<PIEZA_LADO; i++){
        for(uint16_t j = 0; j<PIEZA_LADO; j++){
            if (piezas[pieza][posicion.Rot][j][i] == true){
                dibujar_mino(oX + (i*(MINO_LADO+MINO_BORDE)), oY + (j* (MINO_LADO+MINO_BORDE)), color_Centro,color_Borde);
            }
        }
    }
}

//Funcion que dibuja los caracteres en forma de palabra
void dibujar_Palabra_F1(uint8_t palabra[], uint8_t tam, uint16_t pos_X, uint16_t pos_Y, uint8_t escala, uint8_t luz, uint8_t sombra, uint8_t base){
            for(uint8_t i=0; i<tam; i++){
                dibujar_Caracter_F1(palabra[i], pos_X + i*12 ,+ pos_Y,escala,sombra, luz, base);
            }
}























