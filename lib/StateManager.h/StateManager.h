#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

class StateManager {
public:
    enum class State {
        Stopped,
        Running,
        Paused
    };

    bool isRunning() const { return state == State::Running; }
    bool isPaused() const { return state == State::Paused; }
    bool isStopped() const { return state == State::Stopped; }
    State getState() const { return state; }
    void setState(State newState){ state = newState; }
private:
    State state;
};

#endif