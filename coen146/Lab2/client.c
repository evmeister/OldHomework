//Evan Eberhardt Lab 2 client.c
//Sends one transmission to server.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <assert.h>

#define PORTN 9001 //clever

int main(int argc, char* argv[]){
	struct hostent *server_addr = gethostbyname(argv[1]); //get host name
	//init socket
	struct sockaddr_in si_server;						  //init sockaddr
	bzero((char*)&si_server, sizeof(si_server));		  //zero sockaddr	
	si_server.sin_family=AF_INET; 						  //set const
	bcopy((char*)server_addr->h_addr, (char*)&si_server.sin_addr, server_addr->h_length); //copy info to struct
	si_server.sin_port=htons(PORTN);					  //set port number
	int sockfd = socket(PF_INET, SOCK_DGRAM, 0);		  //socket
	//get file data
	FILE *fp = fopen("notes.txt", "r");
	assert(fp!=NULL);
	char packet[1024];
	fgets(packet, sizeof(packet), fp);
	//sendto
	int n = sendto(sockfd, packet, 1024, 0, (struct sockaddr*)&si_server, sizeof(si_server));
	if(n<0) printf("\nAn Error has occured\n");
	fclose(fp);
	return 0;
}
