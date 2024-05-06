#include "Cell.hpp"

Cell::Cell(int x, int y): pos(x, y)
{
	
}


bool Cell::operator==(const Cell &other) const
{
	return GetPos() == other.GetPos();
}

const Pos Cell::GetPos() const
{
	return pos;
}