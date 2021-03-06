#pragma once

#include <Windows.h>
#include <string>
#include <iostream>
#include "player.h"

constexpr int LENGTH = 10;
constexpr int HEIGHT = 10;

enum Color {
    BLACK, BLUE, GREEN, CYAN, RED,
    MAGENTA, BROWN, LGRAY, DGRAY, LBLUE,
    LGREEN, LCYAN, LRED, LMAGENTA, YELLOW, WHITE
};

constexpr WORD colors[4] = {
    Color::MAGENTA, Color::LMAGENTA, Color::LBLUE,
    Color::BLUE
};


void resetCaretPos();
void hideCursor(HANDLE& handle);

class Game
{
    std::string consoleOutput;
    HANDLE handle;
    int colorIndex, renderTicks, updateTicks;
    Player* player;
    int* input;

    void initialize();

    void restart();

    bool usedPositions[LENGTH * HEIGHT] = {false};

public:
    
    Game(HANDLE& p_handle, int* p_input);
    void update();

    void render();
};