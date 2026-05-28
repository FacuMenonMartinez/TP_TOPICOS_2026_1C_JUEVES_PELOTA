#include "pantalla_game_over.h"

uint8_t mensaje_Fin_Juego[13]={c_F,c_I,c_N,c_ES,c_D,c_E,c_L,c_ES,c_J,c_U,c_E,c_G,c_O};
uint8_t mensaje_Salida[9]={c_S,c_A,c_L,c_I,c_R,c_ES,c_E,c_S,c_C};
uint8_t mensaje_Reiniciar[13]={c_R,c_E,c_I,c_N,c_I,c_C,c_I,c_A,c_R,c_ES,c_E,c_N,c_T};
uint8_t mensaje_Ranking[7]={c_R,c_A,c_N,c_K,c_I,c_N,c_G};

uint8_t mostrar_Pantalla_Game_Over (t_Jugador ranking[]){

    eGBT_Tecla tecla;
    uint8_t mostrar_Pantalla=1;



    gbt_borrar_backbuffer(AUX);

    while(mostrar_Pantalla==1){
        gbt_procesar_entrada();
        tecla = gbt_obtener_tecla_presionada();

        if (tecla==GBTK_ENTER){
            mostrar_Pantalla=0;
            return 1;
        }

        if(tecla== GBTK_ESCAPE){
            mostrar_Pantalla =0;
            printf("SALIENDO DEL JUEGO");
            gbt_volcar_backbuffer();
            gbt_destruir_ventana();
            gbt_cerrar();
            return 2;
        }

        dibujar_Palabra_F1(mensaje_Fin_Juego,13, VENTANA_ANCHO/2 - (FUENTE_PRIMERA_ANCHO*13)/2, VENTANA_ALTO/VENTANA_ALTO + (FUENTE_PRIMERA_ALTO*1.5), 1, 4,13,12);
        dibujar_Palabra_F2(mensaje_Salida,9, VENTANA_ANCHO/VENTANA_ANCHO + 7, VENTANA_ALTO/VENTANA_ALTO + (FUENTE_SEGUNDA_ALTO), 1, 4);
        dibujar_Palabra_F2(mensaje_Reiniciar,13, VENTANA_ANCHO - (FUENTE_SEGUNDA_ANCHO)*17, VENTANA_ALTO/VENTANA_ALTO + (FUENTE_SEGUNDA_ALTO), 1, 4);
        dibujar_Palabra_F2(mensaje_Ranking,7, VENTANA_ANCHO/2 - (FUENTE_SEGUNDA_ANCHO*7)/2, VENTANA_ALTO/2 - FUENTE_SEGUNDA_ALTO*8, 1, 4);


        for(uint8_t i =0; i<CANTIDAD_JUGADORES-1; i++){

            if(ranking[i].jugador_Nombre[0]>=c_A && ranking[i].jugador_Nombre[0]<c_ES){
                dibujar_Palabra_F2(ranking[i].jugador_Nombre,CARACTERES_JUGADOR, VENTANA_ANCHO/VENTANA_ANCHO + (FUENTE_SEGUNDA_ANCHO + 7), VENTANA_ALTO/2 + (FUENTE_SEGUNDA_ALTO*i) + (i*FUENTE_SEGUNDA_ALTO/2), 1, 4);
                mostrar_Puntaje(ranking[i].puntaje, VENTANA_ANCHO - FUENTE_SEGUNDA_ANCHO*6 ,VENTANA_ALTO/2 + (FUENTE_SEGUNDA_ALTO*i) + (i*FUENTE_SEGUNDA_ALTO/2),1);
            }


        }





        gbt_volcar_backbuffer();
    }



}
