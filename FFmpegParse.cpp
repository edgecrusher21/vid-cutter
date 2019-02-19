//#include "CsvParse.cpp"
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

void convertToMp3(const char * videoFile, std::string artist, std::string albumName,  std::string year, Song* song){
  // Create directories for files
  // Code based from here: https://www.geeksforgeeks.org/create-directoryfolder-cc-program/
  
    //Now it's time to use ffmpeg to convert to mp3 and add metadata 
    std::string command("ffmpeg -i ");
    command.append(videoFile);
    command.append(" -vn -ab 320k -ar 44100");
    command.append(" -ss ");
    command.append(song->getStartTime());
    command.append(" -to ");
    command.append(song->getEndTime());
    command.append(" -y ");
    command.append("-metadata artist=\"");
    command.append(artist);
    command.append("\" -metadata title=\"");
    command.append(song->getSongName());
    command.append("\" -metadata album=\"");
    command.append(albumName);
    command.append("\" -metadata year=\"");
    command.append(year);
    command.append("\" ");
    command.append("\" ");
    command.append(artist);
    command.append(" - ");
    command.append(song->getSongName());
    command.append(".mp3");
    command.append("\" ");

    std::cout << "Now parsing command: " << command << std::endl;
    std::cout << "Now converting: " << song->getSongName() << std::endl;
    system(command.c_str());


  

}

void toMp3(Album* album, const char * videoFile){
  std::string artist = album->getArtistName();
  std::string albumName = album->getAlbumName();
  std::string year = album->getYear();

  while(!album->isTrackListEmpty()){
    Song* song = album->getTrack();
    std::cout << "Song Name: " << song->getSongName() <<
      " Start Time: " << song->getStartTime() <<
      " End Time: " << song->getEndTime()
              << std::endl;
    convertToMp3(videoFile, artist, albumName, year, song);
  }
}

//int main(int arg, char* argv[]){
  //Include test for ffmpeg
// return 0;
//}
