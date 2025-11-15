#pragma once

// Local includes
#include "NoticeState.h"
#include "Utils.h"

// 3rd party includes
#include <QObject>
#include <QTimer>

class StandUp;

// Handles all the functionality for the sit-down popup
class SitDown : public QObject {
    Q_OBJECT

  public:
    explicit SitDown(QObject *parent = nullptr);

    // Starts the countdown until the sit-down reminder shows
    // The timer interval is determined by the current build mode
    void startTimer();

    // Stops the sit-down reminder timer
    void stopTimer();

    // Sets the StandUp instance to communicate with
    void setStandUp(StandUp *standUp);

  public slots:
    // Shows the sit-down popup
    void show();

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
    const int DURATION = Utils::getTimerDuration(Utils::ONE_HOUR);
    const QString DURATION_TEXT =
        QString("<span style='font-size:10pt;font-weight:normal;'><b>Duration:</b> %1</span>")
            .arg(QString::fromStdString(Utils::millisecondsToTimeString(DURATION)));

    const QString POPUP_TITLE = "Sit Down Reminder";
    const QString POPUP_TEXT = QString("Time to lower your desk and sit down!"
                                       "<br>%1")
                                   .arg(DURATION_TEXT);
    const QString POPUP_BUTTON_TEXT = "I'm Sitting Down";

    int remainingSeconds = 0;

    QTimer *tickTimer;
    StandUp *standUp = nullptr;
};