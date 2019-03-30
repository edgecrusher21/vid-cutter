//#include "CsvParse.cpp"
#include "lib/FFmpegWrapper.cpp"
#include <bits/stdc++.h>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <sys/stat.h>
#include <sys/types.h>
namespace fs = std::filesystem;
std::string directory;

void convertToMp3(const char *videoFile, std::string artist,
                  std::string albumName, std::string year, Song *song) {

  std::map<std::string, std::string> md;
  md.insert(std::pair<std::string, std::string>("artist", artist));
  md.insert(std::pair<std::string, std::string>("title", song->getSongName()));
  md.insert(std::pair<std::string, std::string>("year", year));
  md.insert(std::pair<std::string, std::string>("album", albumName));
  md.insert(std::pair<std::string, std::string>(
      "track", std::to_string(song->getTrack())));
  // This is a quick fix to ensure /'s aren't interpreted by ffmpeg as
  // directories
  // TODO: Make this a generic fix for any string
  std::string songNameFix = song->getSongName();
  for (std::string::size_type i = 0; i < songNameFix.size(); i++) {
    if (songNameFix.at(i) == '/') {
      songNameFix[i] = ' ';
      i++;
      std::cout << songNameFix << std::endl;
    }
  }
  std::string command =
      ffmpeg::ffmpegValues(videoFile,
                           artist.insert(0, directory)
                               .append(" - ")
                               .append(songNameFix)
                               .append(".mp3"),
                           "mp3", song->getStartTime(), song->getEndTime(), md);
  std::cout << "Now parsing command: " << command << std::endl;
  std::cout << "Now converting: " << song->getSongName() << std::endl;
  bool checkSuccess = ffmpeg::runFFMpeg(command);
  if (checkSuccess) {
    std::cout << "ffmpeg ran successuflly" << std::endl;
  } else {
    std::cout << "Something went wrong" << std::endl;
  }
}

void toMp3(Album *album, const char *videoFile) {
  // Create directories for files
  directory.append(album->getArtistName());
  directory.append("/").append(album->getAlbumName()).append("/");
  if (fs::create_directories(directory.c_str()) ||
      fs::exists(directory.c_str())) {
    std::cout << "Directory successfully created: " << directory << std::endl;
  } else {
    throw std::runtime_error(std::string("Creating directory has failed."));
  }

  std::string artist = album->getArtistName();
  std::string albumName = album->getAlbumName();
  std::string year = album->getYear();

  while (!album->isTrackListEmpty()) {
    Song *song = album->getTrack();
    std::cout << "Song Name: " << song->getSongName()
              << " Start Time: " << song->getStartTime()
              << " End Time: " << song->getEndTime() << std::endl;
    convertToMp3(videoFile, artist, albumName, year, song);
  }
}

// int main(int arg, char* argv[]){
// Include test for ffmpeg
// return 0;
//}
