Tarea01 Sistemas operativos
Nombre: Mauricio De Juan
correo: mauricio.dejuan@alumnos.uv.cl

Dentro del diseño de mi solucion se encuentran fuciones muy importantes como el main, hora, salirconcontrol y senSig(las explicaciones de como funcionan estan en el codigo).

El proceso del trabajo pedido es basicamente la hora, para esto ejecutamos los comandos "make" y "./hora" donde se mostrara el programa en ejecucion con el id de su proceso, y listo para recibir la señal SIGUSR1, la señal SIGUSR1 funciona como señal definida por uno para se usada en programas de aplicacion como es nuestro caso, desde otra terminal ejecutamos "kill -s SIGUSR process-ID" donde process-ID es la que se nos muestra en la consola. 

Al estar dentro de un ciclo infinito nos mostrara la hora al poner el ultimo comando ya mencionado, podemos poner las veces que queramos el comando al este estar de forma recursiva, es decir, que se puede seguir ejecutando a pesar de que tenga la senial implementada, y el proceso seguira existiendo.

El programa se puede terminar causando la interrupcion SIGINT que se ejecuta con control+c dos veces, esto quiere decir que es para salir del proceso de ejecucion que tenemos.
