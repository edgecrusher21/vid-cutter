#include <iostream>

class Splice {

public:
  Splice(int t, const std::string& st, const std::string& et) : track(t), startTime(st),
                                        endTime(et) {};
  ~Splice();
  int getTrack();
  void setTrack(int t);
  const std::string getStartTime();
  void setStartTime(const std::string& st);
  const std::string getEndTime(){return endTime;}
  void setEndTime(const std::string& et){endTime = et;}
private:
  int track;
  std::string startTime;
  std::string endTime;
};
Splice::~Splice(){
  
}

int Splice::getTrack(){
  return track;
}

void Splice::setTrack(int t){
  track = t;
}

const std::string Splice::getStartTime(){
  return startTime;
}

void Splice::setStartTime(const std::string& st){
  startTime = st;
}
