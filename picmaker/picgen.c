#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(){
  srand(time(NULL));  
  char header[20] = "P3 500 500 255 ";
  int pixel[3];
  char line[20];  
  int fd = open("imagine.ppm", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  write(fd, header, strlen(header));
  for(int i = 0; i < 500; i++){
    for(int j = 0; j < 500; j++){
      int r1 = rand();
      snprintf(line, 20, "%d %d %d ",0,i+r1%10,j );
      write(fd, line, strlen(line));
    }
  }

  return 0;
}
