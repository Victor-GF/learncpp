#ifndef MONSTER_GENERATOR_H
#define MONSTER_GENERATOR_H

#include "Monster.h"
#include <string_view>

namespace MonsterGenerator
{
    using RandomName = std::string_view;
    using RandomRoar = std::string_view;

    // Generates a random monster
    Monster generate();

    constexpr RandomName getName(const int nameId);
    constexpr RandomRoar getRoar(const int roarId);
}

#endif
