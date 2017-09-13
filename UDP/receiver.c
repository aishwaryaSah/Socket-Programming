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
 int fd=socket(AF_INET, SOCK_DGRAM, 0);
 if(fd!=-1)
   printf("Socket Created\n");
    
 struct sockaddr_in obj;
 obj.sin_family=AF_INET;
 obj.sin_port=htons(7000);
 obj.sin_addr.s_addr=inet_addr("169.254.6.212");
 int b1=bind(fd,(const struct sockaddr *)&obj, sizeof(obj));
 
 if(b1==-1)
 {
  printf("aa\n");
 }
 else
 {
  printf("Binded\n");
 }
 int a=0;  
 do
 {
  struct sockaddr_in obj1;
  int l=sizeof(obj1);
  char str[100];
  int d1=recvfrom(fd,str,sizeof(str),0,(struct sockaddr *)&obj1, &l);
  if(d1==-1)
  {
   printf("aa\n");
  }
  else
  {
   printf("%s",str);
   printf("\n");
   char str1[100];
   scanf("%s",str1);
   int d2=sendto(fd,str1,strlen(str1),0,(const struct sockaddr *)&obj1, sizeof(obj1));
   if(d2==-1)
   {
    printf("aa\n");
   }
  }
  a++;
 }while((strcpy(str,"BYE")!=0)&&(strcpy(str1,"BYE")!=0));
}
