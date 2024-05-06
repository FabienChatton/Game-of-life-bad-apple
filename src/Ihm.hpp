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
	void ProcessInputKey();
	
	int GetRow();
	int GetCol();
	bool GetRun();
	unsigned int GetSleep();
	bool GetStep();
	bool GetNextStep();
	void SetNextStep(bool n);
	
private:
	int row;
	int col;
	double speed;
	bool run;
	bool step;
	bool nextStep;
	
};

#endif // IHM_HPP