#include "Game.hpp"
#include "Ihm.hpp"
#include "Cell.hpp"
#include "Pos.hpp"
#include "Grid.hpp"

#include <iostream>
#include <vector>

int main(void)
{
	Ihm ihm;
	Game game(ihm);
	while (game.Process()) { }
    return 0;
}