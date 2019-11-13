#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(){
  struct stat file;
  stat("stat.c", &file);
  printf("Size: %ld\n", file.st_size);
  printf("Permissions: %o\n", file.st_mode);
  printf("Time of Last Access: %s", ctime(&file.st_atime));
  return 0;
}
