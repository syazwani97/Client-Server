// Write CPP code here 
#include <netdb.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#define PORT 5000 

int main(int argc , char const *argv[])
{
     int sockfd = 0, vread;
     char *annyeong = "annyeong from client";
     char buff[1000] = {0};
     struct sockaddr_in adrress;
     struct sockaddr_in servaddr;
     
     //create socket
     if ((sockfd = socket(AF_INET, SOCK_STREAM,0)) < 0)
     {
          printf ("could not create socket");
	  return -1;
     }
     memset(&servaddr, '0', sizeof(servaddr));
     
     servaddr.sin_family = AF_INET;
     servaddr.sin_port = htons(5000);
     
     if (inet_pton(AF_INET, "192.168.216.128", &servaddr.sin_addr) <= 0)
     {
          //print the error message
          printf("\n it's error \n");
          return -1;
     }
	
	//Accept and incoming connection
	send(sockfd, annyeong, strlen(annyeong) , 0);
	  printf("annyeong message sent");
	  vread = read(sockfd, buff , 1000);
	  printf("%s\n" , buff);
	  
	
	return 0;
}


