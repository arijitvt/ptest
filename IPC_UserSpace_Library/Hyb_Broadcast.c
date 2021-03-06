#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>

#include "libipc.h"
#include "../ipty.h"

int Hyb_Broadcast(const char *data, int count )
{
	const char *dev_name =  "/dev/ipty0";
	int fd = open(dev_name,O_RDONLY);
	if(fd < 0){
		printf("Unable to send the message\n");
		return -1;
	}
	char *data_buf = (char *) malloc(strlen(data)+3);
	strcpy(data_buf,data);
	strcat(data_buf,"\n");
	ioctl(fd,IOCTL_BROADCAST_MSG,data_buf);
	close(fd);
	return 0;
}

/*
int main(){

	Hyb_Broadcast(0,"Arijit",10 );
	return 0;
}
*/
