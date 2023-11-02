#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
// socket related
#include <sys/socket.h>
#include <sys/un.h> // unix namespace --> local sockets

#define SOCKET_NAME "/tmp/localSocket"
#define BUFSZ (4 * 1024) // 4 KB

typedef int socket_t;
typedef struct sockaddr_un LocalSocketAddr_t;
typedef struct sockaddr SocketAddr_t;

int main(void)
{
    char buffer[BUFSZ] = {0};
    LocalSocketAddr_t client_addr;

    // file descriptor
    socket_t client_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (client_sock < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    memset(&client_addr, 0, sizeof(LocalSocketAddr_t));
    client_addr.sun_family = AF_UNIX;
    strncpy(client_addr.sun_path, SOCKET_NAME, strlen(SOCKET_NAME) + 1);
    int ret = connect(client_sock, (SocketAddr_t *)&client_addr, sizeof(LocalSocketAddr_t));
    if (ret < 0)
    {
        perror("connect: server is down");
        exit(EXIT_FAILURE);
    }

    // send request to server
    char *msg = "30+70+20*5+20-10*35*5/4+50-20+3";
    strncpy(buffer, msg, strlen(msg));
    ret = write(client_sock, buffer, strlen(buffer));
    if (ret < 0)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    memset(buffer, '\0', BUFSZ);
    // wait for response from Server
    ret = read(client_sock, buffer, BUFSZ);
    if (ret < 0)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Server Response: [%s]\n", buffer);

    close(client_sock);
}