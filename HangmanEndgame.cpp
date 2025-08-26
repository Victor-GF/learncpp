#include "GameRuntime.h"
#include "Hangman.h"
#include <iostream>

void Hangman::endgame()
{
    GameRuntime::finish();
}

void Hangman::onFinish()
{
    std::cout << "Bye-bye!\n";
}
