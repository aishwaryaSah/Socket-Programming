#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include<string.h>
#include<stdlib.h>
#include <arpa/inet.h>
   
int main()
{
 int fd=socket(AF_INET, SOCK_STREAM, 0);
 if(fd!=-1)
   printf("Socket Created\n");
 
 struct sockaddr_in server;
 server.sin_family=AF_INET;
 server.sin_port=htons(5890);
 server.sin_addr.s_addr=inet_addr("10.0.88.158");

 int b1=connect(fd,(const struct sockaddr *)&server, sizeof(server));
 if(b1==-1)
 {
  printf("Not Connected\n");
 }
 else
 {
  printf("Connected\n");
  char str[100];
  scanf("%s",str);
  int d1=send(fd,str,strlen(str),0);
  if(d1!=-1)
  {
   printf("Send the info\n");
  }
  else
  {
   printf("Not Sent\n");
  }
 }
}
