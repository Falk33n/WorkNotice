// Local includes
#include "StandUp.h"
#include "StyledMessageBox.h"
#include "Utils.h"

StandUp::StandUp(SitDown *_sitDown, QObject *parent) : QObject(parent), sitDown(_sitDown) {
    // Initialize timer and connect its timeout signal
    tickTimer = new QTimer(this);

    // Triggers stand-up popup
    connect(tickTimer, &QTimer::timeout, this, &StandUp::onTick);
}

void StandUp::startTimer() {
    remainingSeconds = INTERVAL / Utils::ONE_SECOND;
    emit remainingTimeChanged(remainingSeconds);
    emit stateChanged(NoticeState::StandUp);
    tickTimer->start(Utils::ONE_SECOND);
}

void StandUp::stopTimer() { tickTimer->stop(); }

void StandUp::onTick() {
    remainingSeconds--;

    emit remainingTimeChanged(remainingSeconds);

    if (remainingSeconds <= 0) {
        stopTimer();
        show();
    }
}

void StandUp::show() {
    // Creates and styles the message box
    StyledMessageBox createPopup(POPUP_TITLE, POPUP_TEXT, POPUP_BUTTON_TEXT);

    // Pause the stand-up timer and start the sit-down timer
    if (sitDown)
        sitDown->startTimer();

    emit timeout();
}