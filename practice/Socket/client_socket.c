#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
        struct sockaddr_in server_addr;
        int client_sockfd;
        unsigned short PORT = 8080;
 
        client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
        if(client_sockfd == -1){
                perror("Error creating socket");
                exit(EXIT_FAILURE);
        }
 
        memset(&server_addr, 0, sizeof(server_addr));
 
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(PORT);
 
        if(connect(client_sockfd,(struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
                perror("Error connecting to server");
                exit(EXIT_FAILURE);
        }
 
        printf("Connected to server!\n");
        close(client_sockfd);
        return 0;
}
