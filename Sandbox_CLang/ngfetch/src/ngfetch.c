#include <libgen.h>
#include <limits.h>
#include <pwd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include "ip_address_info.h"

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 255
#endif

#define STR(x) _STR(x)
#define _STR(x) #x

int info_offset = 0;
char uptime[9];
unsigned int freeram, totalram, procs;
char host[HOST_NAME_MAX+1], *name, *shellpath, *shell, *gecos, *os, *osrelease;

#if defined __GNU_LIBRARY__
char *lib = "glibc";
char *libversion = STR(__GLIBC__) "." STR(__GLIBC_MINOR__);
#elif defined __UCLIBC__
char *lib = "uclibc";
    char *libversion = STR(__UCLIBC_MAJOR__) "." STR(__UCLIBC_MINOR__);
#elif defined  __dietlibc__
    char *lib = "dietlibc";
    char *libversion = "unknown";
#elif defined __NEWLIB_STDIO_H
    char *lib = "newlib";
    char *libversion = "unknown";
#elif defined USR_KLIBC_STDIO_STDIONT_H
    char *lib = "klibc";
    char *libversion = "unknown";
#elif defined(unix) || defined(__unix__) || defined(__unix)
    char *lib = "libc";
    char *libversion = "unknown";
#else
    char *lib = "muslc";
    char *libversion = "unknown";
#endif

void get_passwd()
{
    struct passwd *passwd = getpwuid(getuid());

    if (!((name = passwd->pw_name))) name = "unknown";
    if (!((shellpath = passwd->pw_shell))) shellpath = "unknown";
    if (!((gecos = passwd->pw_gecos))) gecos = "unknown";

    shell = basename(shellpath);
    //printf("Shell: %s\n", shellpath);
}

void get_utsname()
{
    struct utsname utsname;
    uname(&utsname);

    if (!((os = utsname.sysname))) os = "unknown";
    if (!((osrelease = utsname.release))) os = "unknown";
    printf("OS: %s %s %s\n", utsname.nodename, utsname.sysname, utsname.machine);
    printf("Kernel: %s\n",utsname.release);
    //printf("System name: %s\n",utsname.sysname);
    printf("Username: %s\n Shellpath: %s\n Shell: %s\n glibc: %s\n", name, shell, shellpath, libversion);
}


void get_sysinfo()
{
    int divisor = 1048576;
    struct sysinfo info;
    sysinfo(&info);
    long uptime_s = info.uptime;
    char uptime[9];
    snprintf(uptime, 9, "%.2ld:%.2ld:%.2ld", uptime_s / 3600, uptime_s % 3600 / 60, uptime_s % 60);
    procs = info.procs;
    freeram = info.freeram / divisor;
    totalram = info.freeram / divisor;
    printf("Total RAM: %lu MB\n", info.totalram/divisor);
    printf("Free swap: %lu MB\n", info.freeswap/divisor);
    printf("Processes running: %u\n", procs);
    printf("Uptime: %.2ld:%.2ld:%.2ld\n", uptime_s / 3600, uptime_s % 3600 / 60, uptime_s % 60);
}


int fetch_system_info()
{
    get_passwd();
    gethostname(host, sizeof(host));
    get_utsname();
    get_sysinfo();
    get_public_ip_info();
    get_local_ip_info();
    return 0;
}
