#ifndef BUTTON_EVENT_H
#define BUTTON_EVENT_H

struct ButtonEvent
{
    enum ButtonId
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        A,
        B,
        SELECT,
        MENU,
        NONE
    };

    ButtonId buttonId;
    bool pressed;
};

#endif