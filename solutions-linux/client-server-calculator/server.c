#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
// socket related
#include <sys/socket.h>
#include <sys/un.h> // unix namespace --> local sockets

#include <signal.h>

#define SOCKET_NAME "/tmp/localSocket"
#define BUFSZ       (4*1024)  // 4 KB


typedef int socket_t;
typedef struct sockaddr_un LocalSocketAddr_t ;
typedef struct  sockaddr SocketAddr_t ;

socket_t server_sock ;

void destroy_socket(int sig)
{
    printf("Destroying allocated aserver socket...\n");
    close(server_sock);
    unlink(SOCKET_NAME);
}





int main(void)
{
    char buffer[BUFSZ] = {0} ;
    LocalSocketAddr_t server_addr ;

    // just in case the last run did not destroy the socket
    unlink(SOCKET_NAME);
    signal(SIGTERM, destroy_socket);

    // file descriptor
    server_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if(server_sock < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    printf("server socket created..\n ");


    memset(&server_addr, 0, sizeof(LocalSocketAddr_t));
    server_addr.sun_family = AF_UNIX ;
    strncpy(server_addr.sun_path,SOCKET_NAME, strlen(SOCKET_NAME)+1);
    int ret = bind(server_sock,(SocketAddr_t*) &server_addr, sizeof(LocalSocketAddr_t) );
    if(ret < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    ret = listen(server_sock, 2);
    if(ret < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        // accept is waiting for a client connection request
        socket_t client_sock = accept(server_sock,NULL,NULL);
        if(client_sock < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        ret = read(client_sock,buffer, BUFSZ );
        if(ret < 0)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buffer[BUFSZ-1] = '\0' ;

        // process request from client
        printf("Received from Client: %s\n", buffer);

        // send response to client
        char* msg = "Hi from local Server" ;
        memset(buffer, 0, BUFSZ);
        strncpy(buffer, msg, strlen(msg)) ;
        ret = write(client_sock, buffer,strlen(buffer) );
        if(ret < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
        close(client_sock);
    
    }

    destroy_socket(99);
}