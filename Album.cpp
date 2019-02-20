#include <stdio.h>
#include <queue>
#include "Song.cpp"
class Album {
public:
  Album(const std::string& an, const std::string& artN, const std::string& y) : albumName(an), artistName(artN), year(y){};

  //Getters and Setters
  const std::string getAlbumName(){ return albumName;}
  void setAlbumName(const std::string& an){albumName = an;}
  const std::string getArtistName(){return artistName;}
  void setArtistName(const std::string& artN){artistName = artN; }
  const std::string getYear(){return year; }
  void setYear(const std::string& y){year = y;}

  bool addTrack(Song* song);
  Song* getTrack();
  void listTrack();
  bool isTrackListEmpty();

private:
  std::string albumName;
  std::string artistName;
  std::string year; //Store year as ($YEAR)
  std::queue<Song*> trackList;

};

  
//Return true if song added successfully
bool Album::addTrack(Song* song){
  if(trackList.empty()){
    song->setTrack(1);
    trackList.push(song);
    return true;
  }else{
    int prevTrack = trackList.front()->getTrack();
    song->setTrack(prevTrack+1);
    trackList.push(song);
    return true;
  }
}

Song* Album::getTrack(){
  Song* song = trackList.front();
  trackList.pop();
  return song;

}

//Useful for debugging purposes
void Album::listTrack(){
  //Create a copy of the queue
  std::queue<Song*> trackList = this->trackList;
  std::cout << "Now in class listing tracks" << std::endl;
  std::cout << "Album Name: " << albumName << std::endl;
  std::cout << "Artist Name: " << artistName << std::endl;
  std::cout << "Year: " << year << std::endl;
  while(!trackList.empty()){
    Song* song = trackList.front();
    std::cout << "Song Name: " << song->getSongName() <<
      " Start Time: " << song->getStartTime() <<
      " End Time: " << song->getEndTime()
              << std::endl;

    trackList.pop();
  }

}
bool Album::isTrackListEmpty(){
  return trackList.empty();
  }
