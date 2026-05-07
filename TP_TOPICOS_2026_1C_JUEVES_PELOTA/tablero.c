#include "tablero.h"
#include "recursos.h" //para poder usar las macros
#include "GBT/gbt.h"

#define INCREMENTAR(var, paso) ((var) += (paso))
#define PASO 10 //TAMANIO DEL MINO
#define OY_GRILLA


///Funcion dibujar tablero
void dibujar_marco(uint8_t color_Centro,uint8_t color_Borde)
//A esta funcion se le debe mandar un dato tipo config para poder dibujar las distintas opciones
///Convertir todos los parametros de dibujar mino en Macros
{
    ////    for(int g, g<grosor) POR SI SE QUIERE AGREGAR UN DOBLE BORDE
    int i=0;
    for(i=GRILLA_ORIGEN_X-14;i<=GRILLA_ORIGEN_X-14+(GRILLA_COL+2)*14; INCREMENTAR(i,PASO))
    {
        dibujar_mino(i, GRILLA_ORIGEN_Y+56, color_Centro, color_Borde);
        dibujar_mino(i, GRILLA_ORIGEN_Y+112+(GRILLA_FIL)*14, color_Centro, color_Borde);
    }
    for(i=GRILLA_ORIGEN_Y+56; i<=GRILLA_ORIGEN_Y+112+(GRILLA_FIL)*14; INCREMENTAR(i,PASO))
    {
        dibujar_mino(GRILLA_ORIGEN_X-14, i, color_Centro, color_Borde);
        dibujar_mino(GRILLA_ORIGEN_X-14+(GRILLA_COL+2)*14, i, color_Centro, color_Borde);
    }






//    for(i=GRILLA_ORIGEN_X;i<=GRILLA_ORIGEN_X+GRILLA_COL; i++)
//    {
//        gbt_dibujar_pixel(i,GRILLA_ORIGEN_Y,color_Centro);
//        gbt_dibujar_pixel(i, GRILLA_ORIGEN_Y+GRILLA_FIL,color_Centro);
//    }
//    for(i=GRILLA_ORIGEN_Y; i<=GRILLA_ORIGEN_Y+GRILLA_FIL; i++)
//    {
//        gbt_dibujar_pixel(GRILLA_ORIGEN_X, i, color_Centro);
//        gbt_dibujar_pixel(GRILLA_ORIGEN_X+GRILLA_COL, i, color_Centro);
//    }



}

//
//{
////    bordes arriba y abajo
////    for(int g, g<grosor)
//for(int i=oX; i<oX+ancho; i++)
//{
//    gbt_dibujar_pixel(i,oY,color);
//    gbt_dibujar_pixel(i,oY+alto,color);
//}
//for(int i=oY; i<oY+alto; i++)
//{
//    gbt_dibujar_pixel(oX,i,color);
//    gbt_dibujar_pixel(oX+ancho,i,color);
//}
//}
