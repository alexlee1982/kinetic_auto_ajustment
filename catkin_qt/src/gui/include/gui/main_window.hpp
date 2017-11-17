/**
 * @file /include/gui/main_window.hpp
 *
 * @brief Qt based gui for gui.
 *
 * @date November 2010
 **/
#ifndef gui_MAIN_WINDOW_H
#define gui_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "usr_motion_api.h"
#include "moveandrecord.h"
/*****************************************************************************
** Namespace
*****************************************************************************/



namespace gui {




/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();



public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/

  void refreshStatus();
    /******************************************
    ** Manual connections
    *******************************************/


private Q_SLOTS:
  void on_enable_clicked();

  void on_disable_clicked();

  void on_stop_clicked();

  void on_reset_clicked();

  void on_JP_1_pressed();

  void on_JP_1_released();

  void on_JP_2_pressed();

  void on_JP_2_released();

  void on_JP_3_pressed();

  void on_JP_3_released();

  void on_JP_4_pressed();

  void on_JP_4_released();

  void on_JP_5_pressed();

  void on_JP_5_released();

  void on_JP_6_pressed();

  void on_JP_6_released();

  void on_JN_1_pressed();

  void on_JN_1_released();

  void on_JN_2_pressed();

  void on_JN_2_released();

  void on_JN_3_pressed();

  void on_JN_3_released();

  void on_JN_4_pressed();

  void on_JN_4_released();

  void on_JN_5_pressed();

  void on_JN_5_released();

  void on_JN_6_pressed();

  void on_JN_6_released();

  void on_MOVEandREC_pressed();

  void on_MOVEandREC_clicked();

  void on_pushButton_clicked();

  void on_CAL_clicked();

private:
  Ui::MainWindow ui;
	QNode qnode;
  double th[20][6];
  double deltaQ[24];
  double L[5];
  MoveAndRecord rec;
  double dis[19];
protected:
  void keyPressEvent(QKeyEvent *e);
  void keyReleaseEvent(QKeyEvent *e);

};

}  // namespace gui

#endif // gui_MAIN_WINDOW_H
