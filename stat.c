#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
  struct stat *staty = (struct stat *)malloc(sizeof(struct stat *));
  int err = stat("stat.c",staty);

  if (err < 0) {
    printf("Error: %s", strerror(err));
    return 0;
  }

  printf("File size: %s\n",staty->st_blksize);
  printf("Permissions: %s\n",staty->st_mode);
  printf("Time of last access: %s\n",staty->st_atime);
  
  return 0;
}
