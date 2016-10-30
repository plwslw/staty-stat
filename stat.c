#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

/*
Custom definitions for permissions that are undefined in Windows

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
*/


//default is rw,r,r

int main() {
  struct stat staty;

  //int err = stat("stat.c",&staty);
  int err = stat("a.exe",&staty);
  
  if (err < 0) {
    printf("Error: %s", strerror(err));
    return 0;
  }

  
  
  
  printf("File size: %lld bytes\n",(long long)staty.st_size);
  
  printf("Permissions: -");

  if (staty.st_mode & S_IRUSR) {
    printf("r"); //read
  }
  else {
    printf("-");
  }
  if (staty.st_mode & S_IWUSR) {
    printf("w"); //write
  }
  else {
    printf("-");
  }
  if (staty.st_mode & S_IXUSR) {
    printf("x"); //execute
  }
  else {
    printf("-");
  }

  if (staty.st_mode & S_IRGRP) {
    printf("r"); //read
  }
  else {
    printf("-");
  }
  if (staty.st_mode & S_IWGRP) {
    printf("w"); //write
  }
  else {
    printf("-");
  }
  if (staty.st_mode & S_IXGRP) {
    printf("x"); //execute
  }
  else {
    printf("-");
  }

  if (staty.st_mode & S_IROTH) {
    printf("r"); //read
  }
  else {
    printf("-");
  }
  if (staty.st_mode & S_IWOTH) {
    printf("w"); //write
  }
  else {
    printf("-");
  }
  if (staty.st_mode & S_IXOTH) {
    printf("x"); //execute
  }
  else {
    printf("-");
  }
  printf("\n");


  printf("Time of last access: %s\n",ctime(&staty.st_atime));

  
  return 0;
}


 /*
   //Not sure why it keeps printing 7

  if (staty.st_mode & (S_IRUSR | S_IWUSR | S_IXUSR)) {
    printf("7");
  }
  else if (staty.st_mode & (S_IRUSR | S_IWUSR)) {
    printf("6"); //read & write
  }
  else if (staty.st_mode & (S_IRUSR | S_IXUSR)) {
    printf("5"); //read & execute
  }
  else if (staty.st_mode & S_IRUSR) {
    printf("4"); //read
  }
  else if (staty.st_mode & (S_IWUSR | S_IXUSR)) {
    printf("3"); //write & execute
  }
  else if (staty.st_mode & S_IWUSR) {
    printf("2"); //write
  }
  else if (staty.st_mode & S_IXUSR) {
    printf("1"); //execute
  }
  else {
    printf("0"); //none
  }

  printf("0");
  printf("0\n");
  */
