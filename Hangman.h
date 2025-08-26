#ifndef HANGMAN_H
#define HANGMAN_H

#include <bits/types/stack_t.h>
#include <bitset>
#include <functional>
#include <string_view>
#include <vector>

namespace Hangman
{
    /**
     * Stores data for the current session, that means,
     * the current gameplay.
     */
    namespace Session
    {
        constexpr int MAX_WRONG_ATTEMPTS {6};

        // Random word for the user guess
        std::string_view getRandomWord();
        void generateRandomWord();

        // Table with all guesses and non-guessed letters
        const std::vector<bool> &getLettersGuessed();
        const std::size_t saveLetterGuessed(const char letter);
        bool isLetterGuessed(const char letter);

        // Stack with wrong guesses
        const std::vector<char> &getWrongLetterGuesses(); 
        const std::size_t countWrongLetterGuesses();
        void addWrongLetterGuess(const char letterGuess);
    };

    /**
     * Handle all configurations required before the gameplay.
     */
    void setup();

    /**
     * Execute the gameplay, until the game is over.
     */
    void gameplay();

    /**
     * Finish the gameplay
     */
    void endgame();

    void onFinish();
}

#endif