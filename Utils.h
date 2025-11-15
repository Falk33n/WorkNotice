#pragma once

// 3rd party includes
#include <QMessageBox>
#include <string>

// Utility class providing common constants and functions
class Utils {
  public:
    static const int THREE_SECONDS = 3 * 1000;
    static const int FIFTEEN_MINUTES = 15 * 60 * 1000;
    static const int ONE_HOUR = 60 * 60 * 1000;
    static const int ONE_SECOND = 1000;

    // Converts milliseconds to a human-readable time string.
    //      @param milliseconds Duration in milliseconds to convert
    //      @return std::string Human-readable duration string
    static std::string millisecondsToTimeString(int milliseconds);

    // Gets the timer duration based on the current build mode
    //      @param productionDuration Duration used in production mode
    //      @return const int Either an accelerated duration for debug mode or the production
    //      duration
    static const int getTimerDuration(const int productionDuration);
};