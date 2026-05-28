#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <stdio.h>
#include <stdint.h>

#include "GBT/gbt.h"
#include "caracteres.h"
#include "dibujos.h"
#include "movimiento.h"

#define CARACTERES_JUGADOR 3
#define CANTIDAD_JUGADORES 6

/*Este apartado crea un struct del tipo jugador que contendra los campos de nombre y puntaje
    Tambien incluye:
            - Pantalla donde se ingresa nombre de jugador
            - Guardar puntaje de jugador
            - Guardar archivo de jugador historico
*/

typedef struct{
    uint8_t jugador_Nombre[CARACTERES_JUGADOR];
    uint16_t puntaje;
} t_Jugador;

extern t_Jugador ranking_Jugadores[CANTIDAD_JUGADORES];

uint8_t mostrar_Pantalla_Crear_Jugador(t_Jugador *jugador);

uint8_t seleccionar_Caracter();

    // Va a devolver un 1 en caso de éxito
uint8_t guardar_Puntaje (t_Jugador *, uint16_t);

///Crea el vector con las estructuras de los jugadores
    //Si no existe el archivo de puntajes, lo crea y pone al jugador actual
    //Si existe el archivo lo copia al vector e introduce al jugador actual en el último lugar
    //Recibe un array de estructura de jugadores y un puntero de la estructura del jugador actual
    //Retorna 1 si no existia el archivo, un 2 si el archivo ya existia
uint8_t crear_Vector_Jugador(t_Jugador [],t_Jugador *);

/// Crea el archivo de jugadores
    //Toma el array de jugadores, lo ordena por puntajes y lo copia en el archivo de ranking
    //Solamente escribe los primeros 5 lugares
    //Elimina el archivo que recibe y copia el nuevo
    //Recibe el vector de estructura de jugadores
    //Retorna un 1 si el archivo se creo
uint8_t crear_Archivo_Jugador(t_Jugador []);

///Ordena el vector de jugadores
    //Recibe el vector de jugadores y lo ordena por puntaje descendentes
void ordenar_Vector_Jugador (t_Jugador[]);





#endif // JUGADOR_H_INCLUDED
