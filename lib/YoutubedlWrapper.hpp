#ifndef YOUTUBEWRAPPER_HPP
#define YOUTUBEWRAPPER_HPP
#include <iostream>
#include <regex>
#include <sys/stat.h>

namespace youtubedl {
  //std::string youtubeURL;
  //std::string outputFile;
const std::regex CORRECT_YOUTUBE_URL_REGEX(
    "(https?\\:\\/\\/)?((www\\.)?youtube\\.com|youtu\\.?be)\\/.+$");
  //const char *YTDL = "[Youtube-dl Wrapper:] ";

const char *GetStdoutFromCommand(std::string cmd);
bool validUrl(const char *url);
bool fileExists(const char *filename);
  std::string downloadVideo(const char *url, const char *format);
} // namespace youtubedl
#endif
