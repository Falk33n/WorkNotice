#pragma once

#include <QObject>
#include <QSoundEffect>

class AlertSound : public QObject
{
    Q_OBJECT

public:
    explicit AlertSound(QObject* parent = nullptr);
    void play();

private:
    QSoundEffect* sound;
    void initializeSound();
};