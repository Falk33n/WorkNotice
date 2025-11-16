#pragma once

#include "NoticeState.h"
#include "QTimer"

// Base class for different notice states
class NoticeBase : public QObject {
    Q_OBJECT

  public:
    explicit NoticeBase(QObject *parent = nullptr);
    virtual ~NoticeBase() = default;

    // Starts the timer and triggers the popup
    void startTimer();

    // Stops the timer
    void stopTimer();

    // Subclasses define these

    // Gets the duration of the notice in milliseconds
    virtual int durationMs() const = 0;

    // Gets the text for the popup button
    virtual QString popupButtonText() const = 0;

    // Gets the title for the popup
    virtual QString popupTitle() const = 0;

    // Gets the main text for the popup
    virtual QString popupText() const = 0;

    // Changes the notice state
    virtual NoticeState noticeState() const = 0;

  protected slots:
    // Handles timer tick events
    void onTick();

  signals:
    // Emitted when the timer times out
    void timeout();

    // Emitted when the remaining time changes
    //    @param seconds Remaining seconds
    void remainingTimeChanged(int seconds);

    // Emitted when the notice state changes
    //   @param state The new notice state
    void stateChanged(NoticeState state);

private:
    // Gets an readable remaining time text for the popup
    QString getDurationText() const;

    // Combines the popup text with the duration text
    QString combinePopupText() const;

  protected:
    // Shows the popup
    void showPopup() const;

    int remainingSeconds;
    int calculatedDurationMs;
    QTimer *tickTimer;
};