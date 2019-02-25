#include <iostream>
#include <regex>
#include <sys/stat.h>

namespace youtubedl{
  std::string youtubeURL;
  std::string outputFile; 
  const std::regex CORRECT_YOUTUBE_URL_REGEX("(https?\\:\\/\\/)?((www\\.)?youtube\\.com|youtu\\.?be)\\/.+$");  
  const char * YTDL = "[Youtube-dl Wrapper:] ";

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
        if (fgets(buffer, max_buffer, stream) != NULL){
         data.append(buffer);
         std::cout << YTDL << "From std command: " <<  buffer << std::endl;
          }

      pclose(stream);
    }
    return data.c_str();
  }

  bool validUrl(const char * url){
    return regex_match(url, CORRECT_YOUTUBE_URL_REGEX);
  }

  bool fileExists(const char * filename){
    struct stat buffer;
    if(stat(filename, &buffer) ==0)
      return true;
    return false;
  }

  bool downloadVideo(const char * url, const char * format){
    youtubeURL = url;

    //generate filename
    outputFile = youtubeURL.substr((youtubeURL.find_first_of("?v=")+3), youtubeURL.length());
    outputFile.append(".").append(format);
    if(fileExists(outputFile.c_str()))
      return true;
    std::string command = "youtube-dl -f ";
    command.append(format);
    command.append(" ");
    command.append(url);
    command.append(" -o '%(id)s.%(ext)s'");

    std::cout << YTDL << "Now Downloading video" << std::endl
              << "File format: " << format << std::endl;
    std::string ytdlOutput = GetStdoutFromCommand(command);
    //std::cout << ytdlOutput << std::endl;
    if(ytdlOutput.find("[download] Destination:") != std::string::npos){
      std:: cout << "Download finished" << std::endl;
      return true;
    }else{
      return false; 
    }

  }

}
