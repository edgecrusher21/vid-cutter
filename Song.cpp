#include <iostream>
#include "Splice.cpp"

class Song : public Splice{
public:
  Song(const char * sn, int t, double st, double et) : Splice(t, st, et), songName(sn)  {};
private:
  const char * songName;
  const char * getSongName();
  void setSongName(const char *);
   
};
const char * Song::getSongName(){return songName;};
void Song::setSongName(const char * sn){songName = sn;};
