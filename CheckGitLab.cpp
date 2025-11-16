#include "CheckGitLab.h"
#include "WorkDurations.h"

CheckGitLab::CheckGitLab(QObject *parent) : NoticeBase(parent) {}

int CheckGitLab::durationMs() const { return WorkDurations::START_OF_DAY_TASKS_DURATION; }

QString CheckGitLab::popupButtonText() const { return "I'm checking it"; }

QString CheckGitLab::popupTitle() const { return "Check GitLab Reminder"; }

QString CheckGitLab::popupText() const { return "Time to check your GitLab!"; }

NoticeState CheckGitLab::noticeState() const { return NoticeState::CheckGitLab; }