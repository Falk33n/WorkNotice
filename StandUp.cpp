#include "StandUp.h"
#include "WorkDurations.h"
#include "Utils.h"

StandUp::StandUp(QObject *parent) : NoticeBase(parent) {}

int StandUp::durationMs() const {
    return Utils::getTimerDuration(WorkDurations::STAND_UP_DURATION);
}

QString StandUp::popupButtonText() const { return "I'm Standing Up"; }

QString StandUp::popupTitle() const { return "Stand Up Reminder"; }

QString StandUp::popupText() const {
    const QString durationConvertedText =
        QString::fromStdString(Utils::millisecondsToTimeString(durationMs()));

    const QString durationText = QString("<span style='font-size:10pt;font-weight:normal;'>"
                                         "<b>Duration:</b> "
                                         "%1</span>")
                                     .arg(durationConvertedText);

    return QString("Time to raise your desk and stand up!"
                         "<br>%1")
        .arg(durationText);
}

NoticeState StandUp::noticeState() const { return NoticeState::StandUp; }