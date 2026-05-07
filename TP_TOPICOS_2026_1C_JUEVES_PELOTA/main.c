#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>

#include "GBT/gbt.h"
#include "paletas.h"
#include "recursos.h"
#include "tablero.h"

#define ANCHO_VENTANA 640
#define ALTO_VENTANA 480
#define ESCALA_VENTANA 2



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
    sprintf(nombreVentana, "Ventana %dx%d", ANCHO_VENTANA, ALTO_VENTANA);

    //Crear ventana
    if (gbt_crear_ventana(nombreVentana, ANCHO_VENTANA, ALTO_VENTANA, ESCALA_VENTANA) != 0) {
        fprintf(stderr, "Error al iniciar el modulo de graficos de GBT: %s\n", gbt_obtener_log());
        return -1;
    }

    //Aplicar paleta de colores
    if (gbt_aplicar_paleta(paletas[paleta_Activa], CANT_COLORES, GBT_FORMATO_888) != 0) {
        fprintf(stderr, "Error al aplicar la nueva paleta de colores: %s\n", gbt_obtener_log());
        return -1;
    }

    tGBT_Temporizador *temporizador = gbt_temporizador_crear(0.1);
    if (!temporizador) {
        fprintf(stderr, "Error al crear el temporizador para los dibujos: %s\n", gbt_obtener_log());
        return -1;
    }

    tGBT_Temporizador *temporizador_2 = gbt_temporizador_crear(0.1);
    if (!temporizador) {
        fprintf(stderr, "Error al crear el temporizador para los dibujos: %s\n", gbt_obtener_log());
        return -1;
    }

    srand(time(0));

    uint8_t corriendo = 1;
    uint8_t contador_Frames = 0;
    uint8_t nivel = 0;
    ///SETEAR LA PIEZA CON EL RANDOM
    bool pieza_Nueva = 1;
   //Posicion de pieza
    pieza_Pos pieza_Posicion;
    ///pieza_Pos piezaSig_Posicion;

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

        //Deteccion de teclas de desplazamiento por flanco y mantenidas
        uint8_t mover_Der_F = gbt_tecla_presionada(GBTK_DERECHA);
        uint8_t mover_Der_Press = gbt_tecla_sostenida(GBTK_DERECHA);
        uint8_t mover_Der = 0;

        uint8_t mover_Izq_F = gbt_tecla_presionada(GBTK_IZQUIERDA);
        uint8_t mover_Izq_Press = gbt_tecla_sostenida(GBTK_IZQUIERDA);
        uint8_t mover_Izq = 0;

        //Filtrin de tiempo para que no se mueva tan rapido
        if (gbt_temporizador_consumir(temporizador)){
            mover_Der = mover_Der_F || mover_Der_Press;
        }
        if (gbt_temporizador_consumir(temporizador_2)){
            mover_Izq = mover_Izq_F || mover_Izq_Press;
        }

        //Deteccion de tecla de rotacion
        if (tecla == GBTK_ESPACIO){
            printf("Pieza girada\n");
            pieza_Posicion.Rot++;
            if(pieza_Posicion.Rot > 3){
                pieza_Posicion.Rot = GRADOS_0;
            }
        }
        ///pieza_Posicion.Rot = (pieza_Posicion.Rot + 1) & 3;

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

        dibujar_marco(Zc, Zb);

        //Hacer giladas

        //Desplazamiento lateral
        if(mover_Der){
            printf("Pieza desplazada DER\n");
            pieza_Posicion.X ++;
            if (pieza_Posicion.X > GRILLA_COL-1){
                pieza_Posicion.X = GRILLA_COL-1;
            }
        }
        if(mover_Izq){
            printf("Pieza desplazada IZQ\n");
            if (pieza_Posicion.X > 0){
                pieza_Posicion.X --;
            }
        }

        //Caida de la pieza por "Gravedad"
        if (contador_Frames >= tabla_Niveles[nivel]) {
                contador_Frames = 0;
                pieza_Posicion.Y++;
        }
        ///------------------------------
        if(pieza_Posicion.Y > 25)
        {
            pieza_Posicion.Y --;
            pieza_Nueva = 1;
        }

        //Detectar colision
        //Agregar colision a la condicion para que deje de sumar y la dibuje en el lugar que quedo


        //Dibujar la pieza en la pos que le corresponda
        dibujar_Pieza(pieza_J, pieza_Posicion,Sc, Sb);


        //Volcar pixeles dibujados en el backbuffer a la ventana
        gbt_volcar_backbuffer();

        contador_Frames++;
        gbt_esperar(16); //Aprox 60 FPS
    }

    gbt_temporizador_destruir(temporizador);
    gbt_temporizador_destruir(temporizador_2);
    gbt_destruir_ventana();
    gbt_cerrar();
    return 0;
}
