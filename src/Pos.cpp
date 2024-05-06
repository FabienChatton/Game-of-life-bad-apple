#include "Pos.hpp"

Pos::Pos(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Pos::GetX() const
{
	return x;
}

int Pos::GetY() const
{
	return y;
}

bool Pos::operator==(const Pos &other) const
{
	return x == other.x && y == other.y;
}