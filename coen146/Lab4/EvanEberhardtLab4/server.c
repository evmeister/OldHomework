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
#include <ctype.h>

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
	struct data{
		unsigned short seq;
		unsigned short flag;
		char data[100];
	};
	unsigned short seq=0;
	struct data pkt;
	int l;
	while(1){
		int n = recvfrom(sockfd,&pkt,sizeof(struct data),0,(struct sockaddr*)&si_server,&len);
		if(pkt.seq==seq && pkt.flag==17){
			int sl = strlen(pkt.data);
			printf("Message Rcvd:\n%s\nLength:%d\tCheckval:%d\n",pkt.data,sl,pkt.flag);
			for(l=0; l<sl; l++){
				if(pkt.data[l]!=32)
					pkt.data[l]-=32;
			}
			pkt.seq++;
			seq++;
		}
		int m = sendto(sockfd,&pkt,sizeof(struct data),0,(struct sockaddr*)&si_server,sizeof(si_server));
	}
	int c = close(sockfd);
	printf("Exiting...\n");
	return 0;
}
