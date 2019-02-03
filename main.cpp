#include <iostream>
#include <unistd.h>
#include <regex>
#include <cstdio>
#include <memory>
#include <string>
#include <array>

#include "Exceptions.cpp"
//Constants

//Once working with FFmpeg, switch over to GStreamer
bool checkDeps(const char prog[]){
  //std::ifstream infile(ffmpegLocation.c_str());
  //std::string command = strcat("which ",prog," > /dev/null 2>&1"); 
  std::string command = "which ";
  command.append(prog);
  command.append(" > /dev/null 2>&1");
  //std::cout << command << std::endl;
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

      //Now lets check files
    }

    if(argv[2] == NULL)
      throw ArgException("Please enter in a valid file");
    
    std::regex rx ("^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$");

    if(argv[1] == NULL)
      throw ArgException("Please enter in a valid youtube URL");
    else if(!std::regex_match(argv[1], rx))
      throw ArgException("URL entered is not a valid url");

  }catch(DependencyException& e){
    std::cout << e.what() << std::endl;
  }catch(ArgException& e){
    std::cout << "ARG ERROR: " << e.what() << std::endl;
  }catch(std::exception& e){
    std::cout << "Something went wrong. Please contact maintainer" << std::endl;
    std::cout << e.what() << std::endl;
  }


  
  return 0;
}

 
