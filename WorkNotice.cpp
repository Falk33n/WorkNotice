// Local includes
#include "WorkNotice.h"

// 3rd party includes
#include <QLabel>
#include <QVBoxLayout>

WorkNotice::WorkNotice(MainWindow *_mainWindow, QWidget *parent)
    : QWidget(parent), mainWindow(_mainWindow) {
    sitDown = new SitDown(this);
    standUp = new StandUp(sitDown, this);

    // Use same instances for communication between timers
    sitDown->setStandUp(standUp);

    // Connect the stand-up timer
    connect(standUp, &StandUp::remainingTimeChanged, mainWindow, &MainWindow::updateRemainingTime);

    // Connect the sit-down timer
    connect(sitDown, &SitDown::remainingTimeChanged, mainWindow, &MainWindow::updateRemainingTime);

    /* Connect state change signals to MainWindow to update text */

    connect(standUp, &StandUp::stateChanged, mainWindow, &MainWindow::updateWorkState);

    connect(sitDown, &SitDown::stateChanged, mainWindow, &MainWindow::updateWorkState);

    standUp->startTimer();
}

WorkNotice::~WorkNotice() {}