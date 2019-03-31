#include "Album.hpp"

//Getters and Setters
const std::string Album::getAlbumName() { return albumName; }

void Album::setAlbumName(const std::string &an) { albumName = an; }
const std::string Album::getArtistName() { return artistName; }
void Album::setArtistName(const std::string &artN) { artistName = artN; }
const std::string Album::getYear() { return year; }
void Album::setYear(const std::string &y) { year = y; }


// Return true if song added successfully
bool Album::addTrack(Song *song) {
  if (trackList.empty()) {
    song->setTrack(1);
    trackList.push(song);
    return true;
  } else {
    int prevTrack = trackList.back()->getTrack();
    song->setTrack(prevTrack + 1);
    trackList.push(song);
    return true;
  }
}

Song *Album::getTrack() {
  Song *song = trackList.front();
  trackList.pop();
  return song;
}

// Useful for debugging purposes
void Album::listTrack() {
  // Create a copy of the queue
  std::queue<Song *> trackList = this->trackList;
  std::cout << "Now in class listing tracks" << std::endl;
  std::cout << "Album Name: " << albumName << std::endl;
  std::cout << "Artist Name: " << artistName << std::endl;
  std::cout << "Year: " << year << std::endl;
  while (!trackList.empty()) {
    Song *song = trackList.front();
    std::cout << "Song Name: " << song->getSongName()
              << " Start Time: " << song->getStartTime()
              << " End Time: " << song->getEndTime() << std::endl;

    trackList.pop();
  }
}
bool Album::isTrackListEmpty() { return trackList.empty(); }
Album::~Album() {}
