#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/socket.h>

unsigned short
icmp_csum (unsigned short *buf, int nwords)
{
	unsigned long sum;

	for (sum = 0; nwords > 0; nwords--)
		sum += *buf++;
	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	return ~sum;
}
void 
usage(const char *argv0)
{
  fprintf(stderr,"%s (-s -u uid | -k )  -h host_ip\n",argv0);
  exit(EXIT_FAILURE);
}

int
main (int argc, char *argv[])
{
  int s;
  unsigned int kill = 0;
  unsigned int start = 0;
  uint32_t uid = UINT_MAX;
  char opt;
  char buf[8];
  char *host_ip = NULL;
  const char * optstring  = "h:u:sk";
  struct sockaddr_in dst;

  uint8_t  *type = (uint8_t *)  (buf + 0); 
  uint8_t  *code = (uint8_t *)  (buf + 1);
  uint16_t *csum = (uint16_t *) (buf + 2);
  uint32_t *data = (uint32_t *) (buf + 4);


  while ((opt = getopt(argc,argv,optstring)) != -1)
  {
    switch (opt) {
    case 'u' : 
      uid = (unsigned short int)strtoul(optarg,NULL,10);
      break;
    case 'h' :
      host_ip = optarg;
      break;
    case 's' : 
      start = 1;
      break;
    case 'k' :
      kill = 1;
      break;
    default  : 
      usage(argv[0]);
    }
  }


  // LOGICAL NXOR :)))
  if (kill == start || (start && uid == UINT_MAX) || 
      host_ip == NULL || (kill && uid != UINT_MAX ))
	usage(argv[0]);	  


  dst.sin_family = AF_INET;
  dst.sin_port   = htons(0); // bljeee
  dst.sin_addr.s_addr = inet_addr(host_ip);
  bzero(dst.sin_zero, sizeof (dst.sin_zero));

  if ( (s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
    perror("socket");
  }

  bzero(buf,8);
  *type = 111;
  if (start)
  	*code = 222;
  else if (kill)
	*code = 221;
  *data = uid;
  *csum = 0;

  *csum = icmp_csum((unsigned short*)buf,4);
  sendto(s,buf,8,0,(struct sockaddr *)&dst, sizeof(dst));

  return (0);
}
