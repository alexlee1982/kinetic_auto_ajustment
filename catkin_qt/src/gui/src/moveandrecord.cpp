#include "moveandrecord.h"
#include <qmath.h>
extern PmCartesian p;
extern double dv13[120];
MoveAndRecord::MoveAndRecord()
{
recording=0;
}
MoveAndRecord::~MoveAndRecord()
{}

bool MoveAndRecord::init()
{
  start();
}
bool MoveAndRecord::isRecording()
{
  if(1==recording)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void MoveAndRecord::run()
{
    mutex.lock();
    recording=1;
/*
  for(int i=0;i<20;i++)
  {
    for(int j=0;j<6;j++)
    {
      if(1==j)
      {
        th[i][j]=dv13[i*6+j]+90.0;
      }
      else
      {
        th[i][j]=dv13[i*6+j];
      }
    }
  }
  */
   for(int i=0;i<6;i++)
   {
     for(int j=0;j<20;j++)
     {
       th[j][i]=dv13[j+i*20];
     }
   }
   for(int j=0;j<20;j++)
   {
     th[j][1]+=90;
   }
  qDebug() << "enter the recorind thread ";
//   while(1)
//   {
//     sleep(1);
//     qDebug()<<" recording : i am running ";
//   }

  int i=0;
  JointMoveInformation jm;
  jm.acc=1;
  jm.dec=1;
  jm.id=0;
  jm.vJ=1;
  MotionFeedback fb;
  PmCartesian currentPosition;
  for(i=0;i<20;i++)
  {
    //add movj command and record the terminal position
    jm.endPoint.j1=th[i][0];
    jm.endPoint.j2=th[i][1];
    jm.endPoint.j3=th[i][2];
    jm.endPoint.j4=th[i][3];
    jm.endPoint.j5=th[i][4];
    jm.endPoint.j6=th[i][5];
    qDebug()<< "sending the movj j="<<th[i][0]<<th[i][1]<<th[i][2]<<th[i][3]<<th[i][4]<<th[i][5];
    CTRL_AddJointMove(&jm,0,0);
    //wait here untill the movement stop
    for(;;)
    {
      sleep(1);
      CTRL_GetMotionStatus(&fb);
      if(fb.motionState==COMMAND_DONE)
      {
        sleep(1);
        //record current position
        if(i>0)
        {
          distance[i-1]=qSqrt((currentPosition.x-p.x)*(currentPosition.x-p.x)
                              +(currentPosition.y-p.y)*(currentPosition.y-p.y)
                              +(currentPosition.z-p.z)*(currentPosition.z-p.z));
         // qDebug()<< "p               x ="<<p.x <<"y= " << p.y <<"z = "<< p.z;
         // qDebug()<< "currentPosition x =" <<currentPosition.x <<"y= " << currentPosition.y <<"z = "<< currentPosition.z;
          currentPosition=p;
        }
        else
        {
          //qDebug()<< "              p x ="<<p.x <<"y= " << p.y <<"z = "<< p.z;
          //qDebug()<< "currentPosition x =" <<currentPosition.x <<"y= " << currentPosition.y <<"z = "<< currentPosition.z;
          currentPosition=p;
        }

        break;
      }
    }



   }
  recording=0;
  mutex.unlock();
}
void MoveAndRecord::readDistance(double dis[19])
{
  for(int i=0;i<19;i++)
  {
    dis[i]=distance[i];
  }
}
