#include "tarea2_lecturacsv.c"
#include "TDAS/extra.h"
#include "TDAS/list.h"
#include "TDAs/map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrarMenuPrincipal() {
    system("cls||clear") ;
    puts("========================================") ;
    puts("     Base de Datos de Canciones") ;
    puts("========================================");
  
    puts("1) Cargar Canciones") ;
    puts("2) Buscar por Genero") ;
    puts("3) Buscar por Artista") ;
    puts("4) Buscar por Tempo") ;
    puts("5) Crear lista de reproduccion") ;
    puts("6) Agregar cancion a lista de reproduccion") ;
    puts("7) Mostrar lista de reproduccion") ;
    puts("8) Salir") ;
}


int main() {
    leer_canciones();
    unsigned short opcion ;
    
    do{
        mostrarMenu() ;
        scanf("%hu", &opcion) ;
    
        switch (opcion) {
            case 1:
                //pendejada
                break ;
            case 2:
                //pendejada
                break ;
            case 3:
                //pendejada
                break ;
            case 4:
                //pendejada
                break ;
            case 5:
                //pendejada
                break ;
            case 6:
                //pendejada
                break ;
            case 7:
                //pendejada
                break ;
            case 8:
                //pendejada
                break ;
            default:
                system("cls||clear") ;
                printf("Opcion no valida, intente nuevamennte...\n") ;
                getchar() ;
                break ;
        }
    } while (opcion != 8) ;
    return EXIT_SUCCESS;
}
