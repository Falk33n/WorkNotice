// Local includes
#include "SitDown.h"
#include "StandUp.h"
#include "StyledMessageBox.h"
#include "Utils.h"

SitDown::SitDown(QObject *parent) : QObject(parent), standUp(nullptr) {
    // Initialize timer and connect its timeout signal
    tickTimer = new QTimer(this);
    connect(tickTimer, &QTimer::timeout, this, &SitDown::onTick);
}

void SitDown::setStandUp(StandUp *_standUp) { standUp = _standUp; }

void SitDown::startTimer() {
    remainingSeconds = DURATION / Utils::ONE_SECOND;
    emit remainingTimeChanged(remainingSeconds);
    emit stateChanged(NoticeState::SitDown);
    tickTimer->start(Utils::ONE_SECOND);
}

void SitDown::stopTimer() { tickTimer->stop(); }

void SitDown::onTick() {
    remainingSeconds--;

    emit remainingTimeChanged(remainingSeconds);

    if (remainingSeconds <= 0) {
        stopTimer();
        show();
    }
}

void SitDown::show() {
    // Creates and styles the message box
    StyledMessageBox createPopup(POPUP_TITLE, POPUP_TEXT, POPUP_BUTTON_TEXT);

    // Pause the sit-down timer and start the stand-up timer
    if (standUp)
        standUp->startTimer();

    emit timeout();
}