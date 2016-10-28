#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
  struct stat staty;

  int err = stat("stat.c",&staty);

  if (err < 0) {
    printf("Error: %s", strerror(err));
    return 0;
  }

  printf("File size: %lld bytes\n",(long long)staty.st_size);
  //printf("Permissions: %s\n",staty.st_mode);
  printf("Time of last access: %s\n",ctime(&staty.st_atime));

  
  return 0;
}
