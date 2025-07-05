#include "InputManager.h"

volatile bool InputManager::interruptFlag = false; 

void InputManager::init()
{
    Wire.begin();

    mcp.init();

    mcp.portMode(MCP23017Port::A, 0xFF);
    mcp.writeRegister(MCP23017Register::GPIO_A, 0xFF);
    mcp.writeRegister(MCP23017Register::IPOL_A, 0x00);
    mcp.writeRegister(MCP23017Register::GPINTEN_A, 0xFF); 

    pinMode(INT_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(INT_PIN), handleInterrupt, FALLING);

    mcp.clearInterrupts();
}

void InputManager::update()
{
    if(!interruptFlag) return;
    interruptFlag = false;

    delay(1);

    uint8_t portA, portB, snapA, snapB;
    mcp.interruptedBy(portA, portB);
    mcp.clearInterrupts(snapA, snapB);

    Serial.println("interrupt");

    for(uint8_t i = 0; i < 8; i++)
    {
        bool pressed = !(snapA & (1 << i));
        if(pressed != prevState[i])
        {
            lastEvent = { static_cast<ButtonEvent::ButtonId>(i), pressed };
            prevState[i] = pressed;
            break;
        }
    }
}

bool InputManager::hasEvent() const
{
    return lastEvent.buttonId != ButtonEvent::NONE;
}

ButtonEvent InputManager::getEvent()
{
    ButtonEvent currentEvent = lastEvent;
    lastEvent = {ButtonEvent::NONE, false};
    return currentEvent;
}

IRAM_ATTR void InputManager::handleInterrupt()
{
    interruptFlag = true;
}
