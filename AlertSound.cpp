#include "AlertSound.h"
#include <QUrl>
#include <QTimer>

AlertSound::AlertSound(QObject* parent)
    : QObject(parent)
{
    sound = nullptr;
    initializeSound();
}

void AlertSound::initializeSound()
{
    const float EIGHTY_PERCENT = 0.8f;
    const QString SOURCE = "qrc:/WorkNotice/alert.wav";

    sound = new QSoundEffect(this);
    sound->setSource(QUrl(SOURCE));
    sound->setVolume(EIGHTY_PERCENT);
}

void AlertSound::play()
{
    if (sound)
        sound->play();
}