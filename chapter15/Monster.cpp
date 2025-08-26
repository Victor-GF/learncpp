#include "Monster.h"

constexpr std::string_view Monster::getTypeString() const
{
    switch (m_type)
    {
    case Type::dragon:
        return "dragon";
    case Type::goblin:
        return "goblin";
    case Type::ogre:
        return "ogre";
    case Type::orc:
        return "orc";
    case Type::skeleton:
        return "skeleton";
    case Type::troll:
        return "troll";
    case Type::vampire:
        return "vampire";
    case Type::zombie:
        return "zombie";
    default:
        return "?";
    }
}

void Monster::print() const
{
    if (m_hitPoints > 0)
    {
        std::cout
            << m_name << " the " << getTypeString()
            << " has " << m_hitPoints
            << " hit points and says " << m_roar << ".\n";
    }
    else
    {
        std::cout
            << m_name << " the " << getTypeString()
            << " is dead.\n";
    }
}
