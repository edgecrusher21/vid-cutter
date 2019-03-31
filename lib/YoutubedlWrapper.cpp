#include "YoutubedlWrapper.hpp"
//namespace youtubedl {
// I use a lot of commands, so it makes sense to have a dedicated function for
// capturing standard output
// Taken from:
// https://www.jeremymorgan.com/tutorials/c-programming/how-to-capture-the-output-of-a-linux-command-in-c/
//using namespace youtubedl;

const char *youtubedl::GetStdoutFromCommand(std::string cmd) {

  //const char *YTDL = "[Youtube-dl Wrapper:] ";
  std::string data;
  FILE *stream;
  const int max_buffer = 256;
  char buffer[max_buffer];
  cmd.append(" 2>&1");

  stream = popen(cmd.c_str(), "r");
  if (stream) {
    while (!feof(stream))
      if (fgets(buffer, max_buffer, stream) != NULL) {
        data.append(buffer);
        std::cout << "From std command: " << buffer << std::endl;
      }

    pclose(stream);
  }
  return data.c_str();
}

bool youtubedl::validUrl(const char *url) {
  return regex_match(url, CORRECT_YOUTUBE_URL_REGEX);
}

bool youtubedl::fileExists(const char *filename) {
  struct stat buffer;
  if (stat(filename, &buffer) == 0)
    return true;
  return false;
}

std::string youtubedl::downloadVideo(const char *url, const char *format) {
  std::string youtubeURL = url;

  // generate filename
  // TODO: Process youtu.be urls
  std::string outputFile = youtubeURL.substr((youtubeURL.find_first_of("?v=") + 3),
                                 youtubeURL.length());
  outputFile.append(".").append(format);
  if (fileExists(outputFile.c_str()))
    return outputFile;
  std::string command = "youtube-dl -f ";
  command.append(format);
  command.append(" ");
  command.append(url);
  command.append(" -o '%(id)s.%(ext)s'");

  std::cout << "Now Downloading video" << std::endl
            << "File format: " << format << std::endl;
  std::string ytdlOutput = GetStdoutFromCommand(command);
  // std::cout << ytdlOutput << std::endl;
  if (ytdlOutput.find("[download] Destination:") != std::string::npos) {
    std::cout << "Download finished" << std::endl;
    return outputFile;
  } else {
    return "NULL";
  }
}

//} // namespace youtubedl
