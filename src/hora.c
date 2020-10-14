#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
int cont = 0;//contador que servira para salir con control+c
static void senSig(int); //senializo la senial que recibira con SIGUSR1

void salirconcontrol(){//cuando uso la senial de interrupcion SIGNINT (control+c) uso esta funcion
	printf("\n");
	cont++;//se suman dos veces para salir del codigo
	if(cont==2){//si el contador esta en 2 sale automaticamente del codigo con exit(0)
		exit(0);
	}
}

void hora(); //senializo hora para tener la estructura que se muestra mas abajo en la funcion
void error_system(char * msg) {// si por algun motivo hay un error ya sea por no enviar la señal u otra cosa el codigo senialara un mensaje de que no se encontro la hora
	printf("%s \n", msg);
	exit(-1);//salida de error
}
int main(int argc, char*argv[]){ //main del trabajo
	printf("Programa hora ejecutandose. PID = %d\n", getpid());//muestro el process-ID
	if(signal(SIGUSR1, senSig) ==SIG_ERR) //si no se encuentra la senial muestra el error en pantalla
		error_system("no se encuentra la senial SIGUSR1\n");
	printf("Listo para recibir la senial SIGUSR1\n"); //si se encuentra la senial procedera a entrar al ciclo infinito para el comando kill
	for(;;){//ciclo infinito donde solo se termina con la salida de control+c
		signal(SIGINT, salirconcontrol);//senial enviada en caso de apretar control+c
		while(1);	//matiene el ciclo con control+c
		pause(); //sirve como sleep dentro del ciclo
		}
		
	return 0;
}

static void senSig(int signo){ //funcion para enviar seniales con SIGUSR1
	if(signo==SIGUSR1){ //cuando el signo de la senial es el mismo que el de SIGUSR1 o el comando kill tiene el mismo process-ID muestra la hora
		hora();
		printf("Listo para recibir la senial SIGUSR1\n");//al estar en un ciclo se muestra de nuevo
		signal(SIGUSR1, senSig);//se usa la recursividad de la senial para implementar de nuevo la funcion
	}
	else
		error_system("la senial no se ha reconocido"); //si no se reconoce la senial enviada aparece este mensaje
	return; //hay retorno en el void para evitar problemas con la recursividad
}



void hora(){ //funcion utilizada para tener la hora local de nuestro pc
	time_t tiempo = time(0); 
	struct tm *Hlocal = localtime(&tiempo);
	char salida[128];
	strftime(salida,128,"%d/%m/%y %H:%M:%S",Hlocal);
	printf("senial SIGUSR1 recibida: %s\n",salida); //muestra la hora con la estructura dada en esta funcion
}






