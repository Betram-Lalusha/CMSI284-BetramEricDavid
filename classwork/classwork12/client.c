#include <stdio.h>
   #include <sys/socket.h>
   #include <arpa/inet.h>
   #include <unistd.h>
   #include <string.h>

   #define PORT 8080

   int main( int argc, char const *argv[] ) {
       int sock = 0, valread;
       struct sockaddr_in serv_addr;
       char clientMsg[250];
       char buffer[1024] = {0};
       if( (sock = socket( AF_INET, SOCK_STREAM, 0 )) < 0 ) {
           printf( "\n Socket creation error \n" );
           return -1;
       }
       serv_addr.sin_family = AF_INET;
       serv_addr.sin_port = htons(PORT);
       if( inet_pton( AF_INET, "127.0.0.1", &serv_addr.sin_addr )<= 0 ) {
           printf( "\nInvalid address or Address not supported \n" );
           return -1;
       }
       if( connect( sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 ) {
           printf( "\nConnection Failed \n" );
           return -1;
       }

       while(1) {
            printf("\n Enter messsage to sent to server \n\n");
            scanf("%s",clientMsg);
            send( sock, clientMsg, strlen(clientMsg), 0 );
            printf( "   client says: %s \n", clientMsg );
            memset(buffer,0,1024);
            valread = read( sock, buffer, 1024 );
            if(strcmp(buffer, "exit") == 0) {
                break;
            }
            printf( "   client says: server sent: %s\n", buffer );
       }
       return 0;
   }