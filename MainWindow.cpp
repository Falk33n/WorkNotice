// Local includes
#include "MainWindow.h"
#include "StandUp.h"
#include "Utils.h"

// 3rd party includes
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    createWindow();
    addLabel();
}

MainWindow::~MainWindow() {}

void MainWindow::createWindow() {
    setFixedSize(450, 50);
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
        label->setText(TIMER_ZERO_TEXT);
        return;
    }

    const int SECONDS_IN_MILLISECONDS = seconds * 1000;
    label->setText(TIMER_UPDATE_TEXT.arg(Utils::millisecondsToTimeString(SECONDS_IN_MILLISECONDS)));
}

void MainWindow::updateWorkState(NoticeState state) {
    switch (state) {
    case NoticeState::SitDown:
        TIMER_ZERO_TEXT = "Time to lower your desk and sit down!";
        TIMER_UPDATE_TEXT = "Next sit down reminder in %1";
        break;
    case NoticeState::StandUp:
        TIMER_ZERO_TEXT = "Time to raise your desk and stand up!";
        TIMER_UPDATE_TEXT = "Next stand up reminder in %1";
        break;
    }
}