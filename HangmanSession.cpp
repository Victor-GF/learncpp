#include "Hangman.h"
#include <vector>
#include "Random.h"

namespace Hangman
{
    constexpr char DEFAULT_SLOT_WRONG_ATTEMPT = '+';

    std::vector<std::string_view> predefinedWords{
        "mystery", "broccoli", "account",
        "almost", "spaghetti", "opinion",
        "beautiful", "distance", "luggage"};

    std::string_view randomWord{predefinedWords[0]};

    // A table to store the information if some letter was guessed
    std::vector<bool> lettersGuessed(26);

    // A stack to store the user's wrong guesses.
    std::vector<char> wrongLetterGuesses(Session::MAX_WRONG_ATTEMPTS, DEFAULT_SLOT_WRONG_ATTEMPT);

    inline std::size_t hashChar(const char c)
    {
        return static_cast<std::size_t>((c % 32) - 1);
    }
}

std::string_view Hangman::Session::getRandomWord()
{
    return randomWord;
}

void Hangman::Session::generateRandomWord()
{
    randomWord = predefinedWords[Random::get(0, predefinedWords.size() - 1)];
}

const std::vector<bool> &Hangman::Session::getLettersGuessed()
{
    return lettersGuessed;
}

/**
 * Save letter guessed and returns its ID.
 */
const std::size_t Hangman::Session::saveLetterGuessed(const char letter)
{
    const auto hash{hashChar(letter)};
    lettersGuessed[hash] = true;

    return hash;
}

bool Hangman::Session::isLetterGuessed(const char letter)
{
    return lettersGuessed[hashChar(letter)];
}

const std::vector<char> &Hangman::Session::getWrongLetterGuesses()
{
    return wrongLetterGuesses;
}

const std::size_t Hangman::Session::countWrongLetterGuesses() 
{
    std::size_t count{0};

    for (const auto c : wrongLetterGuesses)
    {
        if (c != DEFAULT_SLOT_WRONG_ATTEMPT)
            count++;
    }

    return count;
}

void Hangman::Session::addWrongLetterGuess(const char letterGuess)
{
    for (int i{0}; i < MAX_WRONG_ATTEMPTS; ++i)
    {
        if (wrongLetterGuesses[i] == DEFAULT_SLOT_WRONG_ATTEMPT)
        {
            wrongLetterGuesses[i] = letterGuess;
            break;
        }
    }
}
