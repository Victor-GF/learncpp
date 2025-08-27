#include "GameRuntime.h"
#include "Hangman.h"

int main()
{
    GameRuntime::run(
        Hangman::setup,
        Hangman::gameplay,
        Hangman::onFinish);

    return 0;
}