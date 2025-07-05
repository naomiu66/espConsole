#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <ButtonEvent.h>
#include <Wire.h>
#include <MCP23017.h>

class InputManager{

public:
    void init();
    void update();
    bool hasEvent() const;
    ButtonEvent getEvent();

    static volatile bool interruptFlag;

    static void IRAM_ATTR handleInterrupt();
private:
    static const uint8_t INT_PIN = D4;
    MCP23017 mcp = MCP23017(0x20);
    ButtonEvent lastEvent = {ButtonEvent::NONE, false};
    bool prevState[8] = {true};
};

#endif