# Tarea 2

# SPOTIFIND : Buscador de canciones personalizado
DESCRIPCIÓN
SpotiFind es una aplicación de que se carga en la termina que permite explorar una base de datos musical y buscar canciones según distintos criterios: género, artista o tempo (velocidad de la canción). Para poder hacer esto, la aplicación carga un gran volumen de canciones con su respectiva información desde un archivo .CSV.  Una de las funcionalidades destacadas yace en la capacidad de crear listas de reproducciones personalizadas, pudiendo así organizarlas por preferencia.

1. Como compilar y ejecutar :
   
    Para ejecutar nuestro programa deberás descargar los archivos "tarea2.exe" y "songdataset.csv". A continuación deberás crear una nueva carpeta y mover los archivos anteriormente descargados, deberá quedar en un formato parecido a la carpeta "programa" adjunta en el repositorio. 

    Al abrir la carpeta ya con los archivos adjuntos, unicamente hará falta ejecutar el archivo "tarea2.exe".
    * Requisitos previos :
   
        Trabaja desde la terminal, por lo que no existen prerrequisitos mas que abrir el archivo  .exe, el cual está de antemano en una carpeta junto al archivo .csv. Al hacer doble clic en el .exe se abrirá la terminal con el programa listo para su uso.
   
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
       * Todos los generos deben ser escritos en miniscula, no detecta genero escrito con una letra mayuscula o mayuscula total (ej: blues ✓ Blues ✗ BLUES ✗)
   
4. Ejemplo de interaccion con la aplicacion :
    
   
5. Contribucion de cada integrante :
       Flavio Luna :
           * Implementó las funciones para liberar memoria (Limpiar...)
           * 
       Paulina Muñoz :
           * 
           * 

