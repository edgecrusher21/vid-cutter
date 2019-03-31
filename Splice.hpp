#ifndef SPLICE_HPP
#define SPLICE_HPP
#include <iostream>

class Splice {

public:
  Splice(int t, const std::string &st, const std::string &et)
    : track(t), startTime(st), endTime(et){};
  ~Splice();
  int getTrack();
  void setTrack(int t);
  const std::string getStartTime();
  void setStartTime(const std::string &st);
  const std::string getEndTime();
  void setEndTime(const std::string &et);

private:
  int track;
  std::string startTime;
  std::string endTime;
};

#endif
