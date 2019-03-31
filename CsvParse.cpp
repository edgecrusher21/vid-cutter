#include "CsvParse.hpp"
/*
  ...
  /// Function used to remove "", tabs and spaces from a string extracted from
  /// a CSV file. Unwated tabs and spaces used for asesthetic purposes of a csv
  /// file are removed without removing wanted spaces within the value
  /// This should be used before storing the value to an object to be processed
  /// by the program to avoid errors or bad formatting of values.
  /// @param A reference of the string to be "cleaned"
  /// @return The string value without unwanted "", tabs and spaces
  ...
*/
std::string stringFix(std::string& str){
  int i = 0;
  while(str.at(i)==' '){
    str.erase(0,1);
    i++;
  }
  i = 0;
  while(str.at(i)=='\t'){
    str.erase(0,1);
    i++;
  }
  if(str.at(0)=='"'){
    str.erase(0,1);
  }

  if(str.at(str.length()-1)=='"'){
    str.erase(str.length()-1,1);
  }
  return str;
}
/*
  ...
  /// Function used to take a CSV file, add values to an object (in this case, an Album object for now)
  /// then return the final object.
  ///
  /// @param csv file to be processed
  /// @return Album object with a queue full of song objects
  ...
*/

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
        albumName = stringFix(albumName);
        album->setAlbumName(albumName);
        //std::cout << "Album Name: " << albumName << std::endl;
      }else if(value.compare("_ARTIST_NAME") == 0){
        while(std::getline(iss, artistName, ','))
          iss >> artistName;
        artistName = stringFix(artistName);
        album->setArtistName(artistName);
        //std::cout << "Artist Name: " << artistName << std::endl;
        
      }else if(value.compare("_YEAR") == 0){
        
        while(std::getline(iss, year, ','))
          iss >> year;
        year = stringFix(year);
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
        stringFix(songName);
        stringFix(startTime);
        stringFix(endTime);
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
