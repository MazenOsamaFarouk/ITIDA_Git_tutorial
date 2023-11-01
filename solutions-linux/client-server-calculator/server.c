#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
// socket related
#include <sys/socket.h>
#include <sys/un.h> // unix namespace --> local sockets

#include <signal.h>

#include <ctype.h>

#define SOCKET_NAME "/tmp/localSocket"
#define BUFSZ (4 * 1024) // 4 KB

typedef int socket_t;
typedef struct sockaddr_un LocalSocketAddr_t;
typedef struct sockaddr SocketAddr_t;

socket_t server_sock;

void Calculator(char *buffer);
void ShiftNumbersLeft(float numbers[], int start);
void ShiftOperationsLeft(char operations[], int start);

void destroy_socket(int sig)
{
    printf("Destroying allocated a server socket...\n");
    close(server_sock);
    unlink(SOCKET_NAME);
}

int main(void)
{
    char buffer[BUFSZ] = {'\0'};

    LocalSocketAddr_t server_addr;

    // just in case the last run did not destroy the socket
    unlink(SOCKET_NAME);
    signal(SIGTERM, destroy_socket);

    // file descriptor
    server_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_sock < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    printf("server socket created listening...\n");

    memset(&server_addr, 0, sizeof(LocalSocketAddr_t));
    server_addr.sun_family = AF_UNIX;
    strncpy(server_addr.sun_path, SOCKET_NAME, strlen(SOCKET_NAME) + 1);
    int ret = bind(server_sock, (SocketAddr_t *)&server_addr, sizeof(LocalSocketAddr_t));
    if (ret < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    ret = listen(server_sock, 2);
    if (ret < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // accept is waiting for a client connection request
        socket_t client_sock = accept(server_sock, NULL, NULL);
        if (client_sock < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        memset(buffer, '\0', BUFSZ);

        ret = read(client_sock, buffer, BUFSZ);
        if (ret < 0)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // process request from client
        printf("Received from Client: %s\n", buffer);

        /*calculator with order of operations kinda*/
        Calculator(buffer);

        // send response to client
        // char *msg = "Hi from local Server";
        // memset(buffer, '\0', BUFSZ);
        // strncpy(buffer, msg, strlen(msg));

        ret = write(client_sock, buffer, strlen(buffer));
        if (ret < 0)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
        close(client_sock);
    }

    destroy_socket(99);
}

void Calculator(char *buffer)
{
    short int numbers_count = 0;
    short int operations_count = 0;
    short int iterator = 0;

    char operation[25] = {0};
    float numbers[50] = {0};

    while (buffer[iterator] != '\0')
    {
        if (isdigit(buffer[iterator]))
        {
            numbers[numbers_count] = (numbers[numbers_count] * 10) + (buffer[iterator] - '0');
        }
        else
        {
            operation[operations_count] = buffer[iterator];
            operations_count++;
            numbers_count++;
        }
        iterator++;
    }

    numbers_count = 0;
    operations_count = 0;

    while (operation[operations_count] != '\0')
    {
        if (operation[operations_count] == '*' || operation[operations_count] == '/')
        {
            switch (operation[operations_count])
            {
            case '*':
                numbers[operations_count] *= numbers[operations_count + 1];
                break;
            case '/':
                if (numbers[operations_count + 1] == 0)
                {
                    sprintf(buffer, "can't divide by zero.\n");
                    return;
                }
                else
                {
                    numbers[operations_count] /= numbers[operations_count + 1];
                }
                break;
            }
            ShiftNumbersLeft(numbers, operations_count + 1);
            ShiftOperationsLeft(operation, operations_count);
            operations_count--;
        }
        operations_count++;
    }

    numbers_count = 0;
    operations_count = 0;

    while (operation[operations_count] != '\0')
    {
        if (operation[operations_count] == '+' || operation[operations_count] == '-')
        {
            switch (operation[operations_count])
            {
            case '+':
                numbers[operations_count] += numbers[operations_count + 1];
                break;
            case '-':
                numbers[operations_count] -= numbers[operations_count + 1];
                break;
            }
            ShiftNumbersLeft(numbers, operations_count + 1);
            ShiftOperationsLeft(operation, operations_count);
            operations_count--;
        }
        else
        {
            sprintf(buffer, "No spaces allowed and only allowed operations are + - / * you entered '%c'", operation[operations_count]);
            return;
        }
        operations_count++;
    }
    sprintf(buffer, "Result = %.2f.", numbers[0]);
}

void ShiftNumbersLeft(float numbers[], int start)
{
    while (numbers[start] != '\0')
    {
        numbers[start] = numbers[start + 1];
        start++;
    }
}

void ShiftOperationsLeft(char operations[], int start)
{
    while (operations[start] != '\0')
    {
        while (operations[start] != '\0')
        {
            operations[start] = operations[start + 1];
            start++;
        }
    }
}