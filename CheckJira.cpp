#include "CheckJira.h"
#include "WorkDurations.h"

CheckJira::CheckJira(QObject *parent) : NoticeBase(parent) {}

int CheckJira::durationMs() const { return WorkDurations::START_OF_DAY_TASKS_DURATION; }

QString CheckJira::popupButtonText() const { return "I'm checking it"; }

QString CheckJira::popupTitle() const { return "Check Jira Reminder"; }

QString CheckJira::popupText() const { return "Time to check your Jira!"; }

NoticeState CheckJira::noticeState() const { return NoticeState::CheckJira; }