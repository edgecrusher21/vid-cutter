#ifndef FFMPEGPARSE_HPP
#define FFMPEGPARSE_HPP
#include <fstream>
//#include "CsvParse.cpp"
#include "Album.hpp"
#include "lib/FFmpegWrapper.hpp"
#include <bits/stdc++.h>
//#include <cstdlib>
#include "Song.hpp"
#include <iostream>
#include <map>
#include <sys/stat.h>
#include <sys/types.h>
namespace fs = std::filesystem;

void convertToMp3(const std::string &directory, const char *videoFile,
                  std::string artist, std::string albumName, std::string year,
                  Song *song);
void toMp3(Album *album, const char *videoFile);
#endif
