//Evan Eberhardt Lab 4 server.c
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
	int slen;
	unsigned short seq=0; 
	struct data{
		unsigned short seq;
		unsigned short flag;
		char data[100];
	};
	struct data pkt;

	while(1){
		int n = recvfrom(sockfd,&pkt,sizeof(struct data),0,(struct sockaddr*)&si_server,&len);
		if(pkt.seq==seq || pkt.flag==17){
			slen = strlen(pkt.data);
			printf("Message Recvd:\n%s\nLength: %d\nCheckval: %d\n",pkt.data,slen,pkt.flag);
			int j;
			for(j=0; j<100; j++){
				if(pkt.data[j]=='\0') break;
				toupper(pkt.data[j]);
			}
			pkt.seq++;
		}
		int m = sendto(sockfd,&pkt,sizeof(struct data),0,(struct sockaddr*)&si_server,sizeof(si_server));
	}

	int c = close(sockfd);
	printf("Exiting...\n");
	return 0;
}
