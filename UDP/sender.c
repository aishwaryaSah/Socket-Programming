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
 obj.sin_port=htons(6000);
 obj.sin_addr.s_addr=inet_addr("169.254.6.212");

 int b1=bind(fd,(const struct sockaddr *)&obj, sizeof(obj));
 
 if(b1==-1)
 {
  printf("Not Binded\n");
 }
 else
 {
  printf("Binded\n");
 }
 
 struct sockaddr_in rec;
 rec.sin_family=AF_INET;
 rec.sin_port=htons(7000);
 rec.sin_addr.s_addr=inet_addr("169.254.6.212");

 int a=0;
 do
 {
  char str[100];
  scanf("%s",str);
  int d1=sendto(fd,str,strlen(str),0,(const struct sockaddr *)&rec, sizeof(rec));

  if(d1==-1)
  {
   printf("aa\n");
  }
  else
  {
   char str1[100];
   int d2=recvfrom(fd,str1,sizeof(str1),0,NULL,0);

   if(d2==-1)
   {
   printf("aa\n");
   }
   else
   {
    printf("%s",str1);
    printf("\n");
   }
  }
  a++;
 }while((strcpy(str,"BYE")!=0)&&(strcpy(str1,"BYE")!=0));
}
