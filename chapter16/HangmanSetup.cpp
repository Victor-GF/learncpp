#include "Hangman.h"
#include <iostream>

void Hangman::setup()
{
    Session::generateRandomWord();

    std::cout << "Welcome to C++man (a variant of Hangman)\n"
              << "To win: guess the word.  To lose: run out of pluses.\n"
              << '\n';

}