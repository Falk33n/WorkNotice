#pragma once

#include "NoticeState.h"
#include "QLabel"

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
    QString TIMER_ZERO_TEXT;
    QString TIMER_UPDATE_TEXT;
    QString INITIAL_TEXT;
    QString TITLE;

    QLabel *label;

    // Creates and configures the main window
    void createWindow();

    // Adds the countdown label to the main window
    void addLabel();
};
