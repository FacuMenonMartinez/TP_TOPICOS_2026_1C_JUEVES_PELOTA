#include "puntaje.h"
#include "caracteres.h"
#include "dibujos.h"

uint8_t texto_Puntos [6]={c_P,c_U,c_N,c_T,c_O,c_S};

///Calcula los puntajes a partir de lo sucedido en el juego
//Recibe parametro de puntos actuales, filas que se eliminaron, cuadros que bajaron a mayor velocidad y nivel actual
//Retorna el puntaje calculado
uint16_t calcular_Puntaje (uint16_t puntos, uint8_t filas, uint8_t cuadros, uint8_t nivel){
    uint16_t total= puntos;
    uint8_t dificultad = 58 - nivel;

    if(filas!=0)
        total += dificultad+(8*filas);

    if(cuadros!=0)
        total += dificultad/2 + (1*cuadros);




    return total;
}

/* La funcion mostrar puntaje recibe los puntos hechos, descompone el número y los imprime en pantalla ordenados
    en la coordenada que se le indique
    Recibe por parámetro los puntos, coordenada en x y coordenada en y*/

void mostrar_Puntaje (uint16_t puntos, uint16_t eje_X, uint16_t eje_Y, uint8_t escala){
    //Descomprimo los numeros en unidades
    int u_Mil = (puntos/1000)%10;
    int u_Cien=(puntos/100)%10;
    int u_Dec=(puntos/10)%10;
    int u_Uni=puntos%10;

    //Llamo a la funcion dibujar Caracter y le paso las coordenadas para que queden una al lado de la otra.
        dibujar_Caracter_F2(u_Mil, eje_X, eje_Y,escala,12);
        dibujar_Caracter_F2(u_Cien, eje_X + (FUENTE_SEGUNDA_ANCHO+1)*escala,eje_Y,escala,12);
        dibujar_Caracter_F2(u_Dec, eje_X + (FUENTE_SEGUNDA_ANCHO+1)*escala*2,eje_Y,escala,12);
        dibujar_Caracter_F2(u_Uni, eje_X + (FUENTE_SEGUNDA_ANCHO+1)*escala*3,eje_Y,escala,12);

        //dibujar_Palabra_F1(texto_Puntos,6,eje_X,eje_Y,1,4,5,6);
}

void mostrar_Puntaje_Main (uint16_t puntos, uint16_t eje_X, uint16_t eje_Y, uint8_t escala){
    //Descomprimo los numeros en unidades
    int u_Mil = (puntos/1000)%10;
    int u_Cien=(puntos/100)%10;
    int u_Dec=(puntos/10)%10;
    int u_Uni=puntos%10;

    //Llamo a la funcion dibujar Caracter y le paso las coordenadas para que queden una al lado de la otra.
        dibujar_Caracter_F2(u_Mil, eje_X, eje_Y + FUENTE_PRIMERA_ALTO +3 ,escala,12);
        dibujar_Caracter_F2(u_Cien, eje_X + (FUENTE_SEGUNDA_ANCHO+1)*escala,eje_Y + FUENTE_PRIMERA_ALTO +3 ,escala,12);
        dibujar_Caracter_F2(u_Dec, eje_X + (FUENTE_SEGUNDA_ANCHO+1)*escala*2,eje_Y + FUENTE_PRIMERA_ALTO +3 ,escala,12);
        dibujar_Caracter_F2(u_Uni, eje_X + (FUENTE_SEGUNDA_ANCHO+1)*escala*3,eje_Y + FUENTE_PRIMERA_ALTO +3 ,escala,12);

        dibujar_Palabra_F1(texto_Puntos,6,eje_X,eje_Y,1,4,5,6);
}
