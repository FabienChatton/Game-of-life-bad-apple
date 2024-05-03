#include "Game.hpp"
#include "Ihm.hpp"

int main(void)
{
	Ihm ihm;
	Game game(ihm);
	game.InitScreenSize();
	while (game.Process()) { }
	
    return 0;
}