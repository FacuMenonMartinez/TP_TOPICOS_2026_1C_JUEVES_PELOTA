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
        {0,1,0,0},
        {0,1,1,0},
        {0,1,0,0},
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
    },
};
/*
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
*/

void pieza_Movimiento(pieza_Pos *pieza, eGBT_Tecla *tecla){
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

        case GBTK_DERECHA:
                printf("Pieza desplazada a derecha\n");
                if (pieza->X <GRILLA_COL){
                    pieza->X ++;
                }
            break;

        case GBTK_IZQUIERDA:
            printf("Pieza desplazada a izquierda\n");
            if(pieza->X > 0){
                pieza->X --;
            }
            break;

        default:
            break;
    }
}





