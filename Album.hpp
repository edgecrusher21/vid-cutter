#include "Song.hpp"
#include <queue>
#include <stdio.h>

class Album {
public:
  Album(const std::string &an, const std::string &artN, const std::string &y)
      : albumName(an), artistName(artN), year(y){};
  ~Album();

  // Getters and Setters
  const std::string getAlbumName();
  void setAlbumName(const std::string &an);
  const std::string getArtistName();
  void setArtistName(const std::string &artN);
  const std::string getYear();
  void setYear(const std::string &y);

  bool addTrack(Song *song);
  Song *getTrack();
  void listTrack();
  bool isTrackListEmpty();

private:
  std::string albumName;
  std::string artistName;
  std::string year; // Store year as ($YEAR)
  std::queue<Song *> trackList;
};
