#pragma once

// Local includes
#include "NoticeState.h"

// 3rd party includes
#include "ui_WorkNotice.h"
#include <QLabel>

// Handles the creation of the main window
class MainWindow : public QWidget {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  public slots:
    // Updates the countdown label with the remaining time
    void updateRemainingTime(int seconds);

    // Updates the label based on the current notice state
    void updateWorkState(NoticeState state);

  private:
    const QString INITIAL_TEXT = "Getting remaining time until stand up reminder...";
    const QString TITLE = "Work Notice";

    QString TIMER_ZERO_TEXT = "Time to raise your desk and stand up!";
    QString TIMER_UPDATE_TEXT = "Next stand up reminder in %1";

    QLabel *label;

    // Creates and configures the main window
    void createWindow();

    // Adds the countdown label to the main window
    void addLabel();
};
