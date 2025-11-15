#pragma once

// Local includes
#include "MainWindow.h"
#include "SitDown.h"
#include "StandUp.h"

// 3rd party includes
#include "ui_WorkNotice.h"
#include <QLabel>

// Handles the main application window
class WorkNotice : public QWidget {
    Q_OBJECT

  public:
    WorkNotice(MainWindow *mainWin, QWidget *parent = nullptr);
    ~WorkNotice();

  private:
    Ui::WorkNoticeClass ui;
    StandUp *standUp;
    SitDown *sitDown;
    MainWindow *mainWindow;
};
