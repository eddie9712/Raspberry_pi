#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1){
        printf("Could not create socket\n");
    }
    printf("Socket created\n");
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0){
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    printf("bind done\n");
    //Listen
    listen(socket_desc , 3);
    //Accept and incoming connection
    printf("Waiting for incoming connections...\n");
    c=sizeof(struct sockaddr_in);
    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0){
        perror("accept failed\n");
        return 1;
    }
    printf("Connection accepted\n");
    //Receive a message from client
   while(1)
  {
     int i;
     for(i=0;i<2000;i++)
      client_message[i]='\0';
     if((read_size = recv(client_sock , client_message , 2000 , 0)) > 0 ){
        //Send the message back to client
         printf("%s",client_message);
        write(client_sock , client_message , strlen(client_message));
    }
    if(read_size == 0){
        break;
        printf("Client disconnected\n");
    }
    else if(read_size == -1){
        printf("recv failed");
    }
  }
    return 0;
}
