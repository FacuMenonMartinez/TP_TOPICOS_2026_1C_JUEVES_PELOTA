#include "piezas.h"
#include "movimiento.h"

const bool pieza_Mino[MINO_LADO][MINO_LADO] =
    {
    {1,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,1},
    };

const bool pieza_Mino_Fondo[FONDO_LADO][FONDO_LADO] =
    {
    {1,1},
    {1,1},
    };

const pieza_Grilla piezas[CANT_PIEZAS][ROTACIONES] = {
    //Pieza T:
    {
        //Posicion 0 grados
        {
        {0,0,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {0,0,0,0},
        },
        //Posicion 90 grados
        {
        {0,1,0,0},
        {1,1,0,0},
        {0,1,0,0},
        {0,0,0,0},
        },
        //Posicion 180 grados
        {
        {0,1,0,0},
        {1,1,1,0},
        {0,0,0,0},
        {0,0,0,0},
        },
        //Posicion 270 grados
        {
        {1,0,0,0},
        {1,1,0,0},
        {1,0,0,0},
        {0,0,0,0},
        },
    },
    //Pieza L:
    {
        //Posicion 0 grados
        {
            {1,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {0,0,0,0},
        },
        //Posicion 90 grados
        {
            {1,1,1,0},
            {1,0,0,0},
            {0,0,0,0},
            {0,0,0,0},
        },
        //Posicion 180 grados
        {
            {1,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,0,0,0},
        },
        //Posicion 270 grados
        {
            {0,0,1,0},
            {1,1,1,0},
            {0,0,0,0},
            {0,0,0,0},
        },
    },
    //Pieza J:
    {
        //Posicion 0 grados
        {
            {0,1,0,0},
            {0,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
        },
        //Posicion 90 grados
        {
            {1,0,0,0},
            {1,1,1,0},
            {0,0,0,0},
            {0,0,0,0},
        },
        //Posicion 180 grados
        {
            {1,1,0,0},
            {1,0,0,0},
            {1,0,0,0},
            {0,0,0,0},
        },
        //Posicion 270 grados
        {
            {1,1,1,0},
            {0,0,1,0},
            {0,0,0,0},
            {0,0,0,0},
        },
    },
    //Pieza O:
    {
        //Posicion 0 grados
        {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0},
        },
        //Posicion 90 grados
        {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0},
        },
        //Posicion 180 grados
        {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0},
        },
        //Posicion 270 grados
        {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0},
        },
    },
    //Pieza S:
    {
        //Posicion 0 grados
        {
            {0,1,1,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0},
        },
        //Posicion 90 grados
        {
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,0,0,0},
        },
        //Posicion 180 grados
        {
            {0,1,1,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0},
        },
        //Posicion 270 grados
        {
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,0,0,0},
        },
    },
    //Pieza Z:
    {
        //Posicion 0 grados
        {
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0},
            {0,0,0,0},
        },
        //Posicion 90 grados
        {
            {0,1,0,0},
            {1,1,0,0},
            {1,0,0,0},
            {0,0,0,0},
        },
        //Posicion 180 grados
        {
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0},
            {0,0,0,0},
        },
        //Posicion 270 grados
        {
            {0,1,0,0},
            {1,1,0,0},
            {1,0,0,0},
            {0,0,0,0},
        },
    },
    //Pieza I:
    {
        //Posicion 0 grados
        {
            {1,0,0,0},
            {1,0,0,0},
            {1,0,0,0},
            {1,0,0,0},
        },
        //Posicion 90 grados
        {
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0},
        },
        //Posicion 180 grados
        {
            {1,0,0,0},
            {1,0,0,0},
            {1,0,0,0},
            {1,0,0,0},
        },
        //Posicion 270 grados
        {
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0},
        },
    },
};


//array que contiene la generacion de piezas
uint8_t generacion_Piezas[CANT_PIEZAS];
uint8_t indice = 0;

//Inicializar el array que contiene la generacion de las piezas
void piezas_Inicializar(){
    uint8_t i = 0;
    //Inicializar vector con la cantidad de piezas
    while(i < CANT_PIEZAS){
        *(generacion_Piezas + i) = i;
        i++;
    }
    //Mezclar para poder ir sacando piezas aleatorias sin repeticion
    for (uint8_t j = CANT_PIEZAS - 1; j > 0; j--){
        uint8_t k = rand() % (j + 1);
        uint8_t temp = generacion_Piezas[j];
        generacion_Piezas[j] = generacion_Piezas[k];
        generacion_Piezas[k] = temp;
    }
    indice = 0;
}

uint8_t pieza_Siguiente(){
    if(indice >= CANT_PIEZAS){
        piezas_Inicializar();
    }
    uint8_t temp_Pieza = generacion_Piezas[indice];
    indice++;
    return temp_Pieza;
    indice++;
}
