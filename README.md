# Tarea 2

# SPOTIFIND : Buscador de canciones personalizado
DESCRIPCIÓN

SpotiFind es una aplicación de que se carga en la termina que permite explorar una base de datos musical y buscar canciones según distintos criterios: género, artista o tempo (velocidad de la canción). Para poder hacer esto, la aplicación carga un gran volumen de canciones con su respectiva información desde un archivo .CSV.  Una de las funcionalidades destacadas yace en la capacidad de crear listas de reproducciones personalizadas, pudiendo así organizarlas por preferencia.

1. Como ejecutar el programa:
   Para ejecutar el programa deberás descargar el archivo .rar de el siguiente link: https://www.mediafire.com/file/iqfqj67guowuup5/programa.rar/file
   Luego tendrás que extraer los archivos del .rar haciendo click derecho en el y seleccionar la opción: Extraer en "programa\". A continuación te dejará una carpeta con ambos archivos en
   su interior, unicamente hará falta ejecutar el archivo "tarea2.exe".

   * Requisitos previos:
      - Tener WinRar instalado, si no lo tienes, este es el link de la página para instalarlo: https://winrar.es/descargas
      - Sistema operativo: Windows. Debido a falta de pruebas, no hemos podido determinar si funciona en el sistema macOS
   
3. Opciones que funcionan correctamente y las que no (posibles causas) :
    - Funcionando Correctamente :
       * Funcion para agregar el archivo .CSV y la carga de canciones
       * El Menu se muestra correctamente
       * Funcion de Busqueda por Genero, se ingresa el genero, se busca si existe y si contiene canciones, si existen canciones con ese genero, se muestran con sus datos
       * Funcion de Busqueda por Artista, se ingresa el nombre del artista, se busca si existe el artista y si tiene canciones con su nombre, si existe, se muestran las canciones con el resto de datos
       * Funcion de Busqueda por Tempo, se ingresa el tempo segun preferencia, lenta, moderada o rapida, se busca si existen canciones ingresadas con ese tempo y se muestran los datos de las canciones
       * Funcion "Crear lista de Reproduccion", el usuario ingresa el nombre de la nueva lista de reproduccion, esta se guarda en la memoria y muestra al usuario si ya existia una lista con ese nombre o si hubo un error al crear la lista
       * Funcion "Agregar Cancion a lista de Reproduccion", pregunta por el nombre de la lista pra verificar si ya esta creada, si no existe se avisa al usuario, si existe, pide al usuario el ID de la cancion a agregar, si no existe la cancion, se avisa a usuario, si ya estaba en la lista, tambien se avisa a usuario, si no estaba, muestra al usuario que se ha agregado correctamente
       * Funcion Mostrar Cancion de una Playlist, se le pregunta al usuario el nombre de la playlist, la funcion busca y muestra todas las canciones que se han agregado
       * Al Salir del menu, limpia toda la memoria reservada

    - Problemas Conocidos :
       * Al agregar mayor cantidad de canciones, mas demora al cargar.
       * Si quiero agregar la cancion "ID 20000" tengo que cargar 20000 canciones de una, no se suman las cargas
       * Al escribir letras en la zona de carga de canciones (opcion 1) no salta error, aunque igualmente no carga ningun tipo de cancion
       * Al ingresar alguna letra o simbolo en las opciones del menu, este regresa a la opcion anterior antes de llegar al menu, siendo que ya habia terminado la ejecucion de esa opcion
       * Al ingresar el nombre de un artista se debe ingresar correctamente, con una letra mayuscula al inicio de cada nombre (ej: B.B King)
       * Todos los generos deben ser escritos en miniscula, no detecta genero escrito con una letra mayuscula o mayuscula total
         (ej: blues ✓ Blues ✗ BLUES ✗)
   
4. Ejemplo de interaccion con la aplicacion :
    1. Al abrir el programa:
       
               ========================================
                             SPOTIFIND
               ========================================
               1) Cargar Canciones
               2) Buscar por Genero
               3) Buscar por Artista
               4) Buscar por Tempo
               5) Crear lista de reproduccion
               6) Agregar cancion a lista de reproduccion
               7) Mostrar canciones de una lista de reproduccion
               8) Salir

   2. Cargar canciones: Opción seleccionada (1)
      
            Seleccione cuantas canciones desea cargar (maximo = 113998):

   Ingresamos: 20000
   
   Nos muestra lo siguiente:

         Cargando canciones...

   Luego nos devuelve al menú principal

   3.  Buscar por genero: Opción seleccionada (2)
      
               =========================================
                        BUSQUEDA POR GENERO
               =========================================
               
               Ingrese el nombre del genero:
   Ingresamos: blues
   
   En este caso cargan 1000 canciones, pero mostramos en el ejemplo las 3 últimas:

         Cancion 998
         ID: 8997
         Titulo: Don't Let Me Be Misunderstood
         Album: Remnant From The Ashes The Ultimate Fantasy Playlist
         Artistas: Eric Burdon
         Tempo: 113 BPM
         
         ------------------------------------------
         
         Cancion 999
         ID: 8998
         Titulo: Don't Let Me Be Misunderstood
         Album: Disciples Liberation The Ultimate Fantasy Playlist
         Artistas: Eric Burdon
         Tempo: 113 BPM
         
         ------------------------------------------
         
         Cancion 1000
         ID: 8999
         Titulo: Sempre Brilhar├í - Ao Vivo
         Album: Quem Foi Que Falou Que Acabou o Rock'N Roll? (Ao Vivo)
         Artistas: Celso Blues Boy
         Tempo: 100 BPM
         
         ------------------------------------------

   Luego nos devuelve al menú principal 

   4. Buscar por artista: Opción seleccionada (3)
      
            =========================================
                     BUSQUEDA POR ARTISTA
            =========================================
            
            Ingrese el nombre del artista:
   Ingresamos: B.B. King
   
   Y nos muestra:

         Canciones del artista B.B. King:

         Cancion 1
         ID: 8157
         Titulo: Please Come Home For Christmas - Album Version / Addtl. Strings
         Album: Christmas Eve At Home
         Genero: blues
         Tempo: 96 BPM
         
         ------------------------------------------
         
         Cancion 2
         ID: 8185
         Titulo: Please Come Home For Christmas
         Album: Home For Christmas 2022
         Genero: blues
         Tempo: 96 BPM
         
         ------------------------------------------
         
         Cancion 3
         ID: 8187
         Titulo: Back Door Santa
         Album: pov: you ride on santa's sleigh
         Genero: blues
         Tempo: 112 BPM
         
         ------------------------------------------

   Luego de mostrar todas las canciones del artista nos devuelve al menú principal

   5.  Buscar por tempo: Opción seleccionada (4)
   
            =========================================
                     BUSQUEDA POR TEMPO
            =========================================
            
            Ingrese una opcion de tempo:
            1) Lentas (Tempo menos de 80 BPM)
            2) Moderadas (Tempo entre 80 y 120 BPM)
            3) Rapidas (Tempo mayor a 120 BPM)

   Ingresamos: 3
   
   Nos muestran todas las canciones correspondientes a ese tempo:

         Cancion 9845
         ID: 19996
         Titulo: Gin ├á l'eau sal├®e
         Album: Gin ├á l'eau sal├®e
         Artistas: Salebarbes
         Genero: country
         Tempo: 172 BPM
         
         ------------------------------------------
         
         Cancion 9846
         ID: 19997
         Titulo: Some Girls Do
         Album: Best Of
         Artistas: Sawyer Brown
         Genero: country
         Tempo: 139 BPM
         
         ------------------------------------------
         
         Cancion 9847
         ID: 19998
         Titulo: Blow My Smoke
         Album: Creeker
         Artistas: Upchurch
         Genero: country
         Tempo: 150 BPM
         
         ------------------------------------------

   Luego nos devuelve al menú principal

   6.  Crear lista de reproducción: Opción seleccionada (5)
      
            =========================================
                     CREAR LISTA DE REPRODUCCION
            =========================================
            
            Ingrese el nombre de la lista de reproduccion:

   Ingresamos: temazos

         Lista de reproduccion temazos creada con exito!

   Luego nos devuelve al menú principal

   7. Agregar canción a lista de reproducción: Opción seleccionada (6)
      
            =========================================
                     AGREGAR CANCION A PLAYLIST
            =========================================
            
            Ingrese el nombre de la lista de reproduccion:

   Ingresamos: temazos

         Lista de reproduccion encontrada!
         Ingrese el ID de la cancion a agregar:

   Ingresamos: 6666

         Cancion encontrada!
         Cancion 'Beneath a December Twilight' ha sido agregada a la lista de reproduccion temazos

   Luego nos devuelve al menú principal 

   8. Mostrar canciones de una lista de reproducción: Opción seleccionada (7)
      
            =========================================
                 MOSTRAR CANCIONES DE PLAYLIST
            =========================================
            
            Ingrese el nombre de la lista de reproduccion:

   Ingresamos: temazos

         Lista de reproduccion encontrada!
         Canciones de la lista de reproduccion temazos:
         
         Cancion 1
         ID: 6666
         Titulo: Beneath a December Twilight
         Album: The Slaughter of Innocence, A Requiem for the Mighty
         Artistas: Hecate Enthroned
         Genero: black-metal
         Tempo: 131 BPM
         
         ------------------------------------------

   Luego nos devuelve al menú principal 

   9. Salir: Opción seleccionada (8)
       
            Cierra el programa 
   
6. Contribucion de cada integrante :
   - Flavio Luna :
     * Implementó las funciones para liberar memoria (Limpiar...)
   - Paulina Muñoz :
     * Creacion del MAIN y organizacion de las funciones

 

