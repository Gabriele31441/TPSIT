/*LIBRERIE NECESSARIE + gotoxy()*/
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <conio.h>
#include "windows.h"
#include <ctime>
using namespace std;

void gotoxy(int x,int y){
	COORD coordinate={x,y};
	HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(console,coordinate);
}

//PARAMETRI AL MAIN

int main (int argn, char* argc[]){ //parametri da inserire nel main
	
}
//ES. [0]progarmma.exe, [1]15, [2]f, [3]ciao {il primo elemento nel vettore arcgc[] è sempre la path del programma}
num= atoi(argc[1]);		//converte il numero e lo memorizza
car= argc[2][0];		//memorizza il carattere -forse-
strcpy(str, argc[3]);	//memorizza la stringa


//COMANDI BASE
fp = fopen("nome file", "w"); //permette di aprire/creare un file specificandone il nome e il la modalità di apertura
fclose(fp);//chiude il File associato al puntatore (in questo caso fp)
_fcloseall();//chiude tutti i file aperti

//FILE SEQUENZIALI
FILE *fp; //creazione puntatore
fp = fopen("nomeFile.txt", "w");  	//Apre file in scrittura (crea e cancella tutto)
fp = fopen("nomeFile.txt", "a");  	//Apre file in scrittura in coda (si posiziona alla fine)
fp = fopen("nomeFile.txt", "r");  	//Apre file in lettura parte dall'inizio 
fscanf(fp, "%d %s", &num, &str);  	//Legge il contenuto del file (fp) e conserva i valori nelle rispettive variabili
								  	//%d-> interi %f-> float %c-> caratteri %s ->stringhe(vettore di caratteri)
fprintf(fp, "%d %s \n", num, str);	//Scrive sul foglio i dati inseriti
								  	// %5s -> permette di dare uno spazio di minimo 5 giusticando il testo a destra
									// %-5s-> fornisce un minino di n caratteri e giustifica il testo a sinistra. 
									// %.2f-> mette sempre due cifre dopo la virgola -forse sbagliato-

//FILE DIRETTI
fp = fopen("nomeFile.txt", "w+");  	// Apre il file in lettura e scrittura (crea e cancella tutto se esiste già)
fp = fopen("nomeFile.txt", "r+");  	// Apre il file in lettura e scrittura senza cancellare il contenuto
fp = fopen("nomeFile.txt", "a+");  	// Apre il file in lettura e scrittura, posizionandosi alla fine (append)

fseek(fp, sizeof(record), origine);  // movimento all'interno del file
									 // origine -> punto di riferimento (SEEK_SET: inizio, SEEK_CUR: posizione attuale, SEEK_END: fine)
									 
rewind(fp);  // Riporta il puntatore all'inizio del file (equivale a fseek(fp, 0, SEEK_SET))
ftell(fp);   // Restituisce la posizione attuale del puntatore nel file (in byte)
fread(&record, sizeof(record), numero_elementi, fp);  // lettura nel file                 
fwrite(&record, sizeof(record), numero_elementi, fp); // scrittura nel file

//PRATICHE DI CONVENZIONE 

//Si usano le struct
struct rec{
	int num;
	char str[10];
}record; //struct dichiarata

//prima di scrivere/leggere ci posizioniamo sempre nella desiredata posizione
fseek(fp, sizeof(record)*pos, SEEK_SET); //posiziona il puntatore nella posizione desiderata (si parte da 0)
fread() o fwrite

//Sapere la quantità di record nel file
fseek(fp, sizeof(record),SEEK_END); //ci si posiziona alla fine del file
int Nrec = ftell(fp) / sizeof(record); // fa il rapporto della dim. del file con la dim. del singolo record

//CONDIZIONI UTILIZZATE

if (access("nomeFile.txt", F_OK) != 0) {  
    // Il file non esiste, quindi si può creare o segnalare un errore  
} else {  
    // Il file esiste, quindi si può aprire o eseguire operazioni su di esso  
}

while(fscanf(fp, ...)!=EOF){  //si ferma appena finisce il file
	//OPERAZIONI DA FARE
} 

if(!feof(fp)){ //esegue solo se non arrivato alla fine del file
	
}



















