#include "CheckCalendar.h"
#include "WorkDurations.h"

CheckCalendar::CheckCalendar(QObject *parent) : NoticeBase(parent) {}

int CheckCalendar::durationMs() const { return WorkDurations::START_OF_DAY_TASKS_DURATION; }

QString CheckCalendar::popupButtonText() const { return "I'm checking it"; }

QString CheckCalendar::popupTitle() const { return "Check Calendar Reminder"; }

QString CheckCalendar::popupText() const { return "Time to check your Calendar!"; }

NoticeState CheckCalendar::noticeState() const { return NoticeState::CheckCalendar; }