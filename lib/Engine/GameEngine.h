#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <ScreenManager.h>
#include <InputManager.h>
#include <SoundManager.h>
#include <Display.h>
#include <Screens/SnakeGameScreen/SnakeGameScreen.h>

class GameEngine {
public:
    enum class State {
        Stopped,
        Running,
        Paused
    };

    GameEngine(ScreenManager* _screenManager, InputManager* _inputManager, SoundManager* _soundManager, Display* _display)
        : screenManager(_screenManager),
          inputManager(_inputManager),
          soundManager(_soundManager),
          display(_display),
          state(State::Stopped) {}

    void start() { state = State::Running; }
    void stop() { state = State::Stopped; }
    void pause() { if (state == State::Running) state = State::Paused; }
    void resume() { if (state == State::Paused) state = State::Running; }

    void init() {
        if (inputManager) inputManager->init();
        if (soundManager) soundManager->init();
        if (screenManager) screenManager->setScreen(new MainScreen(inputManager, soundManager, display, screenManager));
        if (display) display->init();
        state = State::Running;
    }
    void update() {
        if (state != State::Running) return;
        if (inputManager) inputManager->update();
        if (soundManager) soundManager->update();
        if (screenManager) screenManager->update();
    }
    void render() {
        if (state != State::Running) return;
        if (screenManager) screenManager->render();
    }
    bool isRunning() const { return state == State::Running; }
    bool isPaused() const { return state == State::Paused; }
    bool isStopped() const { return state == State::Stopped; }
    State getState() const { return state; }
private:
    ScreenManager* screenManager;
    InputManager* inputManager;
    SoundManager* soundManager;
    Display* display;
    State state;
};

#endif