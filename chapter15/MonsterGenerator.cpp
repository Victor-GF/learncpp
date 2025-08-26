#include "MonsterGenerator.h"
#include <array>
#include "Random.h"

namespace
{
    // Custom names to generate based on ID
    constexpr std::array<MonsterGenerator::RandomName, 6> customNames = {
        "Blarg", "Strix", "Vamp",
        "Hulk", "Beast", "Shrek"};

    // Custom roars to generate based on ID
    constexpr std::array<MonsterGenerator::RandomRoar, 6> customRoars = {
        "*ROAR*", "*Auuuuu*", "*Zoix*",
        "*HULK SMASH*", "*OOOO*", "*Brainz*"};
}

Monster MonsterGenerator::generate()
{
    const int randomNameId{Random::get(0, 5)};
    const int randomRoarId{Random::get(0, 5)};
    const int randomHitPoints{Random::get(0, 100)}; // 0 - 100
    const int randomType{Random::get(1, static_cast<int>(Monster::Type::maxMonsterTypes) - 1)};
    return {
        static_cast<Monster::Type>(randomType),
        MonsterGenerator::getName(randomNameId),
        MonsterGenerator::getRoar(randomRoarId),
        randomHitPoints};
}

constexpr MonsterGenerator::RandomName MonsterGenerator::getName(const int nameId)
{
    return ((nameId >= 0 && nameId < customNames.size()) ? customNames[nameId] : "?");
}

constexpr MonsterGenerator::RandomRoar MonsterGenerator::getRoar(const int roarId)
{
    return ((roarId >= 0 && roarId < customRoars.size()) ? customRoars[roarId] : "?");
}
