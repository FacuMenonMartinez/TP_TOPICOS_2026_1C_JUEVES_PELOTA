#include "piezas.h"
#include "recursos.h"

const bool pieza_Mino[MINO_LADO][MINO_LADO] =
    //Version 1
    /*
    {
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    };
    */
    /*
    //Version 2
    {
    {0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,0},
    {0,1,1,0,0,1,1,0},
    {0,1,1,0,0,1,1,0},
    {0,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0},
    };
    */

    //Version 4x4
    {
    {1,1,1,1},
    {1,0,0,1},
    {1,0,0,1},
    {1,1,1,1},
    };
const pieza_Grilla pieza_T[ROTACIONES] = {
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
        {0,1,0,0},
        {0,1,1,0},
        {0,1,0,0},
        {0,0,0,0},
    },
};

const pieza_Grilla pieza_L[ROTACIONES] = {
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
};

const pieza_Grilla pieza_J[ROTACIONES] = {
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
};

const pieza_Grilla pieza_O[ROTACIONES] = {
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
};

const pieza_Grilla pieza_S[ROTACIONES] = {
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
};

const pieza_Grilla pieza_Z[ROTACIONES] = {
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
};

const pieza_Grilla pieza_I[ROTACIONES] = {
    //Posicion 0 grados
    {
        {0,1,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {0,1,0,0},
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
        {0,1,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {0,1,0,0},
    },
    //Posicion 270 grados
    {
        {0,0,0,0},
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0},
    },
};

void pieza_Girar(pieza_Pos *pieza, eGBT_Tecla *tecla){
    switch (*tecla){

        case GBTK_a:
            printf("Pieza girada en sentido anti horario\n");
            if (pieza->Rot == 0){
                pieza->Rot = 3;
            }
            else{
                pieza->Rot--;
            }
            break;

        case GBTK_d:
            printf("Pieza girada en sentido horario\n");
            pieza->Rot++;
            if(pieza->Rot > 3){
                pieza->Rot = 0;
            }
            break;

        default:
            break;
    }
}

void pieza_Desplazar(eGBT_Tecla *izq, eGBT_Tecla *der, pieza_Pos *pieza){
    if (*izq){
        printf("Pieza desplazada a izquierda\n");
        if(pieza->X > 0){
            pieza->X --;
        }
    }
    if (*der){
        printf("Pieza desplazada a derecha\n");
        if (pieza->X <GRILLA_COL){
            pieza->X ++;
        }
    }
}





