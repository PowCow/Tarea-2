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
    List *artista ;
    char genero[100] ;
    int tempo; 
} Cancion;

typedef struct {
    List *canciones ;
    char nombrePlaylist[100] ;
} Playlist;

void mostrarMenuPrincipal() { //LISTO

    puts("========================================") ;
    puts("              SPOTIFIND") ;
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
      
        if (k >= cancionesMax) break; //carga primeras n canciones
        Cancion *cancion = malloc(sizeof(Cancion)) ;
        if (cancion == NULL) exit(EXIT_FAILURE) ;
        
        strncpy(cancion->ID, campos[0], sizeof(cancion->ID)) ;
        strncpy(cancion->titulo, campos[4], sizeof(cancion->titulo)) ;
        strncpy(cancion->album, campos[3], sizeof(cancion->album)) ;
        strncpy(cancion->genero, campos[20], sizeof(cancion->genero)) ;
        cancion->tempo = atoi(campos[18]) ;
        cancion->artista = split_string(campos[2], ";") ;

        map_insert(mapID, cancion->ID, cancion) ; // Insertar en el mapa por ID

        for (char *artista = list_first(cancion->artista); artista != NULL; artista = list_next(cancion->artista)) {
            MapPair *artistaPar = map_search(mapArtista, artista) ;
            if (artistaPar == NULL) {
                List *listaArtista = list_create() ;
                list_pushBack(listaArtista, cancion) ;
                map_insert(mapArtista, artista, listaArtista) ;
            }
            else {
                List *listaArtista = (List*)    artistaPar->value ;
                list_pushBack(listaArtista, cancion) ;
            }
        }
        
        MapPair *generoPar = map_search(mapGenero, cancion->genero) ;
        List *listaGenero = generoPar ? (List*)generoPar->value : NULL ;
        if (generoPar == NULL) {
            List *listaGenero = list_create();
            list_pushBack(listaGenero, cancion) ;
            map_insert(mapGenero, cancion->genero, listaGenero);
        }
        else {
            List *listaGenero = (List*)generoPar->value ;
            list_pushBack(listaGenero, cancion);
        }
        k++;
    }
    fclose(archivo); 
}

int is_equal_str(void *key1, void *key2) { 
    return strcmp((char *)key1, (char *)key2) == 0; 
}

int is_equal_int(void *key1, void *key2) {
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
    puts("=========================================") ;
    puts("         BUSQUEDA POR ARTISTA") ; 
    puts("=========================================") ;
    printf("\nIngrese el nombre del artista: \n") ;

    char artista[100] ;
    fgets (artista, sizeof(artista), stdin) ;
    artista[strcspn(artista, "\n")] = '\0' ; 
    
    if (cancionesArtista == NULL) {
        printf("No hay canciones en registro\n") ;
        return ;
    } 
    
    MapPair *par = map_search(cancionesArtista, artista) ;
    if (par == NULL) {
        printf("No se encontraron canciones de %s\n", artista) ;
        return ;
    } 
    else {
        List *canciones = (List *)par->value ;
        Cancion *cancion = list_first(canciones) ;
        while (cancion != NULL) {
            printf("ID: %s | Titulo: %s | Album: %s | Genero: %s | Tempo: %d BPM\n", 
                cancion->ID, cancion->titulo, cancion->album, cancion->genero, cancion->tempo) ;
            cancion = list_next(canciones) ;
        }
    }

}

//void busquedaTempo( ){
    /*la usuaria ingresa "velocidad" - lentas (tempo menos de 80 BPM),
    -moderadas (tempo entre 80 y 120 BPM) y -rapidas (tempo más de 120 BPM)*/
    /* La aplicación muestra todas las canciones que coincidan con la información de cada una.*/
//}

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
                //busquedaGenero(cancionesGenero) ;
                break ;
            case 3:
                busquedaArtista(cancionesArtista) ;
                break ;
            case 4:
                //busquedaTempo() ;
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
