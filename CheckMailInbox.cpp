#include "CheckMailInbox.h"
#include "WorkDurations.h"

CheckMailInbox::CheckMailInbox(QObject *parent) : NoticeBase(parent) {}

int CheckMailInbox::durationMs() const { return WorkDurations::START_OF_DAY_TASKS_DURATION; }

QString CheckMailInbox::popupButtonText() const { return "I'm checking it"; }

QString CheckMailInbox::popupTitle() const { return "Check Mail Inbox Reminder"; }

QString CheckMailInbox::popupText() const { return "Time to check your Mail Inbox!"; }

NoticeState CheckMailInbox::noticeState() const { return NoticeState::CheckMailInbox; }