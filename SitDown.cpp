#include "SitDown.h"
#include "WorkDurations.h"
#include "Utils.h"

SitDown::SitDown(QObject *parent) : NoticeBase(parent) {}

int SitDown::durationMs() const {
    return Utils::getTimerDuration(WorkDurations::SIT_DOWN_DURATION);
}

QString SitDown::popupButtonText() const { return "I'm Sitting Down"; }

QString SitDown::popupTitle() const { return "Sit Down Reminder"; }

QString SitDown::popupText() const {
    const QString durationConvertedText =
        QString::fromStdString(Utils::millisecondsToTimeString(durationMs()));

    const QString durationText = QString("<span style='font-size:10pt;font-weight:normal;'>"
                                         "<b>Duration:</b> "
                                         "%1</span>")
                                     .arg(durationConvertedText);

    return QString("Time to lower your desk and sit down!"
                         "<br>%1")
        .arg(durationText);
}

NoticeState SitDown::noticeState() const { return NoticeState::SitDown; }