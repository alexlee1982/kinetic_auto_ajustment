#ifndef MOVEANDRECORD_H
#define MOVEANDRECORD_H
#include <QtCore>
#include <QThread>
#include<QMutex>
#include "usr_motion_api.h"
#include <QDebug>
//#include "qnode.hpp"
class MoveAndRecord : public QThread
{
public:
  MoveAndRecord();
  virtual ~MoveAndRecord();
  bool init();
  void run();
  bool isRecording();
  void readDistance(double dis[19]);

private:
  QMutex mutex;
  double distance[19];
  double th[20][6];
  bool recording;
};

#endif // MOVEANDRECORD_H
