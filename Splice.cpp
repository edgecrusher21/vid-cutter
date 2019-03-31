#include "Splice.hpp"

Splice::~Splice() {}

int Splice::getTrack() { return track; }

void Splice::setTrack(int t) { track = t; }

const std::string Splice::getStartTime() { return startTime; }

void Splice::setStartTime(const std::string &st) { startTime = st; }

const std::string Splice::getEndTime() {return endTime;}

void Splice::setEndTime(const std::string &et) { endTime = et; }
