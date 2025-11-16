#include "CheckJira.h"
#include "Utils.h"
#include "WorkDurations.h"

CheckJira::CheckJira(QObject *parent) : NoticeBase(parent) {}

int CheckJira::durationMs() const {
    return Utils::getTimerDuration(WorkDurations::START_OF_DAY_TASKS_DURATION);
}

QString CheckJira::popupButtonText() const { return "I'm checking it"; }

QString CheckJira::popupTitle() const { return "Check Jira Reminder"; }

QString CheckJira::popupText() const {
    const QString durationConvertedText =
        QString::fromStdString(Utils::millisecondsToTimeString(durationMs()));

    const QString durationText = QString("<span style='font-size:10pt;font-weight:normal;'>"
                                         "<b>Duration:</b> "
                                         "%1</span>")
                                     .arg(durationConvertedText);

    return QString("Time to check your Jira!"
                   "<br>%1")
        .arg(durationText);
}

NoticeState CheckJira::noticeState() const { return NoticeState::CheckJira; }