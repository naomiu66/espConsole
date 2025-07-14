#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <Arduino.h>

class SoundManager {
public:
    void init();
    void playTone(double freq, unsigned long duration);
    void update();
    void stop();
private:
    static const uint8_t buzzerPin = D6;
    bool playing = false;
    unsigned long endTime = 0;

};

#endif