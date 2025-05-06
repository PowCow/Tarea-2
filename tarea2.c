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
    char **artista ;
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

void leer_canciones(Map* mapID, Map* mapArtista, Map* mapGenero, long cancionesMax) {
    FILE *archivo = fopen("song_dataset_.csv", "r") ;
    if (archivo == NULL) {
        perror("Error al abrir el archivo") ; 
        return;
    }
  
    char **campos;
    // Leer y parsear una línea del archivo CSV. La función devuelve un array de
    // strings, donde cada elemento representa un campo de la línea CSV procesada.
    campos = leer_linea_csv(archivo, ',') ; // Lee los encabezados del CSV
  
    long k = 0;
    // Lee cada línea del archivo CSV hasta el final
    while ((campos = leer_linea_csv(archivo, ',')) != NULL) {
      
        if (k > cancionesMax) break; //carga primeras n canciones
        Cancion *cancion = malloc(sizeof(Cancion)) ;
        if (cancion == NULL) exit(EXIT_FAILURE) ;
        
        strncpy(cancion->ID, campos[0], sizeof(cancion->ID)) ;
        strncpy(cancion->titulo, campos[4], sizeof(cancion->titulo)) ;
        strncpy(cancion->album, campos[3], sizeof(cancion->album)) ;
        strncpy(cancion->genero, campos[20], sizeof(cancion->genero)) ;
        cancion->artista = split_string(campos[2], ";") ;
        cancion->tempo = atoi(campos[18]) ;
        
        
        List *artistas = split_string(campos[2], ";") ; //separar artistas por ;
        printf("Artistas: \n");
        for(char *artista = list_first(artistas); artista != NULL ; artista = list_next(artistas))
            printf("  %s\n", artista) ;
  
        printf("Album: %s\n", campos[3]) ;
        printf("Genero: %s\n", campos[20]) ;
        printf("Tempo: %.2f\n", atof(campos[18])) ;
        printf(" -------------------------------\n") ;
  
        k++;
    }
    fclose(archivo); 
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
