#include <iostream>
#include <unistd.h>

void checkFFmpeg(){
  int findFFmpeg = system("which ffmpeg");

  if(access(findFFmpeg, F_OK) != -1){
    printf("Please install ffmpeg before continuing");
  }else{
    printf("ffmpeg found");
  }
}


int main(int arg, const char* argv[]) {
  printf("Starting vid cutter \n");
  checkFFmpeg();
  return 0;
}

