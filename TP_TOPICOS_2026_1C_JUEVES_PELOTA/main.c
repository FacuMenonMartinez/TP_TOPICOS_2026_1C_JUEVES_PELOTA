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
#include "pantalla_pausa.h"
#include "pantalla_game_over.h"
#include "jugador.h"
#include "configuracion.h"

#define CANT_NIVELES 15

const uint8_t tabla_Niveles[CANT_NIVELES] = {48, 43, 38, 33, 28, 23, 18, 13, 8, 6, 5, 4, 3, 2, 1};
uint16_t VENTANA_ANCHO = 0 ,VENTANA_ALTO = 0, ESCALA_VENTANA = 0 ;

int main(int argc, char* argv[])
{
//    crearArchConfigInicial();
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
    ///Para la paleta mando paleta[config.paleta]
//        if(config.paleta)
//        {
//
//        }
//        else
//        {
//
//        }

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
        printf("--- Valores cargados desde %s ---\n", nombre_archivo);
        printf("Paleta: %d\n", config.paleta);
        printf("Resolucion: %d\n", config.resolucion);
        printf("Velocidad: %d\n", config.velocidad);
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
    if (gbt_aplicar_paleta(paletas[config.paleta], CANT_COLORES, GBT_FORMATO_888) != 0) {
        fprintf(stderr, "Error al aplicar la nueva paleta de colores: %s\n", gbt_obtener_log());
        return -1;
    }

    tGBT_Temporizador *temporizador = gbt_temporizador_crear(0.016); //16ms
    if (!temporizador) {
        fprintf(stderr, "Error al crear el temporizador para los dibujos: %s\n", gbt_obtener_log());
        return -1;
    }


    srand(time(NULL));

    t_Jugador jug, ranking[CANTIDAD_JUGADORES];
    uint8_t corriendo= mostrar_Pantalla_Inicio();
    uint8_t pausa=0;
    uint16_t puntaje = 0;
    uint8_t crear_jugador= mostrar_Pantalla_Crear_Jugador(&jug);
    uint8_t configuracion = mostrar_Pantalla_Configuracion(config.paleta,config.resolucion,config.velocidad);
    uint8_t contador_Frames = 0;
    uint8_t nivel = 0;
    bool pieza_Nueva = 1;
    uint8_t pieza_Indice_Actual = 0;
    uint8_t pieza_Indice_Siguiente;
    pieza_Pos pieza_Pos_Actual, pieza_Pos_Siguiente;
    uint8_t bajar_Rapido;
    uint8_t nivel_Bajar_Rapido = 10;
    uint8_t fila=0;
     corriendo=0;


    if(crear_jugador)
        corriendo=1;
    else
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

        //Pausar juego
        if(tecla==GBTK_p)
            pausa=1;

        //Cambio de paletas
        paletas_Cambio(GBTK_u, GBTK_i, GBTK_o, &tecla);

        //Determinar cual sera la siguiente pieza
        pieza_Indice_Siguiente = pieza_Siguiente();

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
        if(posicion_Valida(pieza_Indice_Actual, &pieza_Pos_Siguiente)){
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
        if(posicion_Valida(pieza_Indice_Actual, &pieza_Pos_Siguiente)){
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
        if(posicion_Valida(pieza_Indice_Actual, &pieza_Pos_Siguiente)){
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
        if(posicion_Valida(pieza_Indice_Actual, &pieza_Pos_Siguiente)){
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
                bajar = true;
            }
        }else if(contador_Frames >= tabla_Niveles[nivel]) {
            contador_Frames = 0;
            movimiento_Grav(&pieza_Pos_Siguiente);
            bajar = true;
        }
        //Verificar si la pos es valida
        if(posicion_Valida(pieza_Indice_Actual, &pieza_Pos_Siguiente)){
            //Actualizar posicion en la grilla
            pieza_Pos_Actual = pieza_Pos_Siguiente;
        }
        else if(bajar) //Si tengo que bajar y no puedo >> bloquear la pieza
        {
            printf("coord x: %d coord y: %d\n", pieza_Pos_Actual.X, pieza_Pos_Actual.Y);
            fijar_Pieza(pieza_Indice_Actual, &pieza_Pos_Actual);
            pieza_Nueva = 1;
//            puntaje = calcular_Puntaje(puntaje,1,0,nivel);
        }

        if (pieza_Nueva == 1){
                int fila_Eliminar;
                //Mientras haya alguna fila para eliminar
                while((fila_Eliminar = verificar_Filas()) != -1){
                    //Eliminar fila completada
                    eliminar_Fila(fila_Eliminar);
                    fila++;
                    //Bajar una posicion todos los minos por encima de la fila eliminada

                //Contador de cuantas filas se eliminaron

                }
                //Asignar la nueva pieza a generar
                pieza_Indice_Actual = pieza_Indice_Siguiente;
            }
            puntaje = calcular_Puntaje(puntaje,fila,0,nivel);
            fila=0;


        //Llenar el backbuffer con un color
        gbt_borrar_backbuffer(AUX);

        //Mostrar puntaje
        mostrar_Puntaje_Main(puntaje, VENTANA_ANCHO/10,VENTANA_ALTO/8,2);
        dibujar_Grilla_Juego();
        //Dibujar la pieza en la pos que le corresponda
        dibujar_Pieza(pieza_Indice_Actual, &pieza_Pos_Actual,Sc, Sb);

        //Entrar en la pausa
        while(pausa==1)
        {
            pausa = mostrar_Pantalla_Pausa();

            if(pausa==2)
                corriendo=0;
        }

        //Contador de frames em funcion del temporizador
        if (gbt_temporizador_consumir(temporizador)){
            contador_Frames++;
            //Volcar pixeles dibujados en el backbuffer a la ventana
            gbt_volcar_backbuffer();
        }

        gbt_esperar(10);
    }

    jug.puntaje=puntaje;
    crear_Vector_Jugador(ranking, &jug);
    crear_Archivo_Jugador(ranking);

    for(uint8_t i =0;i<CANTIDAD_JUGADORES;i++){
        printf("JUGADOR: %d %d %d  PUNTAJE: %d\n",ranking[i].jugador_Nombre[0],ranking[i].jugador_Nombre[1],ranking[i].jugador_Nombre[2], ranking[i].puntaje);
    }

    corriendo = mostrar_Pantalla_Game_Over(ranking);
    gbt_temporizador_destruir(temporizador);
    gbt_destruir_ventana();
    gbt_cerrar();

    return 0;
}
