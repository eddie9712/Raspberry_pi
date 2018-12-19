#include <fcntl.h> // for open
#include <unistd.h> // for close
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
    //Create socket
    sock = socket(AF_INET,SOCK_STREAM , 0);
    if (sock == -1){
      printf("Could not create socket\n");
    }
    printf("Socket created\n");
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0){
        perror("connect failed. Error\n");
        return 1;
    }
    printf("Connected\n");
   while(1)
    {  
     //keep communicating with server
       printf("Enter message : ");
      int i; 
      for(i=0;i<2000;i++)
         message[i]='\0';
       fgets(message,sizeof(message),stdin);
    //Send some data
    if(send(sock,message,strlen(message),0) < 0){
        printf("Send failed\n");
        return 1;
    }
    //Receive a reply from the server
    for(i=0;i<2000;i++)
      server_reply[i]='\0';
    if(recv(sock , server_reply , 2000 , 0) < 0){
      printf("recv failed\n");
    }
     printf("Server reply :");
     printf("%s",server_reply);
    }
    close(sock);
    return 0;
}
