#include <SoundManager.h>

void SoundManager::init()
{
    pinMode(buzzerPin, OUTPUT);
}

void SoundManager::playTone(double freq, unsigned long duration)
{
    tone(buzzerPin, freq, duration);
    endTime = millis() + duration;
    playing = true;
}

void SoundManager::update()
{
    if(playing && (millis() >= endTime))
    {
        stop();
    }
}

void SoundManager::stop()
{
    noTone(buzzerPin);
    playing = false;
}