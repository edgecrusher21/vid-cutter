#include <fstream>
#include <iostream>
#include <map>
#include <sys/stat.h>
#include <sys/types.h>
#include <"Song.hpp">

void convertToMp3(const char *videoFile, std::string artist,
                  std::string albumName, std::string year, Song *song);
void toMp3(Album *album, const char *videoFile);
