#pragma once

#include "CheckMailInbox.h"
#include "CheckJira.h"
#include "CheckCalendar.h"
#include "CheckGitLab.h"
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
    CheckMailInbox *checkMailInbox;
    CheckJira *checkJira;
    CheckGitLab *checkGitLab;
    CheckCalendar *checkCalendar;
    MainWindow *mainWindow;
};
