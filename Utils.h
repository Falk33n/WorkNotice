#pragma once

#include <string>

// Utility class providing common constants and functions
class Utils {
  public:
    // Converts milliseconds to a human-readable time string.
    //      @param milliseconds Duration to convert
    //      @return std::string Human-readable duration string
    static std::string millisecondsToTimeString(int milliseconds);

    // Gets the timer duration based on the current build mode
    //      @param productionDuration Duration used in production mode
    //      @return const int Either an accelerated duration for debug mode or the production
    //      duration
    static const int getTimerDuration(const int productionDuration);

  private:
    // Converts milliseconds to a human-readable time string.
    //      @param totalMinutes Total minutes in the duration
    //      @return std::string Human-readable duration string
    static std::string milliSecondsToHoursMinutesString(int totalMinutes);

    // Converts milliseconds to a human-readable time string.
    //      @param totalMinutes Total minutes in the duration
    //      @param remainingSeconds Remaining seconds in the duration
    //      @return std::string Human-readable duration string
    static std::string milliSecondsToMinutesSecondsString(int totalMinutes, int remainingSeconds);

    // Converts milliseconds to a human-readable time string.
    //      @param totalSeconds Total seconds in the duration
    //      @return std::string Human-readable duration string
    static std::string milliSecondsToSecondsString(int totalSeconds);
};