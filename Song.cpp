#include <iostream>
#include "Splice.cpp"

class Song : public Splice{
public:
  Song(int sn ) : sn(songName);
private:
  const char * songName;

   
};
const char * Song::getSongName(){return songName};
void Song::setSongName(const char * sn){songName = sn};
