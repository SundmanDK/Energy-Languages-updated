

#include <stdio.h>
#include <sys/time.h>
#include <math.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

#include "rapl.h"

#define RUNTIME 1


int main (int argc, char **argv) 
{ char command[500]="",language[500]="", test[500]="", path[500]="";
  int  ntimes = 1;
  int  core = 0;
  int  i=0;
  char start_msg[500];
  char end_msg[500];
  int pc_identifier;
  char pc_str[20];
#ifdef RUNTIME
  //clock_t begin, end;
  double time_spent;
  struct timeval tvb,tva;
#endif
  
// get ip solution taken from:
// https://stackoverflow.com/questions/1570511/c-code-to-get-the-ip-address?noredirect=1&lq=1
// and modified for our use.
// only works when enp0s31f6 ip is visable
  struct ifaddrs *ifaddr, *ifa;
  int family, s;
  char host[NI_MAXHOST];

  if (getifaddrs(&ifaddr) == -1) {
      perror("getifaddrs");
      exit(EXIT_FAILURE);
  }

  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
      family = ifa->ifa_addr->sa_family;

      if (family == AF_INET) {
          s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in),
                                          host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
          if (s != 0) {
              printf("getnameinfo() failed: %s\n", gai_strerror(s));
              exit(EXIT_FAILURE);
          }
          if (0 == strcmp(ifa->ifa_name, "enp0s31f6")){
              pc_identifier = (int)host + strlen(host) - 2;
              break;
          }
      }
  }
  printf((char *)pc_identifier);
  FILE * fp;

  //Run command
//  strcpy(command, "./" );
  strcat(command,argv[1]);
  //Language name
  strcpy(path,"../");


  //pc_identifier = 54; //last digits of ip
  strcpy(language,argv[2]);
  strcat(language,"-");
  //snprintf(pc_str, 20, "%d",pc_identifier);
  strcat(language,(char *)pc_identifier);
  strcat(language,".csv");
  strcat(path,language);
  //Test name
  strcpy(test,argv[3]);
  printf("test %s\n\n",test);
  //ip address
 
  
  sprintf(start_msg, "../.././sigmark-0.4.9-linux --ip 192.168.50.101:8000 --msg \"start, %s, %d\" --ch1", test, pc_identifier);
  sprintf(end_msg, "../.././sigmark-0.4.9-linux --ip 192.168.50.101:8000 --msg \"slut, %s, %d\" --ch1", test, pc_identifier);
  //ntimes = atoi (argv[2]);
  

  fp = fopen(path,"a");

  rapl_init(core);

  //fprintf(fp,"Package , CPU , GPU , DRAM? , Time (sec) \n");
  
  for (i = 0 ; i < ntimes ; i++)
    {  
 
    	fprintf(fp,"%d,%s,",pc_identifier,test);
 	
	      
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



