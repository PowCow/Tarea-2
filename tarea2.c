#include "TDAs/tarea2_lecturacsv.h"
#include "TDAs/extra.h"
#include "TDAs/list.h"
#include "TDAs/map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //wao wao wao wao
    char ID[100] ;
    char titulo[100] ;
    char album[100] ;
    char artista[100] ;
    char genero[100] ;
    int tempo; 
} Cancion;

typedef struct {
    List *canciones ;
    char nombrePlaylist[100] ;
} Playlist;

void mostrarMenuPrincipal() { //LISTO
    puts("========================================") ;
    puts("     Base de Datos de Canciones") ;
    puts("========================================");
    puts("1) Cargar Canciones") ;
    puts("2) Buscar por Genero") ;
    puts("3) Buscar por Artista") ;
    puts("4) Buscar por Tempo") ;
    puts("5) Crear lista de reproduccion") ;
    puts("6) Agregar cancion a lista de reproduccion") ;
    puts("7) Mostrar canciones de una lista de reproduccion") ;
    puts("8) Salir") ;

}

int is_equal_str(const void *key1, const void *key2) { 
    return strcmp((char *)key1, (char *)key2) == 0; 
}
    
int is_equal_int(const void *key1, const void *key2) {
    return *(int *)key1 == *(int *)key2; 
}

void busquedaGenero(Map *cancionesGenero) { 
    /* La usuaria ingresa un género (p. ej. “acoustic”, “samba”, “soul”, “anime”) 
    y la aplicación muestra todas las canciones que coincidan con la información de
    cada una.*/
}

void busquedaArtista(Map *cancionesArtista) {
    /* La usuaria ingresa el nombre de un artista y la aplicación muestra todas las canciones 
    que coincidan con la información de cada una.*/
}

void busquedaTempo( ){
    /*la usuaria ingresa "velocidad" - lentas (tempo menos de 80 BPM),
    -moderadas (tempo entre 80 y 120 BPM) y -rapidas (tempo más de 120 BPM)*/
    /* La aplicación muestra todas las canciones que coincidan con la información de cada una.*/
}

int main() {
    Map *cancionesID = map_create(is_equal_str) ;
    Map *cancionesArtista = map_create(is_equal_str) ;
    Map *cancionesGenero = map_create(is_equal_str) ;


    leer_canciones(cancionesID, cancionesArtista, cancionesGenero);
    unsigned short opcion ;
    long cancionesCargadas = 0 ;
    
    do {
        mostrarMenuPrincipal() ;
        scanf("%hu", &opcion) ;
        getchar() ;
    
        switch (opcion) {
            case 1: 
                system("cls||clear") ;
                printf("Seleccione cuantas canciones desea cargar (maximo = 113998):\n") ;
                scanf("%ld", &cancionesCargadas) ;
                getchar() ;
                printf("Cargando canciones...\n") ;
                leer_canciones(cancionesID, cancionesArtista, cancionesGenero, cancionesCargadas) ;
                break;
            case 2:
                busquedaGenero(cancionesGenero) ;
                break ;
            case 3:
                busquedaArtista(cancionesArtista) ;
                break ;
            case 4:
                busquedaTempo() ;
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
                printf("Opcion no valida, intente nuevamente...\n") ;
                getchar() ;
                break ;
        }
    } while (opcion != 8) ;
    return EXIT_SUCCESS;
}
