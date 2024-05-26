#include "Game.hpp"
#include "GridHash.hpp"
#include "GridArray.hpp"
#include "InputOutput.hpp"

#include <time.h>
#include <stdlib.h>
#include <unistd.h>


Game::Game(Ihm *ihm)
{
	this->ihm = ihm;
	grid = new GridArray;
	grid->RandomGrid(480, 360);
	// grid->Clear();
	tick = 0;
	bai = 0;
	isBadApple = 0;
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
		unsigned int newDelta = (now - last_process_next).count();
		if (newDelta > ihm->GetSleep() * 1000) {
			next = true;
			last_process_next = now;
			delta = newDelta;
		}
	}
	
	if (next) {
		if (isBadApple) {
			BadApple();
		}
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

unsigned int Game::GetDelta()
{
	return delta;
}

void Game::SaveGrid()
{
	auto cells = grid->GetAlivesCells();
	InputOutput::SaveAlivesCells(cells);
}

void Game::LoadGrid()
{
	std::vector<Cell> cells = InputOutput::ReadCells();
	for (unsigned int i = 0; i < cells.size(); i++) {
		Cell c = cells[i];
		Pos p = c.GetPos();
		grid->SetAt(p.GetX(), p.GetY(), 1);
	}
}

void Game::SetBadApple()
{
	isBadApple = true;
}

void Game::BadApple()
{
	std::vector<Cell> cells = InputOutput::ReadCells(bai++);
	for (unsigned int i = 0; i < cells.size(); i++) {
		Cell c = cells[i];
		Pos p = c.GetPos();
		grid->SetAt(p.GetX(), p.GetY(), 1);
	}
}

void Game::ClearGrid()
{
	grid->Clear();
}