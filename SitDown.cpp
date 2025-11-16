#include "SitDown.h"
#include "WorkDurations.h"

SitDown::SitDown(QObject *parent) : NoticeBase(parent) {}

int SitDown::durationMs() const { return WorkDurations::SIT_DOWN_DURATION; }

QString SitDown::popupButtonText() const { return "I'm Sitting Down"; }

QString SitDown::popupTitle() const { return "Sit Down Reminder"; }

QString SitDown::popupText() const { return "Time to lower your desk and sit down!"; }

NoticeState SitDown::noticeState() const { return NoticeState::SitDown; }