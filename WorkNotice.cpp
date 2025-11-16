#include "WorkNotice.h"

WorkNotice::WorkNotice(MainWindow *_mainWindow, QWidget *parent)
    : QWidget(parent), mainWindow(_mainWindow) {
    // Create the different notice states
    checkEmail = new CheckEmail(this);
    checkJira = new CheckJira(this);
    sitDown = new SitDown(this);
    standUp = new StandUp(this);

    // Connect the timers and state changes to the main window
    std::vector<NoticeBase *> notices = {checkEmail, checkJira, sitDown, standUp};
    for (auto notice : notices) {
        connect(notice, &NoticeBase::remainingTimeChanged, mainWindow,
                &MainWindow::updateRemainingTime);
        connect(notice, &NoticeBase::stateChanged, mainWindow, &MainWindow::updateWorkState);
    }

    // Chain so that the timers start one after another
    connect(checkEmail, &NoticeBase::timeout, checkJira, &NoticeBase::startTimer);
    connect(checkJira, &NoticeBase::timeout, standUp, &NoticeBase::startTimer);

    // Chains the loop between standing up and sitting down
    connect(standUp, &NoticeBase::timeout, sitDown, &NoticeBase::startTimer);
    connect(sitDown, &NoticeBase::timeout, standUp, &NoticeBase::startTimer);

    // Ensures the main window is created before starting the first timer
    QTimer::singleShot(0, this, [this]() { checkEmail->startTimer(); });
}

WorkNotice::~WorkNotice() {}
