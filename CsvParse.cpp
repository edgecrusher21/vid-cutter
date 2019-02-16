#include <stdio.h>
#include <fstream>
#include "Splice.cpp"
//#include "Album.cpp"

//TODO: Change from void to return Album object
void csvToString(const char* fileName){

  const char * albumName = "album_name";
  const char * artistName = "artist_name";
  const char * year = "year";
  //Album* album = new Album(albumName, artistName, year);

  std::ifstream file(fileName);
  
}

int main(int arg, const char* argv[]){
  std::cout << "Parsing test" << std::endl;
  csvToString("test.csv");
  return 0;
  
}
