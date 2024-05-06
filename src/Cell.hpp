#ifndef CELL_HPP
#define CELL_HPP

#include "Pos.hpp"

class Cell {
public:
	Cell(int x, int y);
	bool operator==(const Cell &other) const;
	
	const Pos GetPos() const;

private:

	Pos pos;
};

#endif // CELL_HPP