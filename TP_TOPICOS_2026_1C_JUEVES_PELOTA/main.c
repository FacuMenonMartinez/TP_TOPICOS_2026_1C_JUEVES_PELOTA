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
#include "configuracion.h"

#define CANT_NIVELES 15

const uint8_t tabla_Niveles[CANT_NIVELES] = {48, 43, 38, 33, 28, 23, 18, 13, 8, 6, 5, 4, 3, 2, 1};
uint16_t VENTANA_ANCHO = 0 ,VENTANA_ALTO = 0, ESCALA_VENTANA = 0;

int main(int argc, char* argv[])
{

    //Iniciar biblioteca
    if(gbt_iniciar() !=0 ){
        fprintf(stderr, "Error al iniciar biblioteca: %s\n", gbt_obtener_log());
        return -1;
    };

        const char* nombre_archivo = argv[1];
    t_Configuracion config;
    ///Leo el archivo y seteo los parametros segun la config que tenga
    if (leerConfiguracion(nombre_archivo, &config))
    {
        //Desglose de parametros
        if(config.paleta)
        {

        }
        else
        {

        }

        if(config.resolucion) //VGA 640x480
        {
            VENTANA_ANCHO = 640;
            VENTANA_ALTO = 480;
            ESCALA_VENTANA = 2;
        }
        else //CGA 320x200
        {
            VENTANA_ANCHO = 320;
            VENTANA_ALTO = 200;
            ESCALA_VENTANA = 3;
        }

        if(config.velocidad)
        {

        }
        else
        {

        }
//        ///PENDIENTE RELACIONAR LOS VALORES DEL ARCHIVO CON CADA PARAMETRO
//        printf("--- Valores cargados desde %s ---\n", nombre_del_archivo);
//        printf("Paleta: %d\n", config.paleta);
//        printf("Resolucion: %d\n", config.resolucion);
//        printf("Velocidad: %d\n", config.velocidad);
    }

    //Definir nombre de ventana
    char nombreVentana[128];
    sprintf(nombreVentana, "Ventana %dx%d", VENTANA_ANCHO, VENTANA_ALTO);

    //Crear ventana
    if (gbt_crear_ventana(nombreVentana, VENTANA_ANCHO, VENTANA_ALTO, ESCALA_VENTANA) != 0) {
        fprintf(stderr, "Error al iniciar el modulo de graficos de GBT: %s\n", gbt_obtener_log());
        return -1;
    }

    //Aplicar paleta de colores
    if (gbt_aplicar_paleta(paletas[0], CANT_COLORES, GBT_FORMATO_888) != 0) {
        fprintf(stderr, "Error al aplicar la nueva paleta de colores: %s\n", gbt_obtener_log());
        return -1;
    }

    tGBT_Temporizador *temporizador = gbt_temporizador_crear(0.016); //16ms
    if (!temporizador) {
        fprintf(stderr, "Error al crear el temporizador para los dibujos: %s\n", gbt_obtener_log());
        return -1;
    }


    srand(time(NULL));


    uint8_t corriendo= mostrar_Pantalla_Inicio();
    uint16_t puntaje = 0;
//    uint8_t crear_jugador= mostrar_Pantalla_Crear_Jugador(&jug);
    uint8_t configuracion = mostrar_Pantalla_Configuracion(config.paleta,config.resolucion,config.velocidad);
    uint8_t contador_Frames = 0;
    uint8_t nivel = 0;
    bool pieza_Nueva = 1;
    uint8_t pieza_Indice_Actual = 0;
    uint8_t pieza_Indice_Siguiente;
    pieza_Pos pieza_Pos_Actual, pieza_Pos_Siguiente;
    uint8_t bajar_Rapido;
    uint8_t nivel_Bajar_Rapido = 10;
    uint8_t filas_Eliminadas=0;
    uint16_t piezas_Fijadas = 0;
    uint16_t descensos_Rapidos = 0;
    uint16_t contador_Frames_Aux =0;
    bool game_Over = 0;
    corriendo=0;

   if(configuracion)
        corriendo=1;
    else
        corriendo=0;


///    crearArchConfigInicial();

    //Inicializar array que contiene las piezas a generar
    piezas_Inicializar();

    while(corriendo){
        //Detectar algun evento de tecla
        gbt_procesar_entrada();
        eGBT_Tecla tecla = gbt_obtener_tecla_presionada();
        bajar_Rapido = gbt_tecla_sostenida(GBTK_ABAJO);

        //Salir de la ejecucion
        if (tecla == GBTK_ESCAPE){
            corriendo = 0;

            printf("Saliendo del ejemplo\n");
        }

        //Cambio de paletas
        paletas_Cambio(GBTK_u, GBTK_i, GBTK_o, &tecla);

        //Dibujar pieza en coordenada de inicio
        if (pieza_Nueva){
            //Dibujar pieza en coordenada de inicio
            pieza_Pos_Actual.X =      GRILLA_COL/2;
            pieza_Pos_Actual.Y =      0;
            pieza_Pos_Actual.Rot =    e_Pieza_0;      //Generar pieza aleatoria
            dibujar_Pieza(pieza_Indice_Actual, &pieza_Pos_Actual,Sc, Sb);
            pieza_Nueva = 0;

            //Determinar cual sera la siguiente pieza
            pieza_Indice_Siguiente = pieza_Siguiente();
            printf("Pieza siguiente: %d\n", pieza_Indice_Siguiente);
        }

        //modificadores de velocidad

        //----- Desplazamiento hacia la derecha -----

        pieza_Pos_Siguiente = pieza_Pos_Actual;
        //Actualizar coordenada
        if (tecla == GBTK_DERECHA){
            movimiento_Der(&pieza_Pos_Siguiente);
        }
        //Verificar si la nueva posicion es valida
        if(posicion_Valida(pieza_Indice_Actual, &pieza_Pos_Siguiente) == epos_Valida){
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
        if(posicion_Valida(pieza_Indice_Actual, &pieza_Pos_Siguiente)== epos_Valida){
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
        if(posicion_Valida(pieza_Indice_Actual, &pieza_Pos_Siguiente)== epos_Valida){
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
        if(posicion_Valida(pieza_Indice_Actual, &pieza_Pos_Siguiente)== epos_Valida){
            //Actualizar posicion en la grilla
            pieza_Pos_Actual = pieza_Pos_Siguiente;
        }

        //----- Caida gravedad / Bajar rapido -----
        pieza_Pos_Siguiente = pieza_Pos_Actual;
        bool bajar= false;
        if(bajar_Rapido != 0){
            if(contador_Frames >= tabla_Niveles[nivel_Bajar_Rapido]){
                contador_Frames = 0;
                movimiento_Grav(&pieza_Pos_Siguiente);
                //Contador de descensos rapidos
                descensos_Rapidos++;            //Reinicializar luego de usar
                bajar = true;
            }
        }else if(contador_Frames >= tabla_Niveles[nivel]) {
            contador_Frames = 0;
            movimiento_Grav(&pieza_Pos_Siguiente);
            bajar = true;
        }
        //Verificar si la pos es valida
        e_retorno_Validacion pos_Valida = posicion_Valida(pieza_Indice_Actual, &pieza_Pos_Siguiente);
        if(pos_Valida== epos_Valida){
            //Actualizar posicion en la grilla
            pieza_Pos_Actual = pieza_Pos_Siguiente;
        }
        else if(pos_Valida== egame_Over){
            game_Over  = true;
            printf("Game over\n");
        }
        else if(bajar) //Si tengo que bajar y no puedo >> bloquear la pieza
        {
            printf("coord x: %d coord y: %d\n", pieza_Pos_Actual.X, pieza_Pos_Actual.Y);

            //Temporizacion para fijar la pieza
            if(contador_Frames_Aux >= (tabla_Niveles[nivel] /2 )){
                contador_Frames_Aux = 0;
                fijar_Pieza(pieza_Indice_Actual, &pieza_Pos_Actual);
                pieza_Nueva = 1;
            }
        }


        if (pieza_Nueva == 1){
                int fila_Eliminar;

                //Contador de piezas fijadas
                piezas_Fijadas++;
                printf("Piezas fijadas/caidas: %d\n", piezas_Fijadas);

                //Mientras haya alguna fila para eliminar
                while((fila_Eliminar = verificar_Filas()) != -1){

                    //Eliminar fila completada
                    eliminar_Fila(fila_Eliminar);

                    //Contador de filas eliminadas
                    filas_Eliminadas++;
                }

                printf("Filas eliminadas: %d\n", filas_Eliminadas);

                //Asignar la nueva pieza a generar
                pieza_Indice_Actual = pieza_Indice_Siguiente;

                //Descensos rapidos
                printf("Cant. Descensos rapidos: %d\n", descensos_Rapidos);
            }

            //Calcular puntaje en base a las filas eliminadas
            puntaje = calcular_Puntaje(puntaje,filas_Eliminadas,0,nivel);
            //Reinicializar
            filas_Eliminadas=0;

        //Llenar el backbuffer con un color
        gbt_borrar_backbuffer(AUX);

        //Mostrar puntaje
        mostrar_Puntaje(puntaje, VENTANA_ANCHO/10,VENTANA_ALTO/8);
        dibujar_Grilla_Juego();
        //Dibujar la pieza en la pos que le corresponda
        dibujar_Pieza(pieza_Indice_Actual, &pieza_Pos_Actual,Sc, Sb);
        //Dibujar pieza siguiente y texto
        dibujar_Pieza_Siguiente(pieza_Indice_Siguiente);

        //Contador de frames em funcion del temporizador
        if (gbt_temporizador_consumir(temporizador)){
            contador_Frames++;
            contador_Frames_Aux++;
            //Volcar pixeles dibujados en el backbuffer a la ventana
            gbt_volcar_backbuffer();
        }

        gbt_esperar(10);
    }
    gbt_temporizador_destruir(temporizador);
    gbt_destruir_ventana();
    gbt_cerrar();

    return 0;
}

