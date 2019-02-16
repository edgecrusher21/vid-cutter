#include <iostream>

class Splice {

public:
  Splice(int t, double st, double et) : track(t), startTime(st),
                                        endTime(et) {};
private:
  int track;
  double startTime;
  double endTime;
  int getTrack();
  void setTrack(int t);
  double getStartTime();
  void setStartTime(int st);
  double getEndTime();
  void setEndTime(int et);
};


int Splice::getTrack(){
  return track;
}

void Splice::setTrack(int t){
  track = t;
}

double Splice::getStartTime(){
  return startTime;
}

void Splice::setStartTime(int st){
  startTime = st;
}

double Splice::getEndTime(){
  return endTime;
}

void Splice::setEndTime(int et){
  endTime = et;
}
