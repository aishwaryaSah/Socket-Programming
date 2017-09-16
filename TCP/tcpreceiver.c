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
 struct sockaddr_in obj;
 obj.sin_family=AF_INET;
 obj.sin_port=htons(5890);
 obj.sin_addr.s_addr=inet_addr("10.0.88.158");
 int b1=bind(fd,(const struct sockaddr *)&obj, sizeof(obj));
 if(b1==-1)
 {
  printf("Not Binded\n");
 }
 else
 {
  printf("Binded\n");
  int l1=listen(fd,3);
  if(l1==-1)
  {
   printf("Not able to listen");
  }
  else
  {
   printf("Listened\n");
   struct sockaddr_in obj1;
   int l=sizeof(obj1);
   int a1=accept(fd,(struct sockaddr *)&obj1, &l);
   if(a1==-1)
   {
    printf("Not Accepted\n");
   }
   else
   {
    printf("Accepted\n");
   char str[100];
   int d1=recv(a1,str,sizeof(str),0);
   if(d1==-1)
   {
    printf("Not Recieived\n");
   }
   else
   {
    printf("%s",str);
    printf("\n");
   }
   }
  }
 }
} 
