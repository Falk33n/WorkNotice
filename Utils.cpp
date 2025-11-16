#include "Utils.h"
#include "WorkDurations.h"

std::string Utils::milliSecondsToSecondsString(int totalSeconds) {
    return std::to_string(totalSeconds) + " second" + (totalSeconds == 1 ? "" : "s");
}

std::string Utils::milliSecondsToMinutesSecondsString(int totalMinutes, int remainingSeconds) {
    std::string result = std::to_string(totalMinutes) + " minute" + (totalMinutes == 1 ? "" : "s");
    if (remainingSeconds > 0) {
        result += " and " + std::to_string(remainingSeconds) + " second" +
                  (remainingSeconds == 1 ? "" : "s");
    }
    return result;
}

std::string Utils::milliSecondsToHoursMinutesString(int totalMinutes) {
    int hours = totalMinutes / WorkDurations::MINUTES_PER_HOUR;
    int minutes = totalMinutes % WorkDurations::MINUTES_PER_HOUR;

    std::string result = std::to_string(hours) + " hour" + (hours == 1 ? "" : "s");
    if (minutes > 0) {
        result += " and " + std::to_string(minutes) + " minute" + (minutes == 1 ? "" : "s");
    }
    return result;
}

std::string Utils::millisecondsToTimeString(int milliseconds) {
    int totalSeconds = milliseconds / WorkDurations::ONE_SECOND_IN_MS;
    int totalMinutes = totalSeconds / WorkDurations::SECONDS_PER_MINUTE;

    // If duration is less than one minute show in seconds
    if (totalSeconds < WorkDurations::SECONDS_PER_MINUTE) {
        return milliSecondsToSecondsString(totalSeconds);
    }
    // If duration is less than 1 hour show in minutes and seconds
    if (totalMinutes < WorkDurations::MINUTES_PER_HOUR) {
        int remainingSeconds = totalSeconds % WorkDurations::SECONDS_PER_MINUTE;
        return milliSecondsToMinutesSecondsString(totalMinutes, remainingSeconds);
    }
    // If duration is 1 hour or more show in hours and minutes
    return milliSecondsToHoursMinutesString(totalMinutes);
}

const int Utils::getTimerDuration(const int productionDuration) {
#ifndef QT_NO_DEBUG
    const int THREE_SECONDS = WorkDurations::ONE_SECOND_IN_MS * 3;
    return THREE_SECONDS;
#else
    return productionDuration;
#endif
}
