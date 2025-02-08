#include <stdio.h>
#include <winsock.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
SOCKET listenSocket;
SOCKET remoteSocket;
SOCKADDR_IN Server_addr;
SOCKADDR_IN Client_addr;
int sin_size;
short port;
 
char buffer[256];
 
int wsastartup;
int ls_result;
 
/* Inizializzazione della libreria Socket */
WORD wVersionRequested = MAKEWORD(2,2);
WSADATA wsaData;
wsastartup = WSAStartup(wVersionRequested, &wsaData);
if (wsastartup != NO_ERROR) printf("Errore WSAStartup()\n");
 
/* Creazione della Socket che si porrà in ascolto di richieste del Client*/
listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (listenSocket < 0)
printf("Server: errore nella creazione della socket.\n");
else printf("La Listening Socket è partita\n");
 
/* Effettua la bind sull'indirizzo e porta ora specificati */
port = 4000;
 
Server_addr.sin_family = AF_INET;
Server_addr.sin_addr.s_addr = inet_addr( "127.0.0.1" );
Server_addr.sin_port = htons(port);
 
if (bind(listenSocket,(LPSOCKADDR)&Server_addr,sizeof(struct sockaddr)) < 0)
printf("Server: errore durante la bind.\n");
 
/* La socket si pone in "ascolto" tramite la listen() */
ls_result = listen(listenSocket, SOMAXCONN);
if (ls_result < 0) printf("Server: errore durante la listen.\n");
else printf("La Socket è in Ascolto\n");
 
/* La socket accetta la richiesta di connessione del Client */
sin_size = sizeof(struct sockaddr_in);
remoteSocket = accept(listenSocket, (struct sockaddr *)&Client_addr,
&sin_size);
printf("Accettata Connessione con Client: %s\n\n",
inet_ntoa(Client_addr.sin_addr));
 
/* Il Server accetta il numero dal Client */
recv(remoteSocket, buffer, sizeof(buffer), 0);
printf("Numero Arrivato (caratteri) ): %s \n", buffer);
// ---------------------------------------- INIZIO   Conversione della stringa in numero e calcolo del doppio -----------------------
 int n = atoi(buffer);
 n = n * 2;
 itoa(n,buffer,10);

// ---------------------------------------- FINE   Conversione della stringa -----------------------
printf("Numero Doppio Calcolato  %d \n", n);
/* Il Server rimanda il nuovo numero al Client */
send(remoteSocket, buffer, strlen(buffer), 0);

printf("Chiudo il Server");
closesocket(remoteSocket);
WSACleanup();
 
system("pause");
return 0;
}

