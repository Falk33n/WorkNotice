#pragma once

#include "NoticeBase.h"

// Handles all the functionality for the stand-up popup
class StandUp : public NoticeBase {
    Q_OBJECT

  public:
    explicit StandUp(QObject *parent = nullptr);

    // Functions to retrieve the different state configurations

    // Gets the duration of the notice in milliseconds
    int durationMs() const override;

    // Gets the text for the popup button
    QString popupButtonText() const override;

    // Gets the title for the popup
    QString popupTitle() const override;

    // Gets the main text for the popup
    QString popupText() const override;

    // Changes the notice state
    NoticeState noticeState() const override;
};