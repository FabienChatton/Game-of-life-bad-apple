#ifndef GAME_HPP
#define GAME_HPP

#include "Ihm.hpp"
#include "Grid.hpp"

#include <vector>
#include <chrono>
#include <ctime>


class Ihm;

class Game {

public:
	Game(Ihm *ihm);
	~Game();
	bool Process();
	unsigned int GetTick();
	unsigned int GetDelta();
	void SaveGrid();
	void LoadGrid();
	void SetBadApple();
	void ClearGrid();
	
private:
	void BadApple();
	Ihm *ihm;
	Grid *grid;

	std::chrono::time_point<std::chrono::system_clock> last_process_next;
	unsigned int tick;
	unsigned int delta;
	unsigned int bai;
	bool isBadApple;
};

#endif // GAME_HPP