        /*
        //Dibujar en el backbuffer los pixeles del color que dice mi matriz
        for (uint16_t y = 0; y < 14; y++) {
            for (uint16_t x = 0; x < 9; x++) {

                    if(honguito_Magenta[y][x] == X){
                        honguito_Magenta[y][x] = color;
                    }
                gbt_dibujar_pixel(offsetX + x, offsetY + y, honguito_Magenta[y][x]);
            }
        }

        //Offset mas corrimiento
        offsetX += VEL;
        //Control de desborde para reinicar secuencia
        if (offsetX > 128){
            offsetX = 0;
        }

        */
        /*
        dibujar_mino(50, 50, Mino_T, Tc,Tb);
        dibujar_mino(50, 55, Mino_T, Ic, Ib);
        dibujar_mino(50, 60, Mino_T, Lc, Lb);
        dibujar_mino(50, 65, Mino_T, Zc, Zb);
        */

        /*
        //Dibujar la puta T de mierda
        for(uint16_t i = 0; i<LADO_PIEZA; i++){
            for(uint16_t j = 0; j<LADO_PIEZA; j++){
               if (pieza_T[3][j][i] == true){
                    dibujar_mino(50 + (i*5), 50 + (j*5), Mino_T, Tc,Tb);
               } //cero es la pieza a cero grados
            }
        }
        */

        /*

        //Generar una pieza en una coordenada fija (Centro de la grilla de juego)
        dibujar_Pieza(pieza_J, 50, 50, rotacion,Sc, Sb);

        dibujar_Pieza(pieza_L, 50, 100, rotacion,Sc, Sb);

        dibujar_Pieza(pieza_I, 50, 150, rotacion,Sc, Sb);

        dibujar_Pieza(pieza_O, 100, 50, rotacion,Sc, Sb);

        dibujar_Pieza(pieza_S, 100, 100, rotacion,Sc, Sb);

        dibujar_Pieza(pieza_Z, 100, 150, rotacion,Sc, Sb);


                rotacion ++;

        if (rotacion > 3 || rotacion < 0){
            rotacion = 0;
        }
        }*/


                /*
        //Verifica el nivel actual y eso da la frecuencia con la que actualiza el cambio de posicion de la pieza
        if (contador_Frames >= tabla_Niveles[nivel_1]){
            contador_Frames = 0;
            coord_Y_Inicio_1 += 10;
        }
        dibujar_Pieza(pieza_L, coord_X_Inicio_1,coord_Y_Inicio_1, rotacion,Sc, Sb);

        if (contador_Frames_2 >= tabla_Niveles[nivel_2]) {
            contador_Frames_2 = 0;
            coord_Y_Inicio_2 += 10;
        }
        dibujar_Pieza(pieza_I, coord_X_Inicio_2,coord_Y_Inicio_2, rotacion,Sc, Sb);

        //La pieza se mueve 10 veces x seg
        if (contador_Frames_3 >= tabla_Niveles[nivel_3]) {
            contador_Frames_3 = 0;
            coord_Y_Inicio_3 += 10;
        }
        dibujar_Pieza(pieza_J, coord_X_Inicio_3,coord_Y_Inicio_3, rotacion,Sc, Sb);

        //nomas controla el desborde de la pantalla en y para empezar de nuevo la caida
        if (coord_Y_Inicio_1 >= 480){
            coord_Y_Inicio_1 = 0;
        }
        if (coord_Y_Inicio_2 >= 480){
            coord_Y_Inicio_2 = 0;
        }
        if (coord_Y_Inicio_3 >= 480){
            coord_Y_Inicio_3 = 0;
        }
        */

