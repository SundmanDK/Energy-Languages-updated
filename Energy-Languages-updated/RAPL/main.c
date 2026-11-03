

#include <stdio.h>
#include <sys/time.h>
#include <math.h>

#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>

#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "rapl.h"

#define RUNTIME 1


int main (int argc, char **argv) 
{ char command[500]="",language[500]="", test[500]="", path[500]="";
  int  ntimes = 1;
  int  core = 0;
  int  i=0;
  char start_msg[500];
  char end_msg[500];
  int fd;
  struct ifreq ifr;
  char *ip_addr;
#ifdef RUNTIME
  //clock_t begin, end;
  double time_spent;
  struct timeval tvb,tva;
#endif
  
  FILE * fp;

  //Run command
//  strcpy(command, "./" );
  strcat(command,argv[1]);
  //Language name
  strcpy(path,"../");


  strcpy(language,argv[2]);
  strcat(language,".csv");
  strcat(path,language);
  //Test name
  strcpy(test,argv[3]);
  printf("test %s\n\n",test);
  //ip address
  fd = socket(AF_INET, SOCK_DGRAM, 0);
  ifr.ifr_addr.sa_family = AF_INET;
  strncpy(ifr.ifr_name, "enp0", IFNAMSIZ-1);
  ioctl(fd, SIOCGIFADDR, &ifr);
  ip_addr = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
  close(fd);
  
  sprintf(start_msg, "../.././sigmark-0.4.9-linux --ip 192.168.50.101:8000 --msg \"start,%s,%s\" --ch1", test, ip_addr);
  sprintf(end_msg, "../.././sigmark-0.4.9-linux --ip 192.168.50.101:8000 --msg \"slut,%s,%s\" --ch1", test, ip_addr);
  //ntimes = atoi (argv[2]);
  

  fp = fopen(path,"a");

  rapl_init(core);

  //fprintf(fp,"Package , CPU , GPU , DRAM? , Time (sec) \n");
  
  for (i = 0 ; i < ntimes ; i++)
    {  
 
    	fprintf(fp,"%s ; ",test);
 	
	      
		#ifdef RUNTIME
		        //begin = clock();
				gettimeofday(&tvb,0);
		#endif
	
	rapl_before(fp,core);
	system("pwd");
	system(start_msg); 	
        system(command);
	system(end_msg); 	

	rapl_after(fp,core);

		#ifdef RUNTIME
			//end = clock();
			//time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			gettimeofday(&tva,0);
			time_spent = (tva.tv_sec-tvb.tv_sec)*1000000 + tva.tv_usec-tvb.tv_usec;
			time_spent = time_spent / 1000;
		#endif
			

		#ifdef RUNTIME	
			fprintf(fp," %G \n",time_spent);
		#endif	
    }
    

  fclose(fp);
  fflush(stdout);

  return 0;
}



