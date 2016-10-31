#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>

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

float roundtoTwo(float f) {
  f = f*100;
  f = round(f);  
  f = f/100;
  return f;
}

int main() {
  struct stat staty;

  int err = stat("stat.c",&staty);
  //int err = stat("a.exe",&staty);
  
  if (err < 0) {
    printf("Error: %s", strerror(err));
    return 0;
  }
  
  int size = (int)staty.st_size;
  if (size >= 1073741824) {
    printf("File size: %f GB\n",(roundtoTwo(staty.st_size/1073741824.0)));
  }
  else if (size >= 1048576) {
    printf("File size: %f MB\n",(roundtoTwo(staty.st_size/1048576.0)));
  }
  else if (size >= 1024) {
    printf("File size: %f KB\n",(roundtoTwo(staty.st_size/1024.0)));
  }
  else {
    printf("File size: %lld B\n",(long long)staty.st_size);
  }

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


 
