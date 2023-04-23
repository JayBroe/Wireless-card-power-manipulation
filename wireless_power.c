#include <linux/wireless.h>
#include <sys/socket.h>		
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/fcntl.h> 
#include <sys/stat.h>
#include <sys/ioctl.h>      
#include <unistd.h>     
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define IWERR_ARG_TYPE		-3
#define IWERR_ARG_CONFLICT	-5
#define IWERR_SET_EXT		-6

static int	errarg;

int main(int argc, char **argv)
{
  srand(time(0));
  int sock;		
  struct iwreq wrq;
  struct iwreq *wrq1 = &wrq;
  struct ifreq ifr;
  char * id[IW_ESSID_MAX_SIZE+1];
  char *p;
  errno = 0;
  long conv;
  int power;
  int num;
  int dbm;
  char buffer[20];
  sock = socket(PF_INET, SOCK_STREAM, 0);
	  if(argc == 2){

    strncpy(wrq1->ifr_name, argv[1], IFNAMSIZ);
    ioctl(sock, SIOCGIWTXPOW, wrq1);

////////////////////////////////////////////////
      snprintf(buffer, sizeof(buffer), "%d dBm", wrq.u.txpower.value);
      
////////////////////////////////////////////////
      memset(&wrq, 0, sizeof(struct iwreq));
      wrq.u.essid.length = IW_ESSID_MAX_SIZE+1;
      sprintf(wrq.ifr_name, argv[1]);
      wrq.u.essid.pointer= id;
      ioctl(sock,SIOCGIWESSID, &wrq);
      printf("ESSID data: %s\n", (char *)wrq.u.essid.pointer);
      printf("Card power %c%s\n   ", (wrq.u.txpower.value ? '=' : ':'),buffer);
////////////////////////////////////////////////     
    }
    else
      if(!strcasecmp(argv[2],"set_power")){
      conv = strtol(argv[3], &p, 10);
      
      num = conv;
      }
      else
      if(!strcasecmp(argv[2],"set_power")){
      conv = strtol(argv[3], &p, 10);
      if(errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN){
        return(EXIT_FAILURE);
      }
      else {
        num = conv;
      }
      }
      else
      if(!strcasecmp(argv[2],"med_power")){
      conv = strtol(argv[3], &p, 10);
        num = 10;
      }
      else
      if(!strcasecmp(argv[2],"max_power")){
      conv = strtol(argv[3], &p, 10);
        num = 22;
      }
      else
      if(!strcasecmp(argv[2],"random_power")){
      conv = strtol(argv[3], &p, 10);
        num = rand() % 22;
      }
      else
      if(!strcasecmp(argv[2],"toff_power")){
      conv = strtol(argv[3], &p, 10);
        wrq.u.txpower.disabled = 1;
      }
     
	  wrq.u.txpower.value = num;
     if(sscanf(argv[3], "%i", &(power)) != 1)
		  {
		    errarg = 0;
		    return(IWERR_ARG_TYPE);
		  }
    strncpy(wrq1->ifr_name,argv[1],IFNAMSIZ); 
    ioctl(sock,SIOCSIWTXPOW,wrq1);
    return(IWERR_SET_EXT);
                
        
  close(sock);
  return EXIT_SUCCESS;
}