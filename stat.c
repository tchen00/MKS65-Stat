#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

char * readable(long s){
  int i = 0;
  char * form[] = {"B", "KB", "MB", "GB"};
  while (s >= 1024){
    s /= 1024;
    i++;
  }
  return form[i];
}

void permission(mode_t mode, char * buffer){
	char perm[10] ="rwxrwxrwx";
	for (int i = 0; i < 9; i++){
		if(!(mode & (1 << (8-i)))){
			perm[i] = '-';
		}
	}
	strcat(buffer, perm);
}

int main(){
  struct stat file;
  stat("stat.c", &file);
  printf("Size: %ld\n", file.st_size);
  printf("Permissions: %o\n", file.st_mode);
  printf("Time of Last Access: %s", ctime(&file.st_atime));
  return 0;
}
