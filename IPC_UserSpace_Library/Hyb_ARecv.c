#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "libipc.h"

int Hyb_ARecv(int source,char *data, int count)
{
	char string_buffer[10];
	sprintf(string_buffer,"%d",source);
	const char *dev_name =  "/dev/ipty";
	char *dest_string = (char *)malloc(strlen(dev_name)+strlen(string_buffer));
 	strcat(dest_string,dev_name);
	strcat(dest_string,string_buffer);
#ifdef DEBUG
	printf("%s\n",dest_string);
#endif
	FILE *fp = fopen(dest_string,"r");
	if(fp == NULL){
		printf("Unable to send the message\n");
		return -1;
	}
	fgets(data, 256 , fp);
	fclose(fp);
	return 0;
		
}

/*
int main(){
	
	char recv_buffer[256];
	Hyb_Recv(0,recv_buffer,256 );
	printf("From the main the recv buffer is %s\n",recv_buffer);
	return 0;
}*/

