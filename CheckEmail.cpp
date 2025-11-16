#include "CheckEmail.h"
#include "Utils.h"
#include "WorkDurations.h"

CheckEmail::CheckEmail(QObject *parent) : NoticeBase(parent) {}

int CheckEmail::durationMs() const {
    return Utils::getTimerDuration(WorkDurations::START_OF_DAY_TASKS_DURATION);
}

QString CheckEmail::popupButtonText() const { return "I'm checking it"; }

QString CheckEmail::popupTitle() const { return "Check Email and Calendar Reminder"; }

QString CheckEmail::popupText() const {
    const QString durationConvertedText =
        QString::fromStdString(Utils::millisecondsToTimeString(durationMs()));

    const QString durationText = QString("<span style='font-size:10pt;font-weight:normal;'>"
                                         "<b>Duration:</b> "
                                         "%1</span>")
                                     .arg(durationConvertedText);

    return QString("Time to check your Mail Inbox and Calendar!"
                   "<br>%1")
        .arg(durationText);
}

NoticeState CheckEmail::noticeState() const { return NoticeState::CheckEmail; }