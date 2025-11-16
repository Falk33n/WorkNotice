#include "WorkNotice.h"

WorkNotice::WorkNotice(MainWindow *_mainWindow, QWidget *parent)
    : QWidget(parent), mainWindow(_mainWindow) {
    // Create the different notice states
    checkMailInbox = new CheckMailInbox(this);
    checkJira = new CheckJira(this);
    checkGitLab = new CheckGitLab(this);
    checkCalendar = new CheckCalendar(this);
    sitDown = new SitDown(this);
    standUp = new StandUp(this);

    // Connect the timers and state changes to the main window
    std::vector<NoticeBase *> notices = {checkMailInbox, checkCalendar, checkJira, checkGitLab, sitDown, standUp};
    for (auto notice : notices) {
        connect(notice, &NoticeBase::remainingTimeChanged, mainWindow,
                &MainWindow::updateRemainingTime);
        connect(notice, &NoticeBase::stateChanged, mainWindow, &MainWindow::updateWorkState);
    }

    // Chain so that the timers start one after another
    std::vector<NoticeBase *> chain = {checkMailInbox, checkCalendar, checkJira, checkGitLab, standUp};
    for (size_t i = 0; i < chain.size() - 1; ++i) {
        NoticeBase *nextInChain = chain[i + 1];
        connect(chain[i], &NoticeBase::timeout, nextInChain, &NoticeBase::startTimer);
    }

    // Chains the loop between standing up and sitting down
    connect(standUp, &NoticeBase::timeout, sitDown, &NoticeBase::startTimer);
    connect(sitDown, &NoticeBase::timeout, standUp, &NoticeBase::startTimer);

    // Ensures the main window is created before starting the first timer
    QTimer::singleShot(0, this, [this]() { checkMailInbox->startTimer(); });
}

WorkNotice::~WorkNotice() {}
