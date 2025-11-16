#pragma once

// TODO: Make these configurable by the user
// Time constants in milliseconds
class WorkDurations {
  public:
    static constexpr int ONE_SECOND_IN_MS = 1000;
    static constexpr int SECONDS_PER_MINUTE = 60;
    static constexpr int MINUTES_PER_HOUR = 60;
    static constexpr int ONE_MINUTE_IN_MS = ONE_SECOND_IN_MS * SECONDS_PER_MINUTE;

    // 20 minutes recommended by health experts
    static constexpr int STAND_UP_DURATION = ONE_MINUTE_IN_MS * 20;

    // 40 minutes recommended by health experts
    static constexpr int SIT_DOWN_DURATION = ONE_MINUTE_IN_MS * 40;

    // 3 minutes for start-of-day tasks such as checking mail inbox and
    // calendar and gitlab and jira
    static constexpr int START_OF_DAY_TASKS_DURATION = ONE_MINUTE_IN_MS * 3;
};