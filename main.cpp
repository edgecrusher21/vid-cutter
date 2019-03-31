#include "CsvParse.hpp"
#include "FFmpegParse.hpp"
#include "Exceptions.cpp"
#include "lib/YoutubedlWrapper.hpp"

#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

// Constants
/*
  ...
  /// Checks to see if a program exists using a shell command "which"
  /// Such command sees outputs the location of program. If the location
  /// doesn't exist, it should return no value
  /// @param the program as expected to be entered in a shell
  /// @return true if exists, else return false if it doesn't
  ...
*/
bool checkDeps(const char prog[]) {
  // std::ifstream infile(ffmpegLocation.c_str());
  // std::string command = strcat("which ",prog," > /dev/null 2>&1");
  std::string command = "which ";
  command.append(prog);
  command.append(" > /dev/null 2>&1");
  // std::cout << command << std::endl;
  if (!system(command.c_str())) {
    return false;
  } else {
    return true;
  }
}
/*
  ...
  /// main method to initialize program. Main method should be focused
  /// on directing shell arguments, running the appropriate functions
  /// and exception handling. Everything else should be within their own files
  ///
  /// @param arguments provided by the shell
  /// @return exit status code when finished with program or if errors found
  ...
*/

// TBC - interactive w/out the need for a csv file
/*bool interactive() {

  return false;
}
*/

int main(int arg, const char *argv[]) {
  printf("Starting vid cutter \n");
  try {
    std::cout << arg << std::endl;
    if (arg <= 1) {
      std::cout << "Please enter the correct arguments";
      return 0;
    }
    // First, lets check to see if depdencies are met
    // this is just some quick and dirty crap, I'll think
    // of something more elegant later on.
    int flag = 0; // 1=ffmpeg not found;2=youtube-dl not found;3=both not found
    checkDeps("ffmpeg") ? flag += 1 : flag = 0;
    checkDeps("youtube-dl") ? flag += 2 : flag = flag;
    switch (flag) {
    case 1:
      throw DependencyException("ffmpeg");
      break;
    case 2:
      throw DependencyException("youtube-dl");
      break;
    case 3:
      throw DependencyException("ffmpeg, youtube-dl");
      break;

      // Now lets check files
    }

    if (argv[2] == NULL)
      throw ArgException("Please enter in a valid file");
    // TODO: More error checking with files

    if (!youtubedl::validUrl(argv[1]))
      throw ArgException("Please enter in a valid youtube URL");

    // for now, we'll just use mp4 for convenience sakes
    std::string _NULL = "NULL";
    std::string videoFile = youtubedl::downloadVideo(argv[1], "mp4");
    if(videoFile == "NULL"){
      throw std::runtime_error("Video processing failed");
    }else{
      std::cout << "Video file processed: " << videoFile << std::endl;
    }// This feels dodgy on this end

    // Now creating album object to store csv file data
    std::cout << "Now parsing file: " << argv[2] << std::endl;
    Album *album = csvToString(argv[2]);

    // typical y/n prompt, make sure a clear answer is given
    // exit program if 'n' is given
    char response = 'g';
    while (response != 'y') {
      std::cout << "Is this data correct?[y/n]" << std::endl;
      std::cin >> response;
      if (response == 'y') {
        std::cout << "OK" << std::endl;
      } else if (response == 'n') {
        std::cout << "Fix any issues with the CSV file or contact maintainer "
                     "if you believe something went wrong"
                  << std::endl;
        return 0;
      }
    }

    // Now convert files to MP3
    toMp3(album, videoFile.c_str());
  } catch (DependencyException &e) {

    std::cout << e.what() << std::endl;
  } catch (ArgException &e) {
    std::cout << " ERROR IN ARGUMENTS: " << e.what() << std::endl;
  } catch (std::runtime_error &e) {
    std::cout << "Something went wrong. Please contact maintainer" << std::endl;
    std::cout << e.what() << std::endl;
  }
  return 0;
}
