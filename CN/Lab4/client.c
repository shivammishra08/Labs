#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define SIZE 1024

int recvFile(char *filename, int sockfd) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error in writing file.");
        exit(1);
    }
    // File transfer:
    char data[SIZE] = {0}; int flag = 1;
    while(1) {
        if (recv(sockfd, data, SIZE, 0) == -1) {
            printf("Error in receiving file.");
            exit(1);
        }
        if (data[0] == EOF) break;
        if(strcmp(data, "File not found.") == 0) {
            flag = 0; break;
        }
        fprintf(fp, "%s", data);
        bzero(data, SIZE);
    }
    fclose(fp);
    if(!flag) system("rm rfile");
    return flag;
}

int main() {
    // Create socket:
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket Creation FAILED!!\n");
        exit(1);
    }
    printf("Socket created successfully\n");
    
    // Set port and IP the same as server-side:
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Send connection request to server:
    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Connection Failed!!\n");
        exit(1);
    }
    printf("Connection with server Processed Successfully !!\n");
    
    // Receive list from server:
    recvFile("rlist", sockfd);
    printf("List received successfully :\n");
    system("cat rlist");

    // Send filename to server:
    printf("Name of file to be downloaded: ");
    char filename[SIZE]; scanf("%s", filename);
    send(sockfd, filename, sizeof(filename), 0);
    printf("File requested successfully !!\n");

    // Receive file from server:
    if(recvFile("rfile", sockfd)) {
        printf("File received successfully !!\n");
        printf("File contents:\n");
        system("cat rfile");
    }
    else printf("File not found !!\n");
    
    // Close the socket:
    system("rm rlist");
    close(sockfd);
    return 0;
}