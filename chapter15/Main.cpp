#include <iostream>
#include <string>
#include <string_view>
#include "Monster.h"
#include "MonsterGenerator.h"

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}