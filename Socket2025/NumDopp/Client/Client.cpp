#include <winsock.h>
#include <stdio.h>
#include <string.h>
	 
	int main()
	{
	SOCKET clientsocket;
	SOCKADDR_IN addr;
	 
	char buffer[80];
	short port;
	 
	WORD wVersionRequested = MAKEWORD(2,2);
	WSADATA wsaData;
	WSAStartup(wVersionRequested, &wsaData);
	 
	port = 4000;
	 
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(port);
	
	clientsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (connect(clientsocket, (LPSOCKADDR)&addr, sizeof(addr)) < 0)
	printf("Errore nella connessione con il Server");
	
	// chiede il numero di cui si vuole fare il doppio
   printf("\nNumero da Inviare: ");
   int num;
   scanf("%d",&num);
   
    // passa da intero a stringa ed invia al server
    itoa(num, buffer, 10); 
    send(clientsocket,buffer,sizeof(buffer),0);
    
    // rilegge dal server la risposta (come numero)
    // e la trasforma successivamente in effettivo intero
    recv(clientsocket,buffer,sizeof(buffer),0);
    num= atoi(buffer);

    // stampa l'intero calcolato dal server
	printf("\nIl doppio del numero e':    %d: ",num);

	WSACleanup();
	system("pause");
	return 0;
	}
