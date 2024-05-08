#ifndef IHM_HPP
#define IHM_HPP

#ifdef _WIN32
#include <ncurses/ncurses.h>
#endif // windows

#ifdef linux
#include <ncurses.h>
#endif // linux

#include <vector>

#include "Grid.hpp"

class Ihm {

public:
	Ihm();
	~Ihm();
	
	void DrawGrid(Grid &grid);
	void DrawGridCamera(Grid &grid);
	void ProcessInputKey();
	
	int GetRow();
	int GetCol();
	bool GetRun();
	unsigned int GetSleep();
	bool GetStep();
	bool GetNextStep();
	void SetNextStep(bool n);
	
	void MoveUp(int n);
	void MoveDown(int n);
	void MoveLeft(int n);
	void MoveRight(int n);
	
private:
	int row;
	int col;
	double speed;
	bool run;
	bool step;
	bool nextStep;
	int cameraX, cameraY;

};

#endif // IHM_HPP