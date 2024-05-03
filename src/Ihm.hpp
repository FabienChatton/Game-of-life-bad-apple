#ifndef IHM_HPP
#define IHM_HPP

#ifdef _WIN32
#include <ncurses/ncurses.h>
#endif // windows

#ifdef linux
#include <ncurses.h>
#endif // linux

#include <vector>

class Ihm {

public:
	Ihm();
	~Ihm();
	
	void DrawGrid(std::vector<std::vector<char>> &grid, int row, int col);
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
	unsigned int sleep;
	bool run;
	bool step;
	bool nextStep;
	
};

#endif // IHM_HPP