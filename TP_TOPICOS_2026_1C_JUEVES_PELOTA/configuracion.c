#include "configuracion.h"
#define FILAS 3
#define COLUMNAS 2

uint8_t menu_configuracion_mensaje [18] = {c_M, c_E, c_N, c_U, c_ES, c_C, c_O, c_N, c_F, c_I, c_G, c_U, c_R, c_A, c_C, c_I, c_O, c_N};
uint8_t paleta_mensaje [6] = {c_P, c_A, c_L, c_E, c_T, c_A};
uint8_t resolucion_mensaje [10] ={c_R, c_E, c_S, c_O, c_L, c_U, c_C, c_I, c_O, c_N };
uint8_t velocidad_mensaje [9] = {c_V, c_E, c_L, c_O, c_C, c_I, c_D, c_A, c_D};
uint8_t Pal1_mensaje [5] = {c_C, c_L, c_A, c_R, c_A};
uint8_t Pal2_mensaje [6] = {c_O, c_S, c_C, c_U, c_R, c_A};
uint8_t Res1_mensaje [3] = {c_V, c_G, c_A};
uint8_t Res2_mensaje [3] = {c_C, c_G, c_A};
uint8_t Vel1_mensaje [5] = {c_F, c_A, c_C, c_I, c_L};
uint8_t Vel2_mensaje [7] = {c_D, c_I, c_F, c_I, c_C, c_I, c_L};


uint8_t mostrar_Pantalla_Configuracion(t_Configuracion *config)
{
    bool mat[3] = {0,0,0};
    int fil=0, col=0;

    eGBT_Tecla tecla;
    uint8_t menu=1;
    while(menu)
    {
        gbt_procesar_entrada();
        tecla= gbt_obtener_tecla_presionada();
        gbt_borrar_backbuffer(14);
        ///FALTA CENTRAR
        dibujar_Palabra_F1(menu_configuracion_mensaje,18,(VENTANA_ANCHO/2)-(12*15)/2,(VENTANA_ALTO/2)-15*5,1,0,2,3);
        if(fil==0)
            dibujar_Palabra_F2(paleta_mensaje,6,(VENTANA_ANCHO/6),(VENTANA_ALTO/6)*3,1,6);
        else
            dibujar_Palabra_F2(paleta_mensaje,6,(VENTANA_ANCHO/6),(VENTANA_ALTO/6)*3,1,0);
        if(fil==1)
            dibujar_Palabra_F2(resolucion_mensaje,10,(VENTANA_ANCHO/6),(VENTANA_ALTO/6)*4,1,6);
        else
            dibujar_Palabra_F2(resolucion_mensaje,10,(VENTANA_ANCHO/6),(VENTANA_ALTO/6)*4,1,0);
        if(fil==2)
            dibujar_Palabra_F2(velocidad_mensaje,9,(VENTANA_ANCHO/6),(VENTANA_ALTO/6)*5,1,6);
        else
            dibujar_Palabra_F2(velocidad_mensaje,9,(VENTANA_ANCHO/6),(VENTANA_ALTO/6)*5,1,0);
        //estos if else son para que se vea el color de donde estoy posicionado

        ///Desplazamiento dentro de la matriz mediante teclado de forma ciclica
        if(tecla== GBTK_ARRIBA)
        {
            fil--;
            if(fil<0)
                fil= FILAS-1;
        }
        if(tecla== GBTK_ABAJO)
        {
            fil++;
            if(fil>= FILAS)
                fil=0;
        }
        //revisar para optimizar
        if(tecla== GBTK_IZQUIERDA)
        {
            col--;
            if(col<0)
                col = COLUMNAS-1;
            mat[fil] = col;
        }
        if(tecla== GBTK_DERECHA)
        {
            col++;
            if(col>= COLUMNAS)
                col=0;
            mat[fil] = col;
        }

        if (mat[0] == 0)
            dibujar_Palabra_F2(Pal1_mensaje,5,(VENTANA_ANCHO/6)*3,(VENTANA_ALTO/6)*3,1,0);
        else
            dibujar_Palabra_F2(Pal2_mensaje,6,(VENTANA_ANCHO/6)*3,(VENTANA_ALTO/6)*3,1,0);

        if(mat[1] == 0)
            dibujar_Palabra_F2(Res1_mensaje,3,(VENTANA_ANCHO/6)*3,(VENTANA_ALTO/6)*4,1,0);
        else
            dibujar_Palabra_F2(Res2_mensaje,3,(VENTANA_ANCHO/6)*3,(VENTANA_ALTO/6)*4,1,0);

        if(mat[2] == 0)
            dibujar_Palabra_F2(Vel1_mensaje,5,(VENTANA_ANCHO/6)*3,(VENTANA_ALTO/6)*5,1,0);
        else
            dibujar_Palabra_F2(Vel2_mensaje,7,(VENTANA_ANCHO/6)*3,(VENTANA_ALTO/6)*5,1,0);

        if(tecla== GBTK_ENTER)
            menu=0;

        gbt_volcar_backbuffer();



    }
    actualizarArchConfig(mat);
    return 1;

}

void actualizarArchConfig(bool * mat)
{
    t_Configuracion config_nueva;
    config_nueva.paleta=mat[0];
    config_nueva.resolucion=mat[1];
    config_nueva.velocidad=mat[2];

    FILE * arch=fopen("Configuracion","wb");
    if (arch == NULL) {
        printf("Error: No se pudo crear el archivo\n");
    }

    fwrite(&config_nueva,sizeof(t_Configuracion),1,arch);
}

//void crearArchConfigInicial()
//{
//    t_Configuracion config_inicial;
//    config_inicial.paleta=0;
//    config_inicial.resolucion=0;
//    config_inicial.velocidad=0;
//
//    FILE * arch = fopen("Configuracion","wb");
//    if (arch == NULL) {
//        printf("Error: No se pudo crear el archivo\n");
//    }
//
//    fwrite(&config_inicial,sizeof(t_Configuracion),1,arch);
//}
