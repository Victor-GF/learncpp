#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

class Monster
{
public:
    // Owners
    using Name = std::string;
    using Roar = std::string;
    using HitPoints = int;
    enum class Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes,
    };

    // Viewers
    using RoarView = std::string_view;
    using NameView = std::string_view;

private:
    Type m_type{};
    Name m_name{};
    Roar m_roar{};
    HitPoints m_hitPoints{};

public:
    Monster(Type type,
            NameView name,
            RoarView roar,
            HitPoints hitPoints)
        : m_type(type),
          m_name(name),
          m_roar(roar),
          m_hitPoints(hitPoints)
    { }

    constexpr std::string_view getTypeString() const;
    void print() const;
};

#endif