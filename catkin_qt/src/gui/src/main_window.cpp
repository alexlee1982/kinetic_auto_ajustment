/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/gui/main_window.hpp"
#include <QTimer>
#include "../include/gui/usr_motion_api.h"
#include <QDebug>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "calculate_the_deltaq_types.h"
#include "rt_nonfinite.h"
#include "calculate_the_deltaq.h"
#include "calculate_the_deltaq_terminate.h"
#include "calculate_the_deltaq_initialize.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/
PmCartesian p;
/*double dv13[120]=
  {	-10 ,-100, -20, -30, -40, -50,
    10, -80, 20, 30, 40, 50,
    20, -70, 30, 40, 50, 60,
    30, -60, 40, 50, 60, 70,
    40, -50, 50, 60, 70, 80,
    50, -40, 60, 70, 80, 90,
    60, -30, 70, 80, 100, 110,
    70, -25, 60, 50, 40, 30,
    80, -20, 70, 50, 60, 80,
    100, -10, 90, 80, 70, 60,
    30, -40, 60, 70, 80, 90,
    110, -80, 90, 80, 60, 70,
    120, -100, -50, 80, 30, 40,
    130, -110, -80, -70, -60, -50,
    140, -120, -100, -80, -70, -60,
    150, -130, -110, -100, -80, -70,
    160, -140, -130, -80, -60, -50,
    -20, 100, -30, -30, -30, -30,
    -30, 110, -40, -40, -40, -40,
    -40, 120, -50, -50, -50, -50
  };*/
double dv13[120]={
-10  ,  10  ,  20  ,  30  ,  40  ,  50  ,  60  ,  70  ,  80  , 100  ,  30  , 110  , 120  , 130  , 140  , 150  , 160 ,  -20  , -30  , -40,
  -100 ,  -80 ,  -70 ,  -60 ,  -50 ,  -40 ,  -30 ,  -25 ,  -20 ,  -10 ,  -40 ,  -80 , -100 , -110 , -120 , -130 , -140 ,  100 ,  110 ,  120,
  -20  ,  20  ,  30  ,  40  ,  50  ,  60  ,  70  ,  60  ,  70  ,  90  ,  60  ,  90  , -50  , -80  ,-100  ,-110 , -130  , -30  , -40  , -50,
  -30  ,  30  ,  40  ,  50  ,  60  ,  70  ,  80  ,  50  ,  50  ,  80  ,  70  ,  80  ,  80  , -70  , -80  ,-100 ,  -80  , -30  , -40  , -50,
  -40  ,  40  ,  50  ,  60  ,  70  ,  80  , 100  ,  40  ,  60  ,  70  ,  80  ,  60  ,  30  , -60  , -70  , -80 ,  -60  , -30  , -40  , -50,
  -50  ,  50  ,  60  ,  70  ,  80  ,  90  , 110  ,  30  ,  80  ,  60  ,  90  ,  70  ,  40  , -50  , -60  , -70  , -50  , -30  , -40  , -50
};
namespace gui {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    //QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application
  L[0]=100;
  L[1]=300;
  L[2]=20;
  L[3]=300;
  L[4]=100;


  CTRL_USR_Init();
  if(!qnode.init())
  {
    qDebug()<<"ros node init failed \n";
    return;
  }


  QTimer *timer=new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(refreshStatus()));
  timer->start(100);
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/





void MainWindow::refreshStatus()
{

  p=qnode.readPositon();
  ui.label_X_value->setText(QString::number(p.x,'f',5));
  ui.label_Y_value->setText(QString::number(p.y,'f',5));
  ui.label_Z_value->setText(QString::number(p.z,'f',5));

  MotionFeedback fb;
  CTRL_GetMotionStatus(&fb);
  double jp[6];
  jp[0]=fb.jointCmd.j1;
  jp[1]=fb.jointCmd.j2;
  jp[2]=fb.jointCmd.j3;
  jp[3]=fb.jointCmd.j4;
  jp[4]=fb.jointCmd.j5;
  jp[5]=fb.jointCmd.j6;
  qnode.writeJointPosition(jp);

  if(fb.enable[0]==1)
  {
    ui.enable_light->setStyleSheet("background-color: rgb(0, 255, 0);");
  }
  else
  {
    ui.enable_light->setStyleSheet("background-color: rgb(255, 0, 0);");
  }

  if(rec.isRecording())
  {
    ui.MOVEandREC->setText("Recording");
  }
  else
  {
    ui.MOVEandREC->setText("MOVE&&REC");
  }

  rec.readDistance(dis);
  ui.label_D1_value->setText(QString::number(dis[0],'f',5));
  ui.label_D2_value->setText(QString::number(dis[1],'f',5));
  ui.label_D3_value->setText(QString::number(dis[2],'f',5));
  ui.label_D4_value->setText(QString::number(dis[3],'f',5));
  ui.label_D5_value->setText(QString::number(dis[4],'f',5));
  ui.label_D6_value->setText(QString::number(dis[5],'f',5));
  ui.label_D7_value->setText(QString::number(dis[6],'f',5));
  ui.label_D8_value->setText(QString::number(dis[7],'f',5));
  ui.label_D9_value->setText(QString::number(dis[8],'f',5));
  ui.label_D10_value->setText(QString::number(dis[9],'f',5));
  ui.label_D11_value->setText(QString::number(dis[10],'f',5));
  ui.label_D12_value->setText(QString::number(dis[11],'f',5));
  ui.label_D13_value->setText(QString::number(dis[12],'f',5));
  ui.label_D14_value->setText(QString::number(dis[13],'f',5));
  ui.label_D15_value->setText(QString::number(dis[14],'f',5));
  ui.label_D16_value->setText(QString::number(dis[15],'f',5));
  ui.label_D17_value->setText(QString::number(dis[16],'f',5));
  ui.label_D18_value->setText(QString::number(dis[17],'f',5));
  ui.label_D19_value->setText(QString::number(dis[18],'f',5));


}


void gui::MainWindow::on_enable_clicked()
{
    CTRL_ServoEnable(1);
}

void gui::MainWindow::on_disable_clicked()
{
    CTRL_ServoEnable(0);
}

void gui::MainWindow::on_stop_clicked()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_reset_clicked()
{
    CTRL_ServoReset();
}

void gui::MainWindow::on_JP_1_pressed()
{
    SingleAxisMove single;
    single.axis=1;
    single.direction=MOVE_DIR_POSITIVE;
    single.vel=0.1;
    single.endPoint=180.0;
    single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

    CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JP_1_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JP_2_pressed()
{
  SingleAxisMove single;
  single.axis=2;
  single.direction=MOVE_DIR_POSITIVE;
  single.vel=0.1;
  single.endPoint=180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JP_2_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JP_3_pressed()
{
  SingleAxisMove single;
  single.axis=3;
  single.direction=MOVE_DIR_POSITIVE;
  single.vel=0.1;
  single.endPoint=180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JP_3_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JP_4_pressed()
{
  SingleAxisMove single;
  single.axis=4;
  single.direction=MOVE_DIR_POSITIVE;
  single.vel=0.1;
  single.endPoint=180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JP_4_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JP_5_pressed()
{
  SingleAxisMove single;
  single.axis=5;
  single.direction=MOVE_DIR_POSITIVE;
  single.vel=0.1;
  single.endPoint=180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JP_5_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JP_6_pressed()
{
  SingleAxisMove single;
  single.axis=6;
  single.direction=MOVE_DIR_POSITIVE;
  single.vel=0.1;
  single.endPoint=180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JP_6_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JN_1_pressed()
{
  SingleAxisMove single;
  single.axis=1;
  single.direction=MOVE_DIR_NEGATIVE;
  single.vel=0.1;
  single.endPoint=-180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JN_1_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JN_2_pressed()
{
  SingleAxisMove single;
  single.axis=2;
  single.direction=MOVE_DIR_NEGATIVE;
  single.vel=0.1;
  single.endPoint=-180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JN_2_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JN_3_pressed()
{
  SingleAxisMove single;
  single.axis=3;
  single.direction=MOVE_DIR_NEGATIVE;
  single.vel=0.1;
  single.endPoint=-180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JN_3_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JN_4_pressed()
{
  SingleAxisMove single;
  single.axis=4;
  single.direction=MOVE_DIR_NEGATIVE;
  single.vel=0.1;
  single.endPoint=-180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JN_4_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JN_5_pressed()
{
  SingleAxisMove single;
  single.axis=5;
  single.direction=MOVE_DIR_NEGATIVE;
  single.vel=0.1;
  single.endPoint=-180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JN_5_released()
{
    CTRL_MovementStop();
}

void gui::MainWindow::on_JN_6_pressed()
{
  SingleAxisMove single;
  single.axis=6;
  single.direction=MOVE_DIR_NEGATIVE;
  single.vel=0.1;
  single.endPoint=-180.0;
  single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;

  CTRL_AddSingleAxisMove(&single);
}

void gui::MainWindow::on_JN_6_released()
{
    CTRL_MovementStop();
}



void gui::MainWindow::on_MOVEandREC_pressed()
{

}

void gui::MainWindow::on_MOVEandREC_clicked()
{
  rec.init();
}





void MainWindow::on_pushButton_clicked()
{
  JointMoveInformation jm;
  jm.acc=1.0;
  jm.dec=1.0;
  jm.vJ=0.1;
  jm.endPoint.j1=(ui.movj_value_J1->text()).toDouble();
  jm.endPoint.j2=(ui.movj_value_J2->text()).toDouble();
  jm.endPoint.j3=(ui.movj_value_J3->text()).toDouble();
  jm.endPoint.j4=(ui.movj_value_J4->text()).toDouble();
  jm.endPoint.j5=(ui.movj_value_J5->text()).toDouble();
  jm.endPoint.j6=(ui.movj_value_J6->text()).toDouble();

  CTRL_AddJointMove(&jm,0,0);
}



void MainWindow::on_CAL_clicked()
{
  calculate_the_deltaq_initialize();
  calculate_the_deltaq(dv13, dis, L, deltaQ);
  calculate_the_deltaq_terminate();
  for(int i=0;i<24;i++)
  {
   qDebug()<<deltaQ[i];
  }

  ui.Delta_J2_value->setText(QString::number(deltaQ[1],'f',5));
  ui.Delta_J3_value->setText(QString::number(deltaQ[2],'f',5));
  ui.Delta_J4_value->setText(QString::number(deltaQ[3],'f',5));
  ui.Delta_J5_value->setText(QString::number(deltaQ[4],'f',5));

  ui.Delta_L1_value->setText(QString::number(deltaQ[12],'f',5));
  ui.Delta_L2_value->setText(QString::number(deltaQ[13],'f',5));
  ui.Delta_L3_value->setText(QString::number(deltaQ[14],'f',5));
  ui.Delta_L4_value->setText(QString::number(deltaQ[21],'f',5));
  ui.Delta_L5_value->setText(QString::number(deltaQ[23],'f',5));
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
  if(e->key() == Qt::Key_Q && !e->isAutoRepeat())
  {
    SingleAxisMove single;
    single.axis=1;
    single.direction=MOVE_DIR_POSITIVE;
    single.vel=0.1;
    single.endPoint=180.0;
    single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;
    CTRL_AddSingleAxisMove(&single);
  }
  else if(e->key() == Qt::Key_W && !e->isAutoRepeat())
  {
    SingleAxisMove single;
    single.axis=1;
    single.direction=MOVE_DIR_NEGATIVE;
    single.vel=0.1;
    single.endPoint=-180.0;
    single.coordinate.coordinateType=COORDINATE_TYPE_JOINT;
    CTRL_AddSingleAxisMove(&single);
  }
}


void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
  if( !e->isAutoRepeat())
  {
    CTRL_MovementStop();
  }
}


}//name space gui
