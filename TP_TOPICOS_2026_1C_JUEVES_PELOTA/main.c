#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>

#include "GBT/gbt.h"
#include "paletas.h"
#include "movimiento.h"
#include "dibujos.h"

#include "caracteres.h"
#include "puntaje.h"
#include "pantalla_inicio.h"
#include "jugador.h"

#define CANT_NIVELES 15

const uint8_t tabla_Niveles[CANT_NIVELES] = {48, 43, 38, 33, 28, 23, 18, 13, 8, 6, 5, 4, 3, 2, 1};

int main(int argc, char* argv[])
{
    uint8_t paleta_Activa = PALETA_VIVOS;
    t_Jugador jug;

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

    tGBT_Temporizador *temporizador = gbt_temporizador_crear(0.016); //16ms
    if (!temporizador) {
        fprintf(stderr, "Error al crear el temporizador para los dibujos: %s\n", gbt_obtener_log());
        return -1;
    }


    srand(time(NULL));
    //Muestra la pantalla de inicio. Al salir, inicia el ciclo del juego.
    uint8_t corriendo= mostrar_Pantalla_Inicio();
    uint16_t puntaje = 0;
    uint8_t crear_jugador= mostrar_Pantalla_Crear_Jugador(&jug);
    uint8_t contador_Frames = 0;
    uint8_t nivel = 3;
    bool pieza_Nueva = 1;
    uint8_t pieza_indice = 0;


   if(crear_jugador)
        corriendo=1;
    else
        corriendo=0;



   //Posicion de pieza
    pieza_Pos pieza_Pos_Actual, pieza_Pos_Siguiente, pieza_Pos_Prediccion;

    pieza_Pos_Prediccion.Rot=1;
    pieza_Pos_Prediccion.X=0;
    pieza_Pos_Prediccion.Y=0;



    //corriendo=mostrar_Pantalla_Jugador(&jug);

    while(corriendo){

        //Detectar algun evento de tecla
        gbt_procesar_entrada();
        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();

        //Salir de la ejecucion
        if (tecla == GBTK_ESCAPE){
            corriendo = 0;

            printf("Saliendo del ejemplo\n");
        }

        //Giladas con la paleta de colores
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
        //Aplicar nueva paleta
        if (gbt_aplicar_paleta(paletas[paleta_Activa], CANT_COLORES, GBT_FORMATO_888) != 0) {
            fprintf(stderr, "Error al aplicar la nueva paleta de colores: %s\n", gbt_obtener_log());
            return -1;
        }

        //Dibujar pieza en coordenada de inicio
        if (pieza_Nueva){
            pieza_indice = rand() % 7; //Generar pieza random / Reemplazar por algun algoritmo mas piola
            pieza_Pos_Actual.X =      GRILLA_COL/2;
            pieza_Pos_Actual.Y =      0;
            pieza_Pos_Actual.Rot =    e_Pieza_0;      //Generar pieza aleatoria
            dibujar_Pieza(pieza_indice, &pieza_Pos_Actual,Sc, Sb);
            pieza_Nueva = 0;
        }

        //Contador de frames em funcion del temporizador
        if (gbt_temporizador_consumir(temporizador)){
            contador_Frames++;
        }

        //modificadores de velocidad

        //----- Desplazamiento hacia la derecha -----

        pieza_Pos_Siguiente = pieza_Pos_Actual;
        //Actualizar coordenada
        if (tecla == GBTK_DERECHA){
            movimiento_Der(&pieza_Pos_Siguiente);
        }
        //Verificar si la nueva posicion es valida
        if(posicion_Valida(pieza_indice, &pieza_Pos_Siguiente)){
            //Actualizar posicion en la grilla
            pieza_Pos_Actual = pieza_Pos_Siguiente;
        }
        //----- Desplazamiento hacia la izquierda-----

        pieza_Pos_Siguiente = pieza_Pos_Actual;
        //Actualizar coordenada
        if (tecla == GBTK_IZQUIERDA){
            movimiento_Izq(&pieza_Pos_Siguiente);
        }
        //Verificar si la nueva posicion es valida
        if(posicion_Valida(pieza_indice, &pieza_Pos_Siguiente)){
            //Actualizar posicion en la grilla
            pieza_Pos_Actual = pieza_Pos_Siguiente;
        }

        //----- Giro horario -----

        pieza_Pos_Siguiente = pieza_Pos_Actual;
        //Actualizar coordenada
        if (tecla == GBTK_d){
            movimiento_Giro_H(&pieza_Pos_Siguiente);
        }
        //Verificar si la nueva posicion es valida
        if(posicion_Valida(pieza_indice, &pieza_Pos_Siguiente)){
            //Actualizar posicion en la grilla
            pieza_Pos_Actual = pieza_Pos_Siguiente;
        }
        //----- Giro anti horario -----

        pieza_Pos_Siguiente = pieza_Pos_Actual;
        //Actualizar coordenada
        if (tecla == GBTK_a){
            movimiento_Giro_AH(&pieza_Pos_Siguiente);
        }
        //Verificar si la nueva posicion es valida
        if(posicion_Valida(pieza_indice, &pieza_Pos_Siguiente)){
            //Actualizar posicion en la grilla
            pieza_Pos_Actual = pieza_Pos_Siguiente;
        }

        //----- Caida gravedad -----

        pieza_Pos_Siguiente = pieza_Pos_Actual;
        bool bajar= false;
        if (contador_Frames >= tabla_Niveles[nivel]) {
            contador_Frames = 0;
            movimiento_Grav(&pieza_Pos_Siguiente);
            bajar = true;
        }
        //Verificar si la pos es valida
        if(posicion_Valida(pieza_indice, &pieza_Pos_Siguiente)){
            //Actualizar posicion en la grilla
            pieza_Pos_Actual = pieza_Pos_Siguiente;
        }
        else if(bajar) //Si tengo que bajar y no puedo >> bloquear la pieza
        {
            printf("coord x: %d coord y: %d\n", pieza_Pos_Actual.X, pieza_Pos_Actual.Y);
            actualizar_Grilla(pieza_indice, &pieza_Pos_Actual);

            //Verificar si se esta actualizando la grilla
            printf("\nGRILLA: \n");
            for(int i = 0; i <GRILLA_FIL; i++){
                for(int j = 0; j<GRILLA_COL; j++){
                    printf(" %d ", grilla_Juego[i][j]);
                }
                printf("\n");
            }
            printf("\n\n");

            pieza_Nueva = 1;

           puntaje = calcular_Puntaje(puntaje,1,0,nivel);
        }

        //Eliminar filas completadas

        //Llenar el backbuffer con un color
        gbt_borrar_backbuffer(AUX);

        //Hacer giladas
        mostrar_Puntaje(puntaje, VENTANA_ANCHO/10,VENTANA_ALTO/8);

        //Dibujar la pieza en la pos que le corresponda
        dibujar_Pieza(pieza_indice, &pieza_Pos_Actual,Sc, Sb);
        dibujar_Grilla_Juego();
        //Volcar pixeles dibujados en el backbuffer a la ventana
        gbt_volcar_backbuffer();
        gbt_esperar(10);
    }
    gbt_temporizador_destruir(temporizador);
    gbt_destruir_ventana();
    gbt_cerrar();
    return 0;
}


