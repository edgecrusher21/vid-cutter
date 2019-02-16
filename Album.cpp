#include <stdio.h>
#include <queue>
#include "Song.cpp"
class Album {
public:
  Album(const char* an, const char * artN, const char * y);
private:
  const char * albumName;
  const char * artistName;
  const char * year; //Store year as ($YEAR)
  std::queue<Song*> trackList;

  bool addTrack(Song* song);

};

//Return true if song added successfully
bool Album::addTrack(Song* song){
  trackList.push(song);
  return false;
}
