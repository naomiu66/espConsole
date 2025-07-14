#ifndef BUTTON_EVENT_H
#define BUTTON_EVENT_H

struct ButtonEvent
{
    enum ButtonId
    {
        NONE = -1,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        A,
        B,
        SELECT,
        MENU
    };

    ButtonId buttonId;
    bool pressed;
};

#endif