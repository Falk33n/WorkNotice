// Local includes
#include "Utils.h"

std::string Utils::millisecondsToTimeString(int milliseconds) {
    constexpr int MILLISECONDS_PER_SECOND = 1000;
    constexpr int SECONDS_PER_MINUTE = 60;
    constexpr int MINUTES_PER_HOUR = 60;

    int totalSeconds = milliseconds / MILLISECONDS_PER_SECOND;

    if (totalSeconds < SECONDS_PER_MINUTE) {
        // If duration is less than one minute show in seconds
        return std::to_string(totalSeconds) + " second" + (totalSeconds == 1 ? "" : "s");
    }

    int totalMinutes = totalSeconds / SECONDS_PER_MINUTE;

    if (totalMinutes < MINUTES_PER_HOUR) {
        // If duration is less than 1 hour show in minutes
        return std::to_string(totalMinutes) + " minute" + (totalMinutes == 1 ? "" : "s");
    } else {
        // If duration is 1 hour or more show hours and remaining minutes
        int hours = totalMinutes / MINUTES_PER_HOUR;
        int minutes = totalMinutes % MINUTES_PER_HOUR;

        std::string result = std::to_string(hours) + " hour" + (hours == 1 ? "" : "s");
        if (minutes > 0) {
            result += " and " + std::to_string(minutes) + " minute" + (minutes == 1 ? "" : "s");
        }

        return result;
    }
}

const int Utils::getTimerDuration(const int productionDuration) {
#ifdef QT_DEBUG
    const int THREE_SECONDS = 3 * 1000;
    return THREE_SECONDS;
#else
    return productionDuration;
#endif
}
