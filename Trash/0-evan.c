//Evan Eberhardt Lab 3 client.c
//Gets string from stdn, sends transmission to server.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <unistd.h>

#define PORTN 9001 //clever

int main(int argc, char* argv[]){

	//init socket
	struct hostent *server_addr = gethostbyname(argv[1]); //get host name
	struct sockaddr_in si_server;						  //init sockaddr
	bzero((char*)&si_server, sizeof(si_server));		  //zero sockaddr	
	si_server.sin_family=AF_INET; 						  //set const
	socklen_t len = sizeof(si_server);
	bcopy((char*)server_addr->h_addr, (char*)&si_server.sin_addr, server_addr->h_length);
   														  //copy info to struct
	si_server.sin_port=htons(PORTN);					  //set port number
	int sockfd = socket(PF_INET, SOCK_DGRAM, 0);		  //socket open
	printf("Socket Open\n");
	
	//generate strings
	char* msg[5];
	msg[0]=",this is ground control to major tom";
	msg[1]=",youve really made the grade";
	msg[2]=",and the papers want to know";
	msg[3]=",whose shirts you wear";
	msg[4]=",now its time to leave the capsule if you dare";

	//begin loop
	int i;
	for(i=0; i<5; i++){
		char* packet = (char*)i;
		char* flag = ",17"

















	//get text data
	char packet[1024];
	bool exit=false;
	while(exit==false){
		fgets(packet, 1024, stdin);
		if(!strcmp(packet, "logoff\n")){
		   printf("Logging off\n");
		   exit=true;
		}
		int n = sendto(sockfd, packet, 1024, 0, (struct sockaddr*)&si_server, sizeof(si_server));
		if(n<0) printf("\nAn Error has occured\n");
		printf("-SENT\n");
		if(exit){ break;}
		int m = recvfrom(sockfd, packet, 1024, 0, (struct sockaddr*)&si_server, &len);
		if(m<0) printf("\nAn Error has occured\n");
		if(!strcmp(packet, "logoff\n")){
			printf("Player 2 is logging off\n");
			break;
		}else
			printf("Player 2: %s\n", packet);
		printf("-RECEIVED\n");
	}
	printf("Type 'quit' to exit\n");
	while(!strcmp(packet, "quit\n"));
		fgets(packet, 15, stdin);
	int c = close(sockfd);
	printf("Exiting...\n");
	return 0;
}
