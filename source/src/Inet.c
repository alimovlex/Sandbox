#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <netdb.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#define DELIM "." 
//--------------------------------------------Internet program
// Returns hostname for the local computer 
void checkHostName(int hostname) 
{ 
    if (hostname == -1) 
    { 
        perror("gethostname"); 
        exit(1); 
    } 
} 
  
// Returns host information corresponding to host name 
void checkHostEntry(struct hostent * hostentry) 
{ 
    if (hostentry == NULL) 
    { 
        perror("gethostbyname"); 
        exit(1); 
    } 
} 
  
// Converts space-delimited IPv4 addresses 
// to dotted-decimal format 
void checkIPbuffer(char *IPbuffer) 
{ 
    if (NULL == IPbuffer) 
    { 
        perror("inet_ntoa"); 
        exit(1); 
    } 
} 


void get_host()
{
    char hostbuffer[256]; 
    char *IPbuffer; 
    struct hostent *host_entry; 
    int hostname; 
  
    // To retrieve hostname 
    hostname = gethostname(hostbuffer, sizeof(hostbuffer)); 
    checkHostName(hostname); 
  
    // To retrieve host information 
    host_entry = gethostbyname(hostbuffer); 
    checkHostEntry(host_entry); 
  
    // To convert an Internet network 
    // address into ASCII string 
    IPbuffer = inet_ntoa(*((struct in_addr*) 
                           host_entry->h_addr_list[0])); 
  
    printf("Hostname: %s\n", hostbuffer); 
    printf("Host IP: %s\n", IPbuffer); 
}

/* return 1 if string contain only digits, else return 0 */
int valid_digit(char *ip_str) 
{ 
    while (*ip_str) { 
        if (*ip_str >= '0' && *ip_str <= '9') 
            ++ip_str; 
        else
            return 0; 
    } 
    return 1; 
} 
  
/* return 1 if IP string is valid, else return 0 */
int is_valid_ip(char *ip_str) 
{ 
    int i, num, dots = 0; 
    char *ptr; 
  
    if (ip_str == NULL) 
        return 0; 
  
    // See following link for strtok() 
    // http://pubs.opengroup.org/onlinepubs/009695399/functions/strtok_r.html 
    ptr = strtok(ip_str, DELIM); 
  
    if (ptr == NULL) 
        return 0; 
  
    while (ptr) { 
  
        /* after parsing string, it must contain only digits */
        if (!valid_digit(ptr)) 
            return 0; 
  
        num = atoi(ptr); 
  
        /* check for valid IP */
        if (num >= 0 && num <= 255) { 
            /* parse remaining string */
            ptr = strtok(NULL, DELIM); 
            if (ptr != NULL) 
                ++dots; 
        } else
            return 0; 
    } 
  
    /* valid IP string must contain 3 dots */
    if (dots != 3) 
        return 0; 
    return 1; 
} 

void valid_ip()
{
    char ip[] = "128.0.0.1";
    is_valid_ip(ip)? printf("Valid\n"): printf("Not valid\n");   
}