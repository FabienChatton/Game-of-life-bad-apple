#ifndef GAME_HPP
#define GAME_HPP

#include "Ihm.hpp"

#include <vector>
#include <chrono>
#include <ctime>

class Game {

public:
	Game(const Ihm &ihm);
	~Game();
	void InitScreenSize();
	bool Process();

private:
	Ihm ihm;
	int row;
	int col;
	std::vector<std::vector<char>> grid;
	
	int GetNeighbor(int i, int j);
	void NextGen();
	std::chrono::time_point<std::chrono::system_clock> last_process_next;

};

#endif // GAME_HPP