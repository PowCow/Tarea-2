#include "TDAs/extra.h"
#include "TDAs/list.h"
#include "TDAs/map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { 
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


// Procedimiento para mostrar el menu principal
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

/* Abre el archivo  y retorna en caso de error, con la funcion leer_linea_csv() lee una linea 
del csv que es una cancion y la guarda en el struct Cancion, luego la inserta con un push back
en los distintos mapas, esto se repite el numero de veces que el usuario indico, osea carga 
n canciones */
void leer_canciones(Map* mapID, Map* mapArtista, Map* mapGenero, long cancionesMax) { //LISTO
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

/* Funcion para poder crear un mapa vacio */
int is_equal_str(void *key1, void *key2) { 
    return strcmp((char *)key1, (char *)key2) == 0; 
}
/* Funcion para poder crear un mapa vacio */
int is_equal_int(void *key1, void *key2) {
    return *(int *)key1 == *(int *)key2; 
}

/* Muestra un menu, lee el genero que ingresa el usuario, si es mapa es nulo retorna, si el genero no existe retorna,
en cualquier otro caso ingresa al mapa del genero e imprime todas sus canciones con su respectiva informacion */
void busquedaGenero(Map *cancionesGenero) { //LISTO
    puts("=========================================") ;
    puts("         BUSQUEDA POR GENERO") ; 
    puts("=========================================") ;
    printf("\nIngrese el nombre del genero: \n") ;

    char genero[100] ;
    fgets (genero, sizeof(genero), stdin) ;
    genero[strcspn(genero, "\n")] = '\0' ; 
    
    if (cancionesGenero == NULL) {
        printf("No hay canciones en registro\n") ;
        return ;
    } 

    MapPair *par = map_search(cancionesGenero, genero) ;
    if (par == NULL) {
        printf("No se encontraron canciones del genero: %s\n", genero) ;
        return ;
    } 
    else {
        printf("Canciones del genero %s:\n\n", genero) ;
        List *canciones = (List *)par->value ;
        Cancion *cancion = list_first(canciones) ;
        long cont = 1;
        
        while (cancion != NULL) {
            printf("Cancion %ld\n", cont) ;
            printf("ID: %s\n", cancion->ID) ;
            printf("Titulo: %s\n", cancion->titulo) ;
            printf("Album: %s\n", cancion->album) ;

            printf("Artistas: ");
            
            char *artista = list_first(cancion->artista) ;
            while (artista != NULL) {
                printf("%s", artista) ;
                artista = list_next(cancion->artista) ;
                if (artista != NULL) {
                    printf(" - ") ;
                }
            }
            printf("\nTempo: %d BPM\n\n", cancion->tempo) ;
            
            cancion = list_next(canciones) ;
            cont++;
            puts("------------------------------------------\n") ;
        }
    }
}

/* Muestra un menu inicial, lee el artista que ingresa el usuario, verifica si el mapa es nulo, verifica si el artista esta 
en el mapa, si esta en el mapa, muestra un mensaje respecto al artista y muestra las canciones de ese artista */
void busquedaArtista(Map *cancionesArtista) { //LISTO 
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
        printf("No se encontraron canciones del artista: %s\n", artista) ;
        return ;
    } 
    else {
        printf("Canciones del artista %s:\n\n", artista) ;
        List *canciones = (List *)par->value ;
        Cancion *cancion = list_first(canciones) ;
        long cont = 1;
        while (cancion != NULL) {
            printf("Cancion %ld\n", cont) ;
            printf("ID: %s\n", cancion->ID) ;
            printf("Titulo: %s\n", cancion->titulo) ;
            printf("Album: %s\n", cancion->album) ;
            printf("Genero: %s\n", cancion->genero) ;
            printf("Tempo: %d BPM\n\n", cancion->tempo) ;
            
            cancion = list_next(canciones) ;
            cont++;
            puts("------------------------------------------\n") ;
        }
    }
    
}

/* Funcion para mostrar los datos de la cancion y ahorarnos lineas */
void mostrarCancion(Cancion *cancion, int cont) {
    printf("Cancion %ld\n", cont) ;
    printf("ID: %s\n", cancion->ID) ;
    printf("Titulo: %s\n", cancion->titulo) ;
    printf("Album: %s\n", cancion->album) ;
    printf("Artistas: ");
    char *artista = list_first(cancion->artista);
    while (artista != NULL) {
        printf("%s", artista);
        artista = list_next(cancion->artista);
        if (artista != NULL) {
            printf(" - ");
        }
    }
        printf("\nGenero: %s\n", cancion->genero) ;
        printf("Tempo: %d BPM\n\n", cancion->tempo) ;
    puts("------------------------------------------\n") ;
}

/* Muestra un menu, donde el usuario ingresa la opcion deseada, si no esta dentro de las posibilidades, se retorna.
Verifica que el mapa de IDs exista, luego imprime las canciones que entren en las condiciones especificadas */
void busquedaTempo(Map *cancionesID) { //LISTO
    puts("=========================================") ;
    puts("         BUSQUEDA POR TEMPO") ; 
    puts("=========================================") ;
    printf("\nIngrese una opcion de tempo: \n") ;
    printf("1) Lentas (Tempo menos de 80 BPM)\n") ;
    printf("2) Moderadas (Tempo entre 80 y 120 BPM)\n") ;
    printf("3) Rapidas (Tempo mayor a 120 BPM)\n") ;
    unsigned short tempo ;
    scanf("%hu", &tempo) ;
    getchar() ;

    if (cancionesID == NULL) {
        printf("No hay canciones en registro\n") ;
        return ;}

    if (tempo == 1) 
        puts(" ======CANCIONES LENTAS====== \n") ; 
    else if (tempo == 2) 
        puts(" ======CANCIONES MODERADAS====== \n") ;	 
    else if (tempo == 3) 
        puts(" ======CANCIONES RAPIDAS====== \n") ; 
    
        
    MapPair *pair = map_first(cancionesID) ;
    long cont = 1;
    while (pair != NULL) {
        Cancion *cancion = (Cancion*)pair->value ;
        int tempoCancion = cancion->tempo;
        switch (tempo) {
            case 1:
                if (tempoCancion >= 0 && tempoCancion < 80) {
                    mostrarCancion(cancion, cont) ;
                    cont++;
                }
                break ;
            case 2:
                if (tempoCancion >= 80 && tempoCancion <= 120) {
                    mostrarCancion(cancion, cont) ;
                    cont++;
                }
                break ;
            case 3:
                if (tempoCancion > 120) {
                    mostrarCancion(cancion, cont) ;
                    cont++;
                }
                break ;
            default:
                puts("Opcion de tempo no valida.");
                return ;
            
        }
        pair = map_next(cancionesID) ;
    }
}

/* Muestra un menu inicial, lee el nombre de la playlist que ingresa el usuario, reserva memoria y crea una lista,
luego busca en el mapa de listas si existe, si no existe, se ingresa exitosamente */
void crear_ListaReproduccion(Map *mapPlaylist) { //LISTO
    puts("=========================================") ;
    puts("         CREAR LISTA DE REPRODUCCION") ; 
    puts("=========================================") ;
    printf("\nIngrese el nombre de la lista de reproduccion: \n") ;

    char nombrePlaylist[100] ;
    fgets(nombrePlaylist, sizeof(nombrePlaylist), stdin) ;
    nombrePlaylist[strcspn(nombrePlaylist, "\n")] = '\0' ; 

    Playlist *playlist = malloc(sizeof(Playlist)) ;
    if (playlist == NULL) {
        puts("Error al crear la lista de reproduccion") ;
        exit(EXIT_FAILURE) ;}

    playlist->canciones = list_create() ;
    strncpy(playlist->nombrePlaylist, nombrePlaylist, sizeof(playlist->nombrePlaylist)) ;

    MapPair *par = map_search(mapPlaylist, playlist->nombrePlaylist) ;
    if (par != NULL) {
        printf("Ya existe una lista de reproduccion con ese nombre\n") ;
        return ;
    }
    else {
        map_insert(mapPlaylist, playlist->nombrePlaylist, playlist) ;
    }
    printf("Lista de reproduccion %s creada con exito!\n", playlist->nombrePlaylist) ;
}

/* Muestra un menu inicial, lee el nombre de la playlist ingresado por el usuario y verifica si existe,
luego debe el usuario ingresar la ID de la cancion a agregar, si no existe lo especifica y retorna,
si existe avisa, verifica si la cancion ya esta en la playlist, si no esta la agrega existosamente */
void agregar_cancion_ListaReproduccion(Map *mapPlaylist, Map *cancionesID) { //LISTO
    puts("=========================================") ;
    puts("         AGREGAR CANCION A PLAYLIST") ;
    puts("=========================================") ;
    printf("\nIngrese el nombre de la lista de reproduccion: \n") ;
    
    char nombrePlaylist[100] ;
    fgets(nombrePlaylist, sizeof(nombrePlaylist), stdin) ;
    nombrePlaylist[strcspn(nombrePlaylist, "\n")] = '\0' ;
    MapPair *par = map_search(mapPlaylist, nombrePlaylist) ;

    if (par == NULL) {
        printf("No existe una lista de reproduccion con ese nombre\n") ;
        return ;
    }
    else {
        puts("Lista de reproduccion encontrada!") ;
        printf("Ingrese el ID de la cancion a agregar: \n") ;
        char ID[100] ;
        fgets(ID, sizeof(ID), stdin) ;
        ID[strcspn(ID, "\n")] = '\0' ;
        
        MapPair *parCancion = map_search(cancionesID, ID) ;
        if (parCancion == NULL) {
            puts("No se encontro una cancion con ese ID") ;
            return ;
        }
        
        puts("Cancion encontrada!") ;
        Cancion *cancion = (Cancion*)parCancion->value ;
        Playlist *playlist = (Playlist*)par->value ;

        List *cancionesPlaylist = playlist->canciones ;
        Cancion *cancionExistente = list_first(cancionesPlaylist) ;
        while (cancionExistente != NULL) {
            if (strcmp(cancion->ID, cancionExistente->ID) == 0) {
                printf("La cancion '%s' ya existe en la lista de reproduccion\n", cancion->titulo) ;
                return ;
            }
            cancionExistente = list_next(cancionesPlaylist) ;
        }
        list_pushBack(cancionesPlaylist, cancion) ;
        printf("Cancion '%s' ha sido agregada a la lista de reproduccion %s\n", cancion->titulo, playlist->nombrePlaylist) ;
    }
}

/* Muestra un menu inicial, y lee el nombre de la playlist ingresado por el ususario, si no existe retorna,
en caso de existir lo especifica, si la playlist esta vacia tambien lo especifica, de otra forma muestra 
las canciones de la playlist en orden de ingreso */
void mostrar_canciones_ListaReproduccion(Map *mapPlaylist) {
    puts("=========================================") ;
    puts("     MOSTRAR CANCIONES DE PLAYLIST") ;
    puts("=========================================") ;
    printf("\nIngrese el nombre de la lista de reproduccion: \n") ;
    
    char nombrePlaylist[100] ;
    fgets(nombrePlaylist, sizeof(nombrePlaylist), stdin) ;
    nombrePlaylist[strcspn(nombrePlaylist, "\n")] = '\0' ;
    MapPair *par = map_search(mapPlaylist, nombrePlaylist) ;

    if (par == NULL) {
        printf("No existe una lista de reproduccion con ese nombre\n") ;
        return ;
    }
    
    puts("Lista de reproduccion encontrada!") ;
    Playlist *playlist = (Playlist*)par->value ;
    List *cancionesPlaylist = (List*)playlist->canciones ;
    Cancion *cancion = list_first(cancionesPlaylist) ;
    
    if (cancionesPlaylist == NULL || cancion == NULL) {
        printf("No hay canciones en la lista de reproduccion %s\n", playlist->nombrePlaylist) ;
        return ;
    }
    else {
        printf("Canciones de la lista de reproduccion %s:\n\n", playlist->nombrePlaylist) ;
        long cont = 1 ;
        while (cancion != NULL) {
            mostrarCancion(cancion, cont) ;
            cancion = list_next(cancionesPlaylist) ;
            cont++;
        }
    }
}

/* */
void limpiarCanciones(List *canciones) {
    Cancion *cancion = list_first(canciones) ;
    while (cancion != NULL) {
        list_clean(cancion->artista) ;
        free(cancion) ;
        cancion = list_next(canciones) ;
    }
    list_clean(canciones) ;
}

/* Abre el archivo  y retorna en caso de error, con la funcion leer_linea_csv() lee el csv

*/
void limpiarMapa(Map *map) {
    MapPair *pair = map_first(map) ;
    while (pair != NULL) {
        List *canciones = (List*)pair->value ;
        limpiarCanciones(canciones) ;
        pair = map_next(map) ;
    }
    map_clean(map) ;
}

/* Abre el archivo  y retorna en caso de error, con la funcion leer_linea_csv() lee el csv

*/
void limpiarMapaID(Map *map) {
    MapPair *pair = map_first(map) ;
    while (pair != NULL) {
        Cancion *cancion = (Cancion*)pair->value ;
        list_clean(cancion->artista) ;
        free(cancion) ;
        pair = map_next(map) ;
    }
    map_clean(map) ;
}

/* Abre el archivo  y retorna en caso de error, con la funcion leer_linea_csv() lee el csv

*/
void limpiarTodo(Map *mapID, Map *mapArtista, Map *mapGenero, Map *mapPlaylist) {
    limpiarMapaID(mapID) ;
    limpiarMapa(mapArtista) ;
    limpiarMapa(mapGenero) ;
    limpiarMapa(mapPlaylist) ;
}

/* Abre el archivo  y retorna en caso de error, con la funcion leer_linea_csv() lee el csv

*/
int main() {
    Map *cancionesID = map_create(is_equal_str) ;
    Map *cancionesArtista = map_create(is_equal_str) ;
    Map *cancionesGenero = map_create(is_equal_str) ;
    Map *mapPlaylist = map_create(is_equal_str) ;

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
                system("cls||clear") ;
                busquedaGenero(cancionesGenero) ;
                break ;
            case 3:
                system("cls||clear") ;
                busquedaArtista(cancionesArtista) ;
                break ;
            case 4:
                system("cls||clear") ;
                busquedaTempo(cancionesID) ;
                break ;
            case 5:
                system("cls||clear") ;
                crear_ListaReproduccion(mapPlaylist) ;
                break ;
            case 6:
                system("cls||clear") ;
                agregar_cancion_ListaReproduccion(mapPlaylist, cancionesID) ;
                break ;
            case 7:
                system("cls||clear") ;
                mostrar_canciones_ListaReproduccion(mapPlaylist) ;
                break ;
            case 8: //Opcion para salir
                system("cls||clear") ;
                break;
            default:
                system("cls||clear") ;
                printf("Opcion no valida, intente nuevamente...\n") ;
                getchar() ;
                break ;
        }
    } while (opcion != 8) ;

    limpiarTodo(cancionesID, cancionesArtista, cancionesGenero, mapPlaylist) ;
    return EXIT_SUCCESS;
}
