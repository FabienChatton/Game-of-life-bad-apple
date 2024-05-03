#include "Ihm.hpp"

Ihm::Ihm()
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr,row,col);
	
	sleep = 100'000;
	run = true;
	step = false;
	nextStep = false;
}

Ihm::~Ihm()
{
	endwin();
}

void print_info(const char *key, const char *info)
{
	attron(A_STANDOUT);
	printw("%s", key);
	attroff(A_STANDOUT);
	printw(" ");
	printw("%s", info);
	printw("\t\t");
}

void Ihm::DrawGrid(std::vector<std::vector<char>> &grid, int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			char datum = grid[i][j];
			mvaddch(i, j, datum == 0 ? ' ' : '#');
		}
	}
	
	move(row, 0);
	print_info("F1", "Quit");
	print_info("S", "Speed Up");
	print_info("D", "Speed Down");
	print_info("SPACE", "Step by Step");
	print_info("N", "Next Step");
	move(row + 1, 0);
	printw("Sleep time: %d s", sleep / 1'000'000);
	refresh();
}

void Ihm::ProcessInputKey()
{
	timeout(0);
	int ch = getch();
	
	if (ch == KEY_F(1)) {
		run = false;
	}
	switch(ch) {
	case 's':
		if (sleep > 0) {
			sleep -= 10'000;
		}
		break;
	case 'd':
		sleep += 10'000;
		break;
	case ' ':
		step = !step;
		break;
	case 'n':
		nextStep = true;
		break;
	}
}

int Ihm::GetRow()
{
	return row;
}

int Ihm::GetCol()
{
	return col;
}

bool Ihm::GetRun()
{
	return run;
}

unsigned int Ihm::GetSleep()
{
	return sleep;
}

bool Ihm::GetStep()
{
	return step;
}

bool Ihm::GetNextStep()
{
	return nextStep;
}

void Ihm::SetNextStep(bool n)
{
	nextStep = n;
}