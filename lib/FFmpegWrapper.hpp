#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
const std::string NULL_STRING(
    "_NULL"); // this will be a value I will use to declare a string I want null
const std::string METADATA(" -metadata ");
const std::string DOUBLEQUOTES("\""); // This is annoying to type out

namespace ffmpeg {
std::string metadata(const std::string &tag, const std::string &value);
template <class T> std::string metadata(const std::string &tag, T value);
std::string mp3(const std::string &ab, const std::string &ar);
bool runFFMpeg(const std::string &command);
const std::string duration(const std::string &startTime,
                           const std::string &endTime);
const std::string ffmpegValues(const std::string &inputFile,
                               const std::string &outputFile,
                               const char *outputFileType,
                               const std::string &startTime,
                               const std::string &endTime,
                               std::map<std::string, std::string> &md);
} // namespace ffmpeg
