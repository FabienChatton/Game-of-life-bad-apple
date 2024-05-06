#ifndef GAME_HPP
#define GAME_HPP

#include "Ihm.hpp"
#include "Grid.hpp"

#include <vector>
#include <chrono>
#include <ctime>

class Game {

public:
	Game(const Ihm &ihm);
	~Game();
	bool Process();

private:
	Ihm ihm;
	Grid grid;

	std::chrono::time_point<std::chrono::system_clock> last_process_next;

};

#endif // GAME_HPP