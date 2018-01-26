//Evan Eberhardt Lab 4 client.c
//Gens strings, sends transmission to server.c

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
	
	//Generate data
	struct data{
		unsigned short seq;
		unsigned short flag;
		char data[100];
	};
	struct data arr [5];
	char* msg[5];
	msg[0]="this is ground control to major tom";
	msg[1]="youve really made the grade";
	msg[2]="and the papers want to know";
	msg[3]="whose shirts you wear";
	msg[4]="now its time to leave the capsule if you dare";
	unsigned short i;
	for(i=0; i<5; i++){
		arr[i].seq=i;
		arr[i].flag=17;
		strncpy(arr[i].data, msg[i], sizeof(arr[i].data));
	}

	unsigned short seq=0;
	struct data pkt;
	while(seq!=5){
		int n = sendto(sockfd,&arr[seq],sizeof(struct data),0,(struct sockaddr*)&si_server,sizeof(si_server));
		int m = recvfrom(sockfd,&pkt,sizeof(struct data),0,(struct sockaddr*)&si_server,&len);
		if(pkt.seq==seq+1){
			printf("%s\n",pkt.data);
			seq++;
		}
	}

	int c = close(sockfd);
	printf("Exiting...\n");
	return 0;
}
