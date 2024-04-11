/*
    tcp_client.c
    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void start_client_connection(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;)
    {
        bzero(buff, sizeof(buff));
        printf("Enter the string : ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n');
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s\n", buff);
        if ((strncmp(buff, "exit", 4)) == 0)
        {
            printf("Client Exit...\n");
            break;
        }
        //-----------------------------
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("Status : %s", buff);
        //------------------------------
        printf("\n");
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("%s", buff);
        printf("\n");
    }
}


int test_tcp_client()
{
    int sockfd;
    struct sockaddr_in servaddr; //sockaddr_in - {in - домен для интернета}
    sockfd = socket(AF_INET, SOCK_STREAM, 0); //Дескриптор сокета (Домен AF_INET, тип SOCK_STREAM {TCP}, протокол)
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr)); //обнулить структуру сокета, сделав 0.0.0.0
    //привязка адреса и порта
    servaddr.sin_family = AF_INET; //установка семейства адресов интернет
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //адрес сервера (локальной машины)
    servaddr.sin_port = htons(PORT); //htons - host to network short {преобразование числа из порядка хоста в сетевой}
    //соединение с сервером
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) //соединение с сервером, где 1- дескриптор сокета, 2- адрес сервера, 3- длина адреса сервера
    {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");
    start_client_connection(sockfd);
    close(sockfd);
    return 0;
}


