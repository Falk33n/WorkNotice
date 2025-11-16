#pragma once

#include "CheckEmail.h"
#include "CheckJira.h"
#include "MainWindow.h"
#include "SitDown.h"
#include "StandUp.h"

// Handles the application
class WorkNotice : public QWidget {
    Q_OBJECT

  public:
    WorkNotice(MainWindow *_mainWindow, QWidget *parent = nullptr);
    ~WorkNotice();

  private:
    // Pointers to the different notice states
    StandUp *standUp;
    SitDown *sitDown;
    CheckEmail *checkEmail;
    CheckJira *checkJira;
    MainWindow *mainWindow;
};
