#include "jugador.h"

uint8_t crear_Jugador_Mensaje[15]={c_I,c_N,c_G,c_R,c_E,c_S,c_E,c_ES,c_J,c_U,c_G,c_A,c_D,c_O,c_R};



///Pantalla donde se crea el jugador
    // Retorna un 1 en caso de que se haya creado con éxito
    //Recibe por puntero una estructura del tipo jugador y guarda en el campo de nombre
    //      los indices de las letras de los caracteres de la A a la Z.
uint8_t mostrar_Pantalla_Crear_Jugador(t_Jugador *jugador){
     uint8_t caracter_Posicion=0;
    eGBT_Tecla tecla;

    jugador->jugador_Nombre[0] = c_ES;
    jugador->jugador_Nombre[1] = c_ES;
    jugador->jugador_Nombre[2] = c_ES;


    while(caracter_Posicion< CARACTERES_JUGADOR){
        gbt_procesar_entrada();
        tecla= gbt_obtener_tecla_presionada();
        gbt_borrar_backbuffer(14);

        dibujar_Palabra_F1(crear_Jugador_Mensaje,15,(VENTANA_ANCHO/2)-(12*15)/2,(VENTANA_ALTO/2)-15*5,1,0,2,3);


        if(tecla== GBTK_ARRIBA){
            if(jugador->jugador_Nombre[caracter_Posicion]==c_ES)
                jugador->jugador_Nombre[caracter_Posicion] =c_A;
            else
                jugador->jugador_Nombre[caracter_Posicion] ++;
        }

        if(tecla== GBTK_ABAJO){
            if(jugador->jugador_Nombre[caracter_Posicion]==c_A)
                jugador->jugador_Nombre[caracter_Posicion] =c_ES;
            else
                jugador->jugador_Nombre[caracter_Posicion] --;
        }

        printf("Nombre: %d %d %d \n", jugador->jugador_Nombre[0],jugador->jugador_Nombre[1],jugador->jugador_Nombre[2]);
        dibujar_Palabra_F1(jugador->jugador_Nombre, CARACTERES_JUGADOR,(VENTANA_ANCHO/2)-(CARACTERES_JUGADOR*12),(VENTANA_ALTO/2)-15*3,1,5,6,7);

        if(tecla== GBTK_ENTER)
            caracter_Posicion ++;

        gbt_volcar_backbuffer();

    }

    return 1;

}

/// Guarda el puntaje en el campo de tJugador a través del puntero que recibe.
    // Va a devolver un 1 en caso de éxito
uint8_t guardar_Puntaje (t_Jugador* jugador, uint16_t puntaje){
    jugador->puntaje= puntaje;
    return 1;
};

/// Crea el vector que contiene los puntajes históricos
    // Devuelve un 1 si el archivo histórico de puntajes no existia. En ese caso guarda en la primera posicion del vector
    // la puntuacion actual
    // Devuelve un 2 si el archivo histórico de puntajes existia. Recorre las primeras 5 posiciones del vector y copia las
    // estructuras de los jugadores anteriores, ubica al jugador actual en la última posicion del vector.
uint8_t crear_Vector_Jugador(t_Jugador v_Ranking[],t_Jugador * jugador){


    FILE* archivo_Ranking;

    archivo_Ranking = fopen("ranking_Jugadores", "rb");

    if(archivo_Ranking ==NULL){
        printf("El ARCHIVO NO EXISTE");
        v_Ranking[0]= *jugador;

        return 1;
    }

    for(uint8_t i=0; i<CANTIDAD_JUGADORES-1; i++){
        fread(&v_Ranking[i], sizeof(t_Jugador),1,archivo_Ranking);
    }
    v_Ranking[CANTIDAD_JUGADORES-1] = *jugador;

    fclose(archivo_Ranking);

    return 2;

}
/// Ordena el vector con los jugadores de mayor a menor
//  Recibe un vector y lo ordena por burbujeo
void ordenar_Vector_Jugador (t_Jugador ranking[]){
    t_Jugador auxiliar;

    for(uint8_t i = 0; i<CANTIDAD_JUGADORES-1;i++){

        for(uint8_t j=0; j<CANTIDAD_JUGADORES-1-i; j++){

            if(ranking[j].puntaje<=ranking[j+1].puntaje){
                auxiliar= ranking[j+1];
                ranking[j+1]=ranking[j];
                ranking[j]= auxiliar;
            }
        }
    }
}

/// Crea el archivo historico de jugadores
// Crea un archivo nuevo, si ya existia lo reescribe
// Recibe el vector con los jugadores y los ordena por puntaje descendente
// Luego los copia al archivo de jugadores.
// Retorna un 1 en caso de exito.
uint8_t crear_Archivo_Jugador(t_Jugador ranking_Jugadores[]){
    FILE* archivo_Ranking;

    archivo_Ranking= fopen("ranking_Jugadores","wb");
        if(archivo_Ranking ==NULL){
        printf("El ARCHIVO NO EXISTE");
        return 0;
    }


    ordenar_Vector_Jugador(ranking_Jugadores);

    for(uint8_t i=0; i<CANTIDAD_JUGADORES-1; i++){
        fwrite(&ranking_Jugadores[i],sizeof(t_Jugador),1,archivo_Ranking);
    }

    fclose(archivo_Ranking);
    return 1;
}



