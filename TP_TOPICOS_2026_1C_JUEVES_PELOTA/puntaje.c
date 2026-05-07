#include "puntaje.h"
#include "caracteres.h"
/* Falta poner un sistema de puntaje, detectar que se debe sumar puntaje, modificar el puntaje en tanto se modifique
        la velocidad de juego y se presionen teclas*/

/* La funcion mostrar puntaje recibe los puntos hechos, descompone el número y los imprime en pantalla ordenados
    en la coordenada que se le indique
    Recibe por parámetro los puntos, coordenada en x y coordenada en y*/

void mostrar_Puntaje (int puntos, uint8_t eje_X, uint8_t eje_Y){
    //Descomprimo los numeros en unidades
    int u_Mil = (puntos/1000)%10;
    int u_Cien=(puntos/100)%10;
    int u_Dec=(puntos/10)%10;
    int u_Uni=puntos%10;

    //Llamo a la funcion dibujar Caracter y le paso las coordenadas para que queden una al lado de la otra.
        dibujar_Caracter_F1(fuente_Primera[u_Mil], eje_X,eje_Y,1);
        dibujar_Caracter_F1(fuente_Primera[u_Cien], eje_X + 12,eje_Y,1);
        dibujar_Caracter_F1(fuente_Primera[u_Dec], eje_X + 24,eje_Y,1);
        dibujar_Caracter_F1(fuente_Primera[u_Uni], eje_X + 36,eje_Y,1);
}
