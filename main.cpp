#include <iostream>
#include <unistd.h>
#include <regex>
#include <cstdio>
#include <memory>
#include <string>
#include <array>

#include "Exceptions.cpp"
//Constants


//I use a lot of commands, so it makes sense to have a dedicated function for
//capturing standard output
//Taken from: https://www.jeremymorgan.com/tutorials/c-programming/how-to-capture-the-output-of-a-linux-command-in-c/

const char* GetStdoutFromCommand(std::string cmd) {

  std::string data;
  FILE * stream;
  const int max_buffer = 256;
  char buffer[max_buffer];
  cmd.append(" 2>&1");

  stream = popen(cmd.c_str(), "r");
  if (stream) {
    while (!feof(stream))
      if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
    pclose(stream);
  }
  return data.c_str();
}

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

const char* downloadVideo(const char* url, const char* format){
  std::regex rx("(download)(Destination)");
  // std::string ;
  //Youtube-dl command
  std::string command = "youtube-dl -f ";
  command.append(format);
  command.append(" ");
  command.append(url);
  command.append(" -o '%(id)s.%(ext)s'");

  std::cout << "Now downloading video" << std::endl
            << "File format: " << format << std::endl;

  std::string ytdlOutput = GetStdoutFromCommand(command);
  std::cout << ytdlOutput << std::endl;
  std::cout << std::regex_match(ytdlOutput, rx)<< std::endl;
  if(std::regex_match(ytdlOutput, rx)){
    std:: cout << "Download finished" << std::endl;
    return "Success";
  }else{
    return "Failed";
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
    else if(std::regex_match(argv[1], rx))
      throw ArgException("URL entered is not a valid url");

    //for now, we'll just use webm for convenience sakes
    std::cout << downloadVideo(argv[1], "webm") << std::endl;
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

 
