#include "NoticeBase.h"
#include "StyledMessageBox.h"
#include "WorkDurations.h"

NoticeBase::NoticeBase(QObject *parent) : QObject(parent) {
    remainingSeconds = 0;
    // Initialize timer and connect its timeout signal
    tickTimer = new QTimer(this);
    connect(tickTimer, &QTimer::timeout, this, &NoticeBase::onTick);
}

void NoticeBase::startTimer() {
    emit stateChanged(noticeState());
    showPopup();

    // Compute countdown
    remainingSeconds = durationMs() / WorkDurations::ONE_SECOND_IN_MS;
    emit remainingTimeChanged(remainingSeconds);

    tickTimer->start(WorkDurations::ONE_SECOND_IN_MS);
}

void NoticeBase::stopTimer() { tickTimer->stop(); }

void NoticeBase::onTick() {
    remainingSeconds--;
    emit remainingTimeChanged(remainingSeconds);

    if (remainingSeconds <= 0) {
        // Timeout changes it to the next state
        stopTimer();
        emit timeout();
    }
}

void NoticeBase::showPopup() const {
    StyledMessageBox popup(popupTitle(), popupText(), popupButtonText());
}
