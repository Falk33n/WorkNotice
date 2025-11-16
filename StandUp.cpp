#include "StandUp.h"
#include "WorkDurations.h"

StandUp::StandUp(QObject *parent) : NoticeBase(parent) {}

int StandUp::durationMs() const { return WorkDurations::STAND_UP_DURATION; }

QString StandUp::popupButtonText() const { return "I'm Standing Up"; }

QString StandUp::popupTitle() const { return "Stand Up Reminder"; }

QString StandUp::popupText() const { return "Time to raise your desk and stand up!"; }

NoticeState StandUp::noticeState() const { return NoticeState::StandUp; }