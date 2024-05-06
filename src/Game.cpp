#include "Game.hpp"

#include <time.h>
#include <stdlib.h>
#include <unistd.h>


Game::Game(const Ihm& ihm)
{
	this->ihm = ihm;
	grid.RandomGrid(this->ihm.GetCol(), this->ihm.GetRow());
}

Game::~Game()
{

}

bool Game::Process()
{
	bool next = false;
	if (ihm.GetStep()) {
		if (ihm.GetNextStep()) {
			ihm.SetNextStep(false);
			next = true;
		}
	} else {
		auto now = std::chrono::system_clock::now();
		if ((now - last_process_next).count() > ihm.GetSleep() * 1000) {
			next = true;
		}
	}
	
	if (next) {
		grid.NextGen();
	}
	
	ihm.DrawGrid(grid);
	ihm.ProcessInputKey();
	return ihm.GetRun();
}