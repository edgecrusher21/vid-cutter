#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
//#include "Splice.cpp"
//#include "Song.cpp"
#include "Album.cpp"

//TODO: Change from void to return Album object
Album* csvToString(const char* fileName){

  std::string albumName = "album_name";
  std::string artistName = "artist_name";
  std::string year = "year";
  Album* album = new Album(albumName, artistName, year);

  std::ifstream file(fileName);
  std::string line;

  if(file.is_open()){
    while(std::getline(file,line)){
      std::istringstream iss(line);
      std::string value; 
      std::getline(iss, value, ',');

      if(value.compare("_ALBUM_NAME") == 0){
        while(std::getline(iss, albumName, ','))
          iss >> albumName;
        album->setAlbumName(albumName);
        //std::cout << "Album Name: " << albumName << std::endl;
      }else if(value.compare("_ARTIST_NAME") == 0){
        while(std::getline(iss, artistName, ','))
          iss >> artistName;
        album->setArtistName(artistName);
        //std::cout << "Artist Name: " << artistName << std::endl;
        
      }else if(value.compare("_YEAR") == 0){
        
        while(std::getline(iss, year, ','))
          iss >> year;
        album->setYear(year);
        //std::cout << "Year: " << year << std::endl;
        
      }else{
        std::string songName = "SongName"; 
        int track = -1;
        std::string startTime = "00:00";
        std::string endTime = "00:00";
        songName = value;

        while(std::getline(iss, startTime, ',')){
            iss >> endTime; 
        }

        //std::cout << "Song Name: " << songName << " Start Time: " << startTime << " End Time: " << endTime
        //           << std::endl;
        
        Song* song = new Song(songName, track, startTime, endTime);
        album->addTrack(song);
      } 
    }
  }

  std::cout << "Now Testing to see if object was successfully filled with data" << std::endl;
  album->listTrack();
  return album;
}

// int main(int arg, const char* argv[]){
//   std::cout << "Parsing test" << std::endl;
//   csvToString("test.csv");
//   return 0;
  
// }
