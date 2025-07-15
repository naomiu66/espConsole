#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <Game.h>
#include <Display.h>


class PongGame : public Game {
public:
    void init(Display *display) override;
    void update() override;
    ~PongGame() = default;
    PongGame() {}
    bool isFinished() override;
private:
    bool gameOver = false;
    int player1Score = 0;
    int player2Score = 0;
};

#endif