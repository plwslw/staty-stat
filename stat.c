#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

//Custom definitions for permissions that are undefined in Windows
/*
#ifndef S_IRGRP

//r
#define S_IRGRP	        00040
#define S_IROTH	        00004
//w
#define S_IWGRP		00020
#define S_IWOTH		00002
//x
#define S_IXGRP		00010
#define S_IXOTH		00001
//all
#define S_IRWXG		00070
#define S_IRWXO		00007

#endif
*/

//default is rw,r,r

int main() {
  struct stat staty;

  int err = stat("stat.c",&staty);
  //int err = stat("a.exe",&staty);
  
  if (err < 0) {
    printf("Error: %s", strerror(err));
    return 0;
  }

  
  
  
  printf("File size: %lld B\n",(long long)staty.st_size);
  
  printf("Permissions: -");
  
  //User permissions
  printf((staty.st_mode & S_IRUSR) ? "r":"-");
  printf((staty.st_mode & S_IWUSR) ? "w":"-");
  printf((staty.st_mode & S_IXUSR) ? "x":"-");

  //Group permissions
  printf((staty.st_mode & S_IRGRP) ? "r":"-");
  printf((staty.st_mode & S_IWGRP) ? "w":"-");
  printf((staty.st_mode & S_IXGRP) ? "x":"-");

  //Other permissions
  printf((staty.st_mode & S_IROTH) ? "r":"-");
  printf((staty.st_mode & S_IWOTH) ? "w":"-");
  printf((staty.st_mode & S_IXOTH) ? "x":"-");
  printf("\n");
  
  printf("Time of last access: %s\n",ctime(&staty.st_atime));

  
  return 0;
}


 
