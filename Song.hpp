#ifndef SONG_HPP
#define SONG_HPP
#include "Splice.hpp"
#include <iostream>
class Song : public Splice {
public:
  Song(const std::string &sn, int t, const std::string &st,
       const std::string &et)
    : Splice(t, st, et), songName(sn){};
  ~Song();
  const std::string getSongName();
  void setSongName(const std::string &sn);

private:
  std::string songName;
};
#endif
