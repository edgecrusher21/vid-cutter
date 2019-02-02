#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <memory>
#include <string>
#include <array>

//Exception for throwing when dependencies are not met
struct DependencyException : public std::exception {
  const char* dep;
  DependencyException (const char* dep_) : dep(dep_)
  {
    std::cout << "WARNING: Crucial dependency not found. Please resolve the following dependencies:" << std::endl;
  }
  const char * what () const throw () {
    return dep;
  }
};

//Once working with FFmpeg, switch over to GStreamer
bool checkDeps(const char prog[]){
  //std::ifstream infile(ffmpegLocation.c_str());
  //std::string command = strcat("which ",prog," > /dev/null 2>&1"); 
  std::string command = "which ";
  command.append(prog);
  command.append(" > /dev/null 2>&1");
  std::cout << command << std::endl;
  if(!system(command.c_str())){
    return false;
  }else{
    return true;
  }
}


int main(int arg, const char* argv[]) {
  printf("Starting vid cutter \n");
  try {
    //First, lets check to see if depdencies are met
    //this is just some quick and dirty crap, I'll think
    //of something more elegant later on.
    int flag = 0;// 1=ffmpeg not found;2=youtube-dl not found;3=both not found
    checkDeps("ffmpeg")?flag+=1 : flag = 0 ;
     checkDeps("youtube-dl")?flag+=2 : flag = flag ;
    switch(flag){
    case 1 :
      throw DependencyException("ffmpeg");
      break;
    case 2 :
      throw DependencyException("youtube-dl");
      break;
    case 3 :
      throw DependencyException("ffmpeg, youtube-dl");
      break;
    }
  }catch(DependencyException& e){
    std::cout << e.what() << std::endl;
  }


  if(argv == NULL){
    std::cout << "Please enter in a valid file" << std::endl;
  }
  return 0;
}

