#include <stdio.h>
#include <unistd.h>
void checkFFmpeg(void);

main() {
  printf("Starting vid cutter \n");
  checkFFmpeg();
}

void checkFFmpeg(int args){
  string findFFmpeg = system("which ffmpeg");

  if(access(findFFmpeg, F_OK) != -1){
    printf("Please install ffmpeg before continuing");
  }else{
    printf("ffmpeg found");
  }
}
