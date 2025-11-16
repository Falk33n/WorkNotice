#include "MainWindow.h"
#include "Utils.h"
#include "WorkDurations.h"
#include <QVBoxLayout>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), TIMER_ZERO_TEXT("Time to check your Mail Inbox!"),
      TIMER_UPDATE_TEXT("Keep checking your Mail Inbox for another %1"),
      INITIAL_TEXT(TIMER_ZERO_TEXT), TITLE("Work Notice") {
    createWindow();
    addLabel();
}

MainWindow::~MainWindow() {}

void MainWindow::createWindow() {
    setFixedSize(550, 50);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setWindowTitle(TITLE);
}

void MainWindow::addLabel() {
    label = new QLabel(INITIAL_TEXT, this);
    label->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
}

void MainWindow::updateRemainingTime(int seconds) {
    if (seconds == 0) {
        // Sometimes the TIMER_ZERO_TEXT does not update in time
        // Therefore we wait until the event loop is free to update the label
        QTimer::singleShot(0, this, [this]() { label->setText(TIMER_ZERO_TEXT); });
        return;
    }

    const int SECONDS_IN_MILLISECONDS = seconds * WorkDurations::ONE_SECOND_IN_MS;
    label->setText(TIMER_UPDATE_TEXT.arg(Utils::millisecondsToTimeString(SECONDS_IN_MILLISECONDS)));
}

void MainWindow::updateWorkState(NoticeState state) {
    switch (state) {
    case NoticeState::SitDown:
        TIMER_ZERO_TEXT = "Time to lower your desk and sit down!";
        TIMER_UPDATE_TEXT = "Keep sitting for another %1";
        break;
    case NoticeState::StandUp:
        TIMER_ZERO_TEXT = "Time to raise your desk and stand up!";
        TIMER_UPDATE_TEXT = "Keep standing for another %1";
        break;
    case NoticeState::CheckMailInbox:
        TIMER_ZERO_TEXT = "Time to check your Mail Inbox!";
        TIMER_UPDATE_TEXT = "Keep checking your Mail Inbox for another %1";
        break;
    case NoticeState::CheckJira:
        TIMER_ZERO_TEXT = "Time to check your Jira!";
        TIMER_UPDATE_TEXT = "Keep checking your Jira for another %1";
        break;
    case NoticeState::CheckGitLab:
        TIMER_ZERO_TEXT = "Time to check your GitLab!";
        TIMER_UPDATE_TEXT = "Keep checking your GitLab for another %1";
        break;
    case NoticeState::CheckCalendar:
        TIMER_ZERO_TEXT = "Time to check your Calendar!";
        TIMER_UPDATE_TEXT = "Keep checking your Calendar for another %1";
        break;
    }
}