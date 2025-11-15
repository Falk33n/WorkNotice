#pragma once

// Local includes
#include "NoticeState.h"
#include "SitDown.h"
#include "Utils.h"

// 3rd party includes
#include <QObject>
#include <QTimer>

// Handles all the functionality for the stand-up popup
class StandUp : public QObject {
    Q_OBJECT

  public:
    explicit StandUp(SitDown *sitDown, QObject *parent = nullptr);

    // Starts the countdown until the stand-up reminder shows
    // The timer interval is determined by the current build mode
    void startTimer();

    // Stops the stand-up reminder timer
    void stopTimer();

  public slots:
    // Shows the stand-up popup
    void show();

  private slots:
    // Handles timer tick events
    void onTick();

  signals:
    // Emitted when the timer times out
    // Enables communication with other components
    // Without exposing internal timer details
    void timeout();

    // Emitted when the remaining time changes
    void remainingTimeChanged(int seconds);

    // Emitted when the notice state changes
    void stateChanged(NoticeState state);

  private:
    const int INTERVAL = Utils::getTimerDuration(Utils::ONE_HOUR);

    const int DURATION = Utils::getTimerDuration(Utils::FIFTEEN_MINUTES);
    const QString DURATION_TEXT =
        QString("<span style='font-size:10pt;font-weight:normal;'><b>Duration:</b> %1</span>")
            .arg(QString::fromStdString(Utils::millisecondsToTimeString(DURATION)));

    const QString POPUP_TITLE = "Stand Up Reminder";
    const QString POPUP_TEXT = QString("Time to raise your desk and stand up!"
                                       "<br>%1")
                                   .arg(DURATION_TEXT);

    const QString POPUP_BUTTON_TEXT = "I'm Standing Up";

    int remainingSeconds = 0;

    QTimer *tickTimer;
    SitDown *sitDown;
};