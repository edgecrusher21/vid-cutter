#include <iostream>

class Splice {

public:
  Splice(int t, const std::string& st, const std::string& et) : track(t), startTime(st),
                                        endTime(et) {};
  ~Splice();
  int getTrack() {return track;}
  void setTrack(int t){ track = t;}
  const std::string getStartTime(){return startTime;}
  void setStartTime(const std::string& st){startTime = st;}
  const std::string getEndTime(){return endTime;}
  void setEndTime(const std::string& et){endTime = et;}
private:
  int track;
  std::string startTime;
  std::string endTime;
};
Splice::~Splice(){
  
}
