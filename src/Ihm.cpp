#include "Ihm.hpp"

#define SLEEP_REF 100'000
#define CTRL_KEY_RIGHT 561
#define CTRL_KEY_LEFT 546
#define CTRL_KEY_UP 567
#define CTRL_KEY_DOWN 526

Ihm::Ihm()
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	nonl();
	cbreak();
	getmaxyx(stdscr,row,col);
	
	run = true;
	step = false;
	nextStep = false;
	speed = 1;
	cameraX = 0;
	cameraY = 0;
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

void Ihm::DrawGrid(Grid &grid)
{
	for (int i = 0; i < row; i++) {
		move(i, 0);
		clrtoeol(); 
	}
	std::vector<Cell> cells = grid.GetAlivesCells();
	for (unsigned int i = 0; i < cells.size(); i++) {
		Cell c = cells[i];
		Pos p = c.GetPos();
		mvaddch(p.GetY() + cameraY, p.GetX() - cameraX, '#');
	}
	
	move(0, 0);
	print_info("F1", "Quit");
	print_info("S", "Speed Up");
	print_info("D", "Speed Down");
	print_info("SPACE", "Step by Step");
	print_info("N", "Next Step");
	move(row + 1, 0);
	printw("tick: %d, cells %ld, speed: %.1fx sleep: %d",
		game->GetTick(),
		grid.GetAlivesCells().size(),
		speed,
		GetSleep()
	);
	
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
		speed += 0.1;
		break;
	case 'd':
		if (speed > 0.2) {
			speed -= 0.1;
		}
		break;
	case ' ':
		step = !step;
		break;
	case 'n':
		nextStep = true;
		break;
	case KEY_LEFT:
		MoveLeft(1);
		break;
	case CTRL_KEY_LEFT:
		MoveLeft(10);
		break;

	case KEY_UP:
		MoveUp(1);
		break;
	case CTRL_KEY_UP:
		MoveUp(10);
		break;

	case KEY_DOWN:
		MoveDown(1);
		break;
	case CTRL_KEY_DOWN:
		MoveDown(10);
		break;

	case KEY_RIGHT:
		MoveRight(1);
		break;
	case CTRL_KEY_RIGHT:
		MoveRight(10);
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
	return SLEEP_REF / speed;
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

void Ihm::MoveUp(int n)
{
	cameraY += n;
}

void Ihm::MoveDown(int n)
{
	cameraY -= n;
}

void Ihm::MoveLeft(int n)
{
	cameraX -= n;
}

void Ihm::MoveRight(int n)
{
	cameraX += n;
}

void Ihm::SetGame(Game *game)
{
	this->game = game;
}