#include "pantalla_pausa.h"


uint8_t mensaje_Pausa[5]={c_P,c_A,c_U,c_S,c_A};
uint8_t borrar_Pausa[5]={c_ES,c_ES,c_ES,c_ES,c_ES};
uint8_t mensaje_Salir[9]={c_S,c_A,c_L,c_I,c_R,c_ES,c_E,c_S,c_C};

/// MOSTRAR PANTALLA
    //No recibe nada por parametro
    // Posee un temporizador interno y un contador, siguiendo la misma lógica que los frames de la pantalla principal del juego
    // Capta eventos de teclado, en caso de presionar P, retorna 0 y se termina la pausa
    // En caso de presionar ESC retorna un 2 que indica que se cierra el juego desde el main.
uint8_t mostrar_Pantalla_Pausa (){

    tGBT_Temporizador *temp= gbt_temporizador_crear(0.016);
    uint8_t contador=0;

    eGBT_Tecla tecla;
    uint8_t mostrar_Pantalla=1, pausa=1;

    while(mostrar_Pantalla==1){
        gbt_procesar_entrada();

        tecla= gbt_obtener_tecla_presionada();

        if(tecla==GBTK_p){
            mostrar_Pantalla=0;
            printf("SALIENDO DE LA PAUSA");
            gbt_volcar_backbuffer();
        }

        if(pausa==1 && contador>=48){
            pausa=0;
            contador=0;
            dibujar_Palabra_F2(mensaje_Pausa,5, VENTANA_ANCHO/2 - (FUENTE_SEGUNDA_ANCHO*5), VENTANA_ALTO/2 - FUENTE_SEGUNDA_ALTO/2, 2, 12);
            printf("pausa: %d\n", pausa);
        }

        if(pausa==0 && contador>=48){
            pausa=1;
            contador=0;
            dibujar_Palabra_F2(mensaje_Pausa,5, VENTANA_ANCHO/2 - (FUENTE_SEGUNDA_ANCHO*5), VENTANA_ALTO/2 - FUENTE_SEGUNDA_ALTO/2, 2, 13);
            printf("pausa: %d\n", pausa);
        }

        if(gbt_temporizador_consumir(temp))
            contador++;

        gbt_volcar_backbuffer();

    }

    gbt_temporizador_destruir(temp);
    return mostrar_Pantalla;
}
