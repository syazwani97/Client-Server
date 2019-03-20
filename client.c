#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
#define MAXRCVLEN 500
#define PORTNUM 2343
 
int main(int argc, char *argv[])
{
    char buffer[MAXRCVLEN + 1]; /* +1 so we can add null terminator */
    int len, mysocket;
    struct sockaddr_in dest; 
 
    mysocket = socket(AF_INET, SOCK_STREAM, 0);
  
    memset(&dest, 0, sizeof(dest));                /* zero the struct */
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr("127.0.0.1"); /* set destination IP number */
    dest.sin_port = htons(PORTNUM);                /* set destination port number */
 
    connect(mysocket, (struct sockaddr *)&dest, sizeof(struct sockaddr));
  
    len = recv(mysocket, buffer, MAXRCVLEN, 0);
 
    /* We have to null terminate the received data ourselves */
    buffer[len] = '\0';
 
    printf("Received %s (%d bytes).\n", buffer, len);
 
    closesocket(mysocket);
    getch();
    return EXIT_SUCCESS;
}
