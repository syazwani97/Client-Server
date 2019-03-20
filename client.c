#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>

//#define ServerIP "35.162.226.229"
#define ServerIP "127.0.0.1"
#define ServerPort 7777
#define SIZE 1024





int main(int argc, char** argv) {

    int socket_fd;
    struct sockaddr_in serverAddr;
    char text[SIZE],msg[SIZE-20], name[20]text temizlendi,get_msg[1024];
    int byte;
    // Nick
    printf("Please enter your nick"); 
    scanf("%s",name);
    //Create Socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1)
        perror("Error on Socket");

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(ServerPort);
    serverAddr.sin_addr.s_addr =inet_addr(ServerIP);
    memset(&(serverAddr.sin_zero), '\0', 8);

    // Connect to server
    if(connect(socket_fd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr)) == -1)
        perror("Error on Connect");
    puts("Connected");
    while(1)
    {
        //Get message
        printf(">>>"); scanf("%s",msg);
        //Edit message
        strcpy(text, name);
        strcat(text, " : ");
        strcat(text, msg);
        //Send message
        byte = send(socket_fd, text, strlen(text), 0);
        if(byte == -1)
            perror("Error on Send");
        else if(byte == 0)
            printf("Connection've been closed");
        //Get reply to other users

        recv(socket_fd, &get_msg, SIZE-1, 0);
        printf("Getting message %s", get_msg);
    }
    //Close socket
    close(socket_fd);



    return (EXIT_SUCCESS);
}
