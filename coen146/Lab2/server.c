//Evan Eberhardt Lab 2 server.c
//recieves transmission from client.c and writes new file named "result.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <assert.h>

#define PORTN 9001 //clever

int main(){
	//init socket
	struct sockaddr_in si_server;						//init sockaddr
	bzero((char*)&si_server, sizeof(si_server));		//zero sockaddr
	si_server.sin_family=AF_INET;						//set const
	si_server.sin_addr.s_addr=INADDR_ANY; 				//const for default machine IP addr
	si_server.sin_port=htons(PORTN);					//set port number
	int sockfd = socket(PF_INET, SOCK_DGRAM, 0);		//socket
	//bind
	bind(sockfd, (struct sockaddr*) &si_server, sizeof(si_server));
	//recieve from
	char packet[1024];
	int n = recvfrom(sockfd, packet, 1024, 0, (struct sockaddr*)&si_server, NULL);
	if(n<0) printf("\nAn Error has occured\n");
	//Write file data
	FILE *fp = fopen("result.txt", "w");
	assert(fp!=NULL);
	fputs(packet, fp);
	fclose(fp);
	return 0;
}
