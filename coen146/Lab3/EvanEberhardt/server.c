//Evan Eberhardt Lab 3 server.c
//recieves and prints transmission from client.c 

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

int main(){

	//init socket
	struct sockaddr_in si_server;						//init sockaddr
	bzero((char*)&si_server, sizeof(si_server));		//zero sockaddr
	si_server.sin_family=AF_INET;						//set const
	socklen_t len = sizeof(si_server);
	si_server.sin_addr.s_addr=INADDR_ANY; 				//const for default machine IP addr
	si_server.sin_port=htons(PORTN);					//set port number
	int sockfd = socket(PF_INET, SOCK_DGRAM, 0);		//socket open
	bind(sockfd, (struct sockaddr*) &si_server, sizeof(si_server));
														//Bind socket
	printf("Server Open\n");

	//recieve from
	char packet[1024];
	bool exit=false;
	while(exit==false){
		int n = recvfrom(sockfd, packet, 1024, 0, (struct sockaddr*)&si_server, &len);
		if(n<0) printf("\nAn Error has occured\n");
		if(!strcmp(packet, "logoff\n")){
			printf("Player 1 is logging off\n");
			break;
		}else
			printf("Player 1: %s\n", packet);
		printf("-RECEIVED\n");
		fgets(packet, 1024, stdin);
		if(!strcmp(packet, "logoff\n")) exit=true;
		int m = sendto(sockfd, packet, 1024, 0, (struct sockaddr*)&si_server, sizeof(si_server));
		if(m<0) printf("\nAn Error has occurred\n");
		printf("-SENT\n");
	}
	printf("Type 'quit' to exit\n");
	while(!strcmp(packet, "quit\n"))
		fgets(packet, 15, stdin);
	int c = close(sockfd);
	printf("Exiting...\n");
	return 0;
}
