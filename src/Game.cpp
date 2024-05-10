#include "Game.hpp"
#include "GridHash.hpp"
#include "GridArray.hpp"

#include <time.h>
#include <stdlib.h>
#include <unistd.h>


Game::Game(Ihm *ihm)
{
	this->ihm = ihm;
	grid = new GridArray;
	grid->RandomGrid(this->ihm->GetCol(), this->ihm->GetRow());
	tick = 0;
}

Game::~Game()
{
	delete grid;
}

bool Game::Process()
{
	bool next = false;
	if (ihm->GetStep()) {
		if (ihm->GetNextStep()) {
			ihm->SetNextStep(false);
			next = true;
		}
	} else {
		auto now = std::chrono::system_clock::now();
		if ((now - last_process_next).count() > ihm->GetSleep() * 1000) {
			next = true;
			last_process_next = now;
		}
	}
	
	if (next) {
		grid->NextGen();
		++tick;
	}
	
	ihm->DrawGrid(*grid);
	ihm->ProcessInputKey();
	return ihm->GetRun();
}

unsigned int Game::GetTick()
{
	return tick;
}