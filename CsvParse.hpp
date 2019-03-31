#ifndef SONG_HPP
#define SONG_HPP
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <"Album.hpp">

Album* csvToString(const char* fileName);
std::string stringFix(std::string& str);

#endif
