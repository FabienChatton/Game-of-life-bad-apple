#include "Game.hpp"

#include <time.h>
#include <stdlib.h>
#include <unistd.h>


Game::Game(const Ihm& ihm)
{
	this->ihm = ihm;
	row = this->ihm.GetRow() - 2;
	col = this->ihm.GetCol();
}

Game::~Game()
{

}

void Game::InitScreenSize()
{
	srand(time(0));
	grid = std::vector<std::vector<char>>(row);
	
	for (int i = 0; i < row; i++) {
		grid[i] = std::vector<char>(col);
		for (int j = 0; j < col; j++) {
			grid[i][j] = rand() % 2;
		}
	}
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
		NextGen();
	}
	
	ihm.DrawGrid(grid, row, col);
	ihm.ProcessInputKey();
	return ihm.GetRun();
}

int Game::GetNeighbor(int i, int j)
{
	int neigbors = 0;
	for (int k = -1; k < 2; k++) {
		for (int h = -1; h < 2; h++) {
			if (k == 0 && h == 0) continue;
			
			int x = (k + i + row) % row;
			int y = (h + j + col) % col;
			
			neigbors += (int)grid[x][y];
		}
	}
	return neigbors;
}

void Game::NextGen()
{
	std::vector tmp = std::vector<std::vector<char>>(row);
	
	for (int i = 0; i < row; i++) {
		tmp[i] = std::vector<char>(col);
		for (int j = 0; j < col; j++) {
			char datum = grid[i][j];
			int neighbor = GetNeighbor(i, j);
			
			if (datum == 1 && (neighbor == 2 || neighbor == 3)) {
				tmp[i][j] = 1;
			} else if (datum == 0 && neighbor == 3) {
				tmp[i][j] = 1;
			} else {
				tmp[i][j] = 0;
			}
		}
	}
	
	last_process_next = std::chrono::system_clock::now();
	grid = tmp;
}