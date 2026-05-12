#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>

#include "GBT/gbt.h"
#include "paletas.h"
#include "recursos.h"

#include "caracteres.h"
#include "puntaje.h"

#define CANT_NIVELES 15

const uint8_t tabla_Niveles[CANT_NIVELES] = {48, 43, 38, 33, 28, 23, 18, 13, 8, 6, 5, 4, 3, 2, 1};

int main(int argc, char* argv[])
{
    uint8_t paleta_Activa = PALETA_VIVOS;

    //Iniciar biblioteca
    if(gbt_iniciar() !=0 ){
        fprintf(stderr, "Error al iniciar biblioteca: %s\n", gbt_obtener_log());
        return -1;
    };

    //Definir nombre de ventana
    char nombreVentana[128];
    sprintf(nombreVentana, "Ventana %dx%d", VENTANA_ANCHO, VENTANA_ALTO);

    //Crear ventana
    if (gbt_crear_ventana(nombreVentana, VENTANA_ANCHO, VENTANA_ALTO, ESCALA_VENTANA) != 0) {
        fprintf(stderr, "Error al iniciar el modulo de graficos de GBT: %s\n", gbt_obtener_log());
        return -1;
    }

    //Aplicar paleta de colores
    if (gbt_aplicar_paleta(paletas[paleta_Activa], CANT_COLORES, GBT_FORMATO_888) != 0) {
        fprintf(stderr, "Error al aplicar la nueva paleta de colores: %s\n", gbt_obtener_log());
        return -1;
    }

    tGBT_Temporizador *temporizador = gbt_temporizador_crear(0.5);
    if (!temporizador) {
        fprintf(stderr, "Error al crear el temporizador para los dibujos: %s\n", gbt_obtener_log());
        return -1;
    }

    srand(time(0));

    uint8_t corriendo = 1;
    uint8_t contador_Frames = 0;
    uint8_t nivel = 0;
    bool pieza_Nueva = 1;
   //Posicion de pieza
    pieza_Pos pieza_Posicion;

    while(corriendo){

        //Dibujar pieza en coordenada de inicio
        if (pieza_Nueva){
            pieza_Posicion.X =      GRILLA_COL/2;
            pieza_Posicion.Y =      5;
            pieza_Posicion.Rot =    GRADOS_0;
            dibujar_Pieza(pieza_L, pieza_Posicion,Sc, Sb);
            pieza_Nueva = 0;
        }

        //Detectar algun evento de tecla
        gbt_procesar_entrada();
        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();
        eGBT_Tecla pieza_Mov_Der = gbt_tecla_soltada(GBTK_DERECHA);
        eGBT_Tecla pieza_Mov_Izq = gbt_tecla_soltada(GBTK_IZQUIERDA);

        //Salir de la ejecucion
        if (tecla == GBTK_ESCAPE){
            corriendo = 0;
            printf("Saliendo del ejemplo\n");
        }

        //Cambiar paleta de colores
        //Meter en una funcion segun la necesidad de cambiar de paleta
        switch (tecla){
            case GBTK_u:
                paleta_Activa = PALETA_VIVOS;
                break;
            case GBTK_i:
                paleta_Activa = PALETA_NOCTURNOS;
                break;
            case GBTK_o:
                paleta_Activa = PALETA_METALICOS;
                break;
            default:
                break;
        }
        if (gbt_aplicar_paleta(paletas[paleta_Activa], CANT_COLORES, GBT_FORMATO_888) != 0) {
            fprintf(stderr, "Error al aplicar la nueva paleta de colores: %s\n", gbt_obtener_log());
            return -1;
        }

        //Llenar el backbuffer con un color
        gbt_borrar_backbuffer(AUX);

        //Hacer giladas

        dibujar_Caracter_F1(fuente_Primera[c_Z],VENTANA_ANCHO-12,0,1,7,2,9);

        //Giro de la pieza
        pieza_Girar(&pieza_Posicion, &tecla);

        //Movimiento de la pieza
        pieza_Desplazar(&pieza_Mov_Izq, &pieza_Mov_Der, &pieza_Posicion);

        //Caida de la pieza por "Gravedad"
        if (contador_Frames >= tabla_Niveles[nivel]) {
                contador_Frames = 0;
                pieza_Posicion.Y++;
        }


        //Detectar colision
        //Agregar colision a la condicion para que deje de sumar y la dibuje en el lugar que quedo


        //Dibujar la pieza en la pos que le corresponda
        dibujar_Pieza(pieza_L, pieza_Posicion,Sc, Sb);

        //Volcar pixeles dibujados en el backbuffer a la ventana
        gbt_volcar_backbuffer();

        contador_Frames++;
        gbt_esperar(16); //Aprox 60 FPS
    }

    gbt_temporizador_destruir(temporizador);
    gbt_destruir_ventana();
    gbt_cerrar();
    return 0;
}
