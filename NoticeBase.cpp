#include "NoticeBase.h"
#include "StyledMessageBox.h"
#include "Utils.h"
#include "WorkDurations.h"

NoticeBase::NoticeBase(QObject *parent) : QObject(parent) {
    remainingSeconds = 0;
    // Initialize timer and connect its timeout signal
    tickTimer = new QTimer(this);
    connect(tickTimer, &QTimer::timeout, this, &NoticeBase::onTick);
}

void NoticeBase::startTimer() {
    calculatedDurationMs = Utils::getTimerDuration(durationMs());
    emit stateChanged(noticeState());
    showPopup();

    // Compute countdown
    remainingSeconds = calculatedDurationMs / WorkDurations::ONE_SECOND_IN_MS;
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

QString NoticeBase::getDurationText() const {
    const QString durationConvertedText =
        QString::fromStdString(Utils::millisecondsToTimeString(calculatedDurationMs));

    return QString("<span style='font-size:10pt;font-weight:normal;'>"
                   "<b>Duration:</b> "
                   "%1</span>")
        .arg(durationConvertedText);
}

QString NoticeBase::combinePopupText() const {
    const QString durationText = getDurationText();
    return QString("%1<br>%2").arg(popupText(), durationText);
}

void NoticeBase::showPopup() const {
    StyledMessageBox popup(popupTitle(), combinePopupText(), popupButtonText());
}
