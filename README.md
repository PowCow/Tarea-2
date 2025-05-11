# Tarea-2

# SPOTIFIND : Buscador de canciones personalizado
DESCRIPCION 

SpotiFind es una aplicacion de consola que permite explorar una base de datos musical y buscar canciones segun distintos criterios: genero, artista o tempo (velocidad de la cancion). Tambien permite cargar canciones desde un archivo CSV y organizar musica de manera eficiente. 

1. Como compilar y ejecutar :
    

        gcc tarea2.c TDAs/*.c -o tarea2.exe

        ./tarea2

2. Opciones que funcionan correctamente y las que no (posibles causas) :
    - Funcionando Correctamente :
       * Funcion para agregar el archivo .CSV y la carga de canciones
       * El Menu se muestra correctamente
       * Funcion de Busqueda por Genero, se ingresa el genero, se busca si existe y si contiene canciones, si existen canciones con ese genero, se muestran con sus datos
       * Funcion de Busqueda por Artista, se ingresa el nombre del artista, se busca si existe el artista y si tiene canciones con su nombre, si existe, se muestran las canciones con el resto de datos
       * Funcion de Busqueda por Tempo, se ingresa el tempo segun preferencia, lenta, moderada o rapida, se busca si existen canciones ingresadas con ese tempo y se muestran los datos de las canciones
       * Funcion "Crear lista de Reproduccion", 

    - Problemas Conocidos :
       * Al agregar mayor cantidad de canciones, mas demora al cargar.
       * Si quiero agregar la cancion "ID 20000" tengo que cargar 20000 canciones de una, no se suman las cargas
       * 
   
4. Ejemplo de interaccion con la aplicacion :
    
   
5. Contribucion de cada integrante :


