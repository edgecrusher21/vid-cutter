#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>

namespace ffmpeg {
// Wrapper library for FFmpeg (aka dodgy terminal line generator)

const std::string NULL_STRING(
    "_NULL"); // this will be a value I will use to declare a string I want null
const std::string METADATA(" -metadata ");
const std::string DOUBLEQUOTES("\""); // This is annoying to type out

std::string metadata(const std::string &tag, const std::string &value) {

  std::string metadata(METADATA);
  metadata.append(tag)
      .append("=")
      .append(DOUBLEQUOTES)
      .append(value)
      .append(DOUBLEQUOTES);
  return metadata;
}

template <class T> std::string metadata(const std::string &tag, T value) {
  std::string metadata(METADATA);
  metadata.append(tag)
      .append("=")
      .append(DOUBLEQUOTES)
      .append(std::to_string(value))
      .append(DOUBLEQUOTES);
  return metadata;
}

std::string mp3(const std::string &ab, const std::string &ar) {
  std::string str(" -vn ");
  return str.append("-ab ").append(ab).append("k").append(" -ar ").append(ar);
}

bool runFFMpeg(const std::string &command) {
  std::system(command.c_str());
  return true;
}

const std::string duration(const std::string &startTime,
                           const std::string &endTime) {
  std::string str(" -ss ");
  if (endTime.empty() ||
      str.find(":") !=
          std::string::npos) // check if string is empty or just spaces
    return str.append(startTime);
  else
    return str.append(startTime).append(" -to ").append(endTime);
}

const std::string ffmpegValues(const std::string &inputFile,
                               const std::string &outputFile,
                               const char *outputFileType,
                               const std::string &startTime,
                               const std::string &endTime,
                               std::map<std::string, std::string> &md) {
  std::string command("ffmpeg -i ");
  command.append(inputFile);

  if (strcmp(outputFileType, "mp3") == 0)
    command.append(mp3("320", "44100"));

  command.append(duration(startTime, endTime));

  std::map<std::string, std::string>::iterator it = md.begin();
  while (it != md.end()) {
    // std::string md = metadata(it->first, it->second);
    command.append(metadata(it->first, it->second));
    it++;
  }
  return command.append(" ")
      .append(DOUBLEQUOTES)
      .append(outputFile)
      .append(DOUBLEQUOTES);
}
} // namespace ffmpeg
// Use for debugging purposes then comment out later
// int main(int arg, char * argv[]){
// std::cout << ffmpeg::metadata("tag", "value") << std::endl
//            << ffmpeg::metadata("track", 1) <<std::endl;

// std::map<std::string,std::string> md;
// md.insert(std::pair<std::string, std::string>("artist","Fear Factory"));
// md.insert(std::pair<std::string, std::string>("title", "self bias
// resistor"));
// md.insert(std::pair<std::string, std::string>("year", "1995"));
// md.insert(std::pair<std::string, std::string>("album", "demanufacture"));
// std::string command = ffmpeg::ffmpegValues("df.mp4", "output.mp4", "mp3",
// "10:00", "20:00", md);
// const char * output = (ffmpeg::runFFMpeg(command))?"Running command":"command
// failed"; std::cout << output << std::endl;
// return 0;
//}
